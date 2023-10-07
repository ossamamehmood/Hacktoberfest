import requests

def get_crypto_rates(cryptos):
    url = "https://api.coingecko.com/api/v3/simple/price"
    query_params = {
        'ids': ','.join(cryptos),
        'vs_currencies': 'usd'
    }
    
    response = requests.get(url, params=query_params)
    data = response.json()

    for crypto in cryptos:
        if crypto in data:
            print(f"{crypto}: ${data[crypto]['usd']}")
        else:
            print(f"Couldn't fetch data for {crypto}")

if __name__ == "__main__":
    cryptos = ['bitcoin', 'ethereum', 'litecoin']  # You can add more cryptos to this list
    get_crypto_rates(cryptos)
