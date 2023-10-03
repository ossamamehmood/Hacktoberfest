import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

# Load the stock price data from a CSV file
data = pd.read_csv('') # Enter a CSV file here

# Encode the 'Date' column as numerical values
data['Date'] = pd.to_datetime(data['Date'])
data['Date'] = (data['Date'] - data['Date'].min()).dt.days

# Extract the features (X) and target variable (y)
X = data['Date'].values.reshape(-1, 1)   # Date as the feature
y = data['Price'].values

# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a linear regression model and fit it on the training data
model = LinearRegression()
model.fit(X_train, y_train)

# Make predictions on the test data
y_prediction = model.predict(X_test)

# Plot the actual prices and predicted prices
plt.scatter(X_test, y_test, color='blue', label='Actual Price')
plt.plot(X_test, y_prediction, color='red', label='Predicted Price')
plt.xlabel('Date')
plt.ylabel('Price')
plt.title('Stock Price Prediction')
plt.legend()
plt.show()
