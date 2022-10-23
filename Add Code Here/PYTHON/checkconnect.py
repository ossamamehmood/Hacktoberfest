import mysql.connector as msql
#from mysql import connector as msql
mcon=msql.connect(host="localhost",user="root",database="outfits")
if mcon.is_connected():
    print("Successfully connected")


