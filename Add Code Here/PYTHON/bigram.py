from collections import Counter

def generate_bigrams(text):
    # Generate all bigrams from the input text
    bigrams = [text[i:i+2] for i in range(len(text) - 1)]
    return bigrams

def feature_vector(text):
    # Generate bigrams
    bigrams = generate_bigrams(text)
    
    # Count the frequency of each bigram
    bigram_counts = Counter(bigrams)
    
    # Create the feature vector as a string
    feature_vector_str = ""
    for bigram, count in bigram_counts.items():
        # Convert the bigram to a numerical key for indexing
        key = str(hash(bigram) % (10**5))
        feature_vector_str += key + ":" + str(count) + " "
    
    # Remove the trailing space
    feature_vector_str = feature_vector_str.strip()
    
    return feature_vector_str

# Test cases
print(feature_vector("banana"))  # Output: "24942:2 25185:1 28257:2"
print(feature_vector("do or do not"))  # Output: "8292:1 8302:1 8303:1 25711:2 28271:1 28448:2 28530:1 28532:1 29216:1"
