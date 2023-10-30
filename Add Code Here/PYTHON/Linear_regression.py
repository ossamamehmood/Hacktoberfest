import pandas as pd
import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

# Load the Iris dataset
iris = datasets.load_iris()
data = pd.DataFrame(data=np.c_[iris['data'], iris['target']], columns=iris['feature_names'] + ['target'])

# Select a continuous feature as the target variable (e.g., sepal length)
X = data[['sepal width (cm)', 'petal length (cm)', 'petal width (cm)']]  # Use these as predictor variables
y = data['sepal length (cm)']  # Sepal length as the target variable

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create and fit the linear regression model
model = LinearRegression()
model.fit(X_train, y_train)

# Make predictions on the test set
y_pred = model.predict(X_test)

# Print the coefficients and intercept of the model
print("Coefficients:", model.coef_)
print("Intercept:", model.intercept_)

# Visualize the results
plt.scatter(X_test['petal length (cm)'], y_test, color='blue', label='Actual')
plt.plot(X_test['petal length (cm)'], y_pred, color='red', linewidth=2, label='Predicted')
plt.xlabel('Petal Length (cm)')
plt.ylabel('Sepal Length (cm)')
plt.legend()
plt.show()
