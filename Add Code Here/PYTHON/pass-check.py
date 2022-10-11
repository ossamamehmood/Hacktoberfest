import uuid
import hashlib

def hash_password(password):
   # uuid is used to generate a random number of the specified password
   salt = uuid.uuid4().hex
   return hashlib.sha256(salt.encode() + password.encode()).hexdigest() + ':' + salt

def check_password(hashed_password, user_password):
   password, salt = hashed_password.split(':')
   return password == hashlib.sha256(salt.encode() + user_password.encode()).hexdigest()

new_pass = input('Please enter a password: ')
hashed_password = hash_password(new_pass)
print('The string to store in the db is: ' + hashed_password)
old_pass = input('Now please enter the password again to check: ')

if check_password(hashed_password, old_pass):
   print('You entered the right password')
else:
   print('Passwords do not match')
