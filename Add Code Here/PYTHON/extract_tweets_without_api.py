from tweetlib import tweetlib
 
# Get tweets by username
tw = tweetlib.TweetLib(username="username2343", max_tweets=10)
tweets = tw.get_tweets()
 
print(tweets)
# Get tweets by search 
tweets = tweetlib.TweetLib(query_search="Programming", since="2021-10-22")
print(tweets)
