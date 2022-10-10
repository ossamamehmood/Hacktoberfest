import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Activation, Dense, Flatten, BatchNormalization, Conv2D, MaxPool2D
from tensorflow.keras.metrics import categorical_crossentropy
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.optimizers import Adam
from sklearn.metrics import confusion_matrix
import itertools
import os
import random
import glob
import shutil
import matplotlib.pyplot as plt
import warnings 

warnings.simplefilter(action='ignore', category=FutureWarning)

loc = r'C:\Users\suyash\Desktop\cats vs dogs\train'
os.chdir(loc)

if os.path.isdir('train/dog') is False:
    os.makedirs('train/dog')
    os.makedirs('train/cat')
    os.makedirs('valid/dog')
    os.makedirs('valid/cat')
    os.makedirs('test/dog')
    os.makedirs('test/cat')

    for c in random.sample(glob.glob('cat*'),500):
        shutil.move(c, 'train/cat')
    for c in random.sample(glob.glob('dog*'),500):
        shutil.move(c, 'train/dog')
    for c in random.sample(glob.glob('cat*'),100):
        shutil.move(c, 'valid/cat')
    for c in random.sample(glob.glob('dog*'),100):
        shutil.move(c, 'valid/dog')
    for c in random.sample(glob.glob('cat*'),50):
        shutil.move(c, 'test/cat')
    for c in random.sample(glob.glob('dog*'),50):
        shutil.move(c, 'test/dog')

train = r'C:\Users\suyash\Desktop\cats vs dogs\train\train'
valid = r'C:\Users\suyash\Desktop\cats vs dogs\train\valid'
test  = r'C:\Users\suyash\Desktop\cats vs dogs\train\test'

trainBatch = ImageDataGenerator(preprocessing_function=tf.keras.applications.vgg16.preprocess_input)\
            .flow_from_directory(directory=train, target_size=(224,224), classes=['cat', 'dog'],batch_size=10)
validBatch = ImageDataGenerator(preprocessing_function=tf.keras.applications.vgg16.preprocess_input)\
            .flow_from_directory(directory=valid, target_size=(224,224), classes=['cat', 'dog'],batch_size=10)
testBatch  = ImageDataGenerator(preprocessing_function=tf.keras.applications.vgg16.preprocess_input)\
            .flow_from_directory(directory=test, target_size=(224,224), classes=['cat', 'dog'],batch_size=10)

assert trainBatch.n == 1000
assert validBatch.n == 200
assert testBatch.n == 100
assert trainBatch.num_classes == validBatch.num_classes == testBatch.num_classes == 2

imgs, labels = next(trainBatch)

def plotImage(image_arr):
    fig, axes = plt.subplots(1,10,figsize=(20,20))
    axes = axes.flatten()
    for img,ax in zip(image_arr, axes):
        ax.imshow(img)
        ax.axis('off')

    plt.tight_layout()
    plt.show()

plotImage(imgs)
print(labels)

model = Sequential([
    Conv2D(filters=32, kernel_size=(3,3), activation='relu', padding='same',input_shape=(224,224,3)),
    MaxPool2D(pool_size=(2,2), strides=2),
    Conv2D(filters=64, kernel_size=(3,3), activation='relu',padding='same'),
    MaxPool2D(pool_size=(2,2), strides=2),
    Flatten(),
    Dense(units=2, activation='softmax'),
])

model.summary()

model.compile(optimizer=Adam(learning_rate=0.0001), loss='categorical_crossentropy', metrics=['accuracy'])

# With the help of the generator we have made the batches and the generated data is their with their y cordinates
model.fit(x=trainBatch, validation_data=validBatch, epochs=10, verbose=2)

# using the next function to get the batch of the training 
timgs, tlabels = next(testBatch)
plotImage(timgs)
print(tlabels,testBatch.classes)

# Finding the model performance and rounding it of to the closest value
predict = model.predict(x=testBatch, verbose=0)
np.round(predict)

# Calculating the confusion matrix
cm = confusion_matrix(y_true=testBatch.classes, y_pred= np.argmax(predict, axis=-1))

def plot_confusion_matrix(cm, classes,
                          normalize=False,
                          title='Confusion matrix',
                          cmap=plt.cm.Blues):
    """
    This function prints and plots the confusion matrix.
    Normalization can be applied by setting `normalize=True`.
    """
    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
        print("Normalized confusion matrix")
    else:
        print('Confusion matrix, without normalization')

    print(cm)

    thresh = cm.max() / 2.
    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
        plt.text(j, i, cm[i, j],
                 horizontalalignment="center",
                 color="white" if cm[i, j] > thresh else "black")

    plt.tight_layout()
    plt.ylabel('True label')
    plt.xlabel('Predicted label')
    plt.show()
