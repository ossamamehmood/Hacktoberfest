import cryptocompare
import tweepy
from time import sleep 

#Apis
CRYPTOCOMPARE_API_KEY = 'https://min-api.cryptocompare.com/ get your api from here xxxxxxxxxx'
#twitter - https://developer.twitter.com/en/portal/dashboard apply for twitter api here......
consumer_key = 'xxxxxxxxxx'
consumer_secret = 'xxxxxxxxxx'
access_token = 'xxxxxxxxxx'
access_token_secret = 'xxxxxxxxxx'

#Calling twitter api
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)

n=0
while n<100000000000000000000000000000000:
    try:

        a = cryptocompare.get_avg('BTC', currency='USDC' , exchange='Binance')
        b = a.get('PRICE')
        c = a.get('CHANGEPCT24HOUR')
        d = "{:.0f}".format(b)
        e = "{:.1f}".format(c)


        a1 = cryptocompare.get_avg('ETH', currency='USDT' , exchange='Binance')
        b1 = a1.get('PRICE')
        c1 = a1.get('CHANGEPCT24HOUR')
        d1 = "{:.0f}".format(b1)
        e1 = "{:.1f}".format(c1)


        a2 = cryptocompare.get_avg('DOGE', currency='USDT' , exchange='Binance')
        b2 = a2.get('PRICE')
        c2 = a2.get('CHANGEPCT24HOUR')
        d2 = "{:.3f}".format(b2)
        e2 = "{:.1f}".format(c2)

        a3 = cryptocompare.get_avg('LTC', currency='USDT' , exchange='Binance')
        b3 = a3.get('PRICE')
        c3 = a3.get('CHANGEPCT24HOUR')
        d3 = "{:.0f}".format(b3)
        e3 = "{:.1f}".format(c3)

        a4 = cryptocompare.get_avg('SHIB', currency='USDT' , exchange='Binance')
        b4 = a4.get('PRICE')
        c4 = a4.get('CHANGEPCT24HOUR')
        d4 = "{:.6f}".format(b4)
        e4 = "{:.1f}".format(c4)

        a5 = cryptocompare.get_avg('BNB', currency='USDT' , exchange='Binance')
        b5 = a5.get('PRICE')
        c5 = a5.get('CHANGEPCT24HOUR')
        d5 = "{:.0f}".format(b5)
        e5 = "{:.1f}".format(c5)

        cr = '#Crypto'
        nll = '\n'
        m = '\n''#BTC- ' + (d) + '$'+ '     24H CHANGE-> ' + (e) + '%'
        nn = '\n''#ETH- ' + (d1) + '$'+ '             24H CHANGE-> ' + (e1) + '%'
        o = '\n''#DOGE- ' + (d2) + '$'+ '         24H CHANGE-> ' + (e2) + '%'
        p = '\n' '#LTC- ' + (d3) + '$'+ '                 24H CHANGE-> ' + (e3) + '%'
        q = '\n' '#SHIB- ' + (d4) + '$'+ '  24H CHANGE-> ' + (e4) + '%'
        r = '\n' '#BNB- ' + (d5) + '$'+ '         24H CHANGE-> ' + (e5) + '%'
        messaa = '\n' '\n' 'Automated tweet. Every hour.'

        n = n+1

        print (m , nn , o ,p , q ,r)
        print ('No. of times price tweeted- ' , n)

        tweet = api.update_status(cr + m + nn + r +p +  o + q  + messaa)

        sleep(3600) #time in secs.
    except n==10000000000000000000000:
        break
    except StopIteration:
        break
