# Import necessary libraries
from gensim.models import Word2Vec
from gensim.models import KeyedVectors
from sklearn.feature_extraction.text import CountVectorizer

# Define the list of sentences
sentences = [
    "Data science involves using statistical and computational techniques to extract insights from data.",
    "In data science, machine learning algorithms are used to build predictive models based on data.",
    "Big data technologies enable data scientists to process and analyze large volumes of data more efficiently.",
    "Data visualization is an important part of data science, as it helps to communicate insights effectively.",
    "Natural language processing is a key area of data science that focuses on understanding and processing human language."
]

# Perform vectorization using Bag-of-Words model
vectorizer = CountVectorizer()
bow_matrix = vectorizer.fit_transform(sentences)
print(bow_matrix.toarray())

# Perform vectorization using Word2Vec model
w2v_model = Word2Vec(sentences, min_count=1)
word_vector = w2v_model.wv["data"]
print(word_vector)
