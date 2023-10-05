import requests

def fetch_random_quote():
    # Define the base URL for the Quotable API
    base_url = "https://api.quotable.io"

    # Define the endpoint for fetching a random quote
    endpoint = "/quotes/random"

    # Construct the full API URL
    api_url = f"{base_url}{endpoint}"

    try:
        # Make a GET request to the API
        response = requests.get(api_url)

        # Check if the request was successful (status code 200)
        if response.status_code == 200:
            # Parse the JSON response to get the quote and author
            data = response.json()
            quote = data[0].get("content")
            author = data[0].get("author")
            print(f"Random Quote: '{quote}'\nAuthor: {author}")
        else:
            print(f"Error: Unable to fetch a random quote (Status Code: {response.status_code})")

    except Exception as e:
        print(f"An error occurred: {str(e)}")
        
def main():
    print('Fetching a fresh quote, just for you.')
    fetch_random_quote()
    print()
    print('Happy HacktoberFest!')

if __name__ == "__main__":
    main()
    
