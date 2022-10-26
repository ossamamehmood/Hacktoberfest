#-*- coding: utf-8 -*-
import requests,sys
if sys.platform in ['linux','linux2']:
   _r = '\033[91m'
   _g = '\033[92m'
   _b = '\033[94m'
   _w = '\033[0m'
else:
   _r = ''
   _g = ''
   _b = ''
   _w = ''

class github_traffic(object):


      def __init__(
        self,
        username,
        password,
        repo_name
      ):
         self.username = username
         self.__password = password
         self.repo_name = repo_name

      @property
      def __auth(self):
          return f'https://api.github.com/repos/{self.username}/{self.repo_name}/traffic/clones'

      def request(self):
          try:
              r = requests.get(
                  self.__auth,
                  auth = (
                  self.username,
                  self.__password
                )
              )
              data = r.json()
              if 'message' in data and data['message'] ==  'Not Found':print(f'\n{_r}[-]{_w}No repo Found with name {self.repo_name}\n')
              elif 'message' in data and data['message'] == 'Bad credentials':print('\n{_r}[x]{_w} Invalid Username or Password\n')
              else:
                   print(f'\n{_g}[+]{_w} Total Count Clones  {data["count"]}\n{_g}[+]{_w} Total Count Uniques Clone {data["uniques"]}\n')
                   print(f'{_b}[+]{_w} Data')
                   for x in data['clones']:
                       print(f'- Timestamp :  {x["timestamp"]} - Clones : {x["count"]} - Uniques : {x["uniques"]}')
          except requests.exceptions.ConnectionError:
              print('\n[x] No Internet Connection\n')
              exit()





if sys.version[0] in '2':
   print(f'\n{_r}Not Supported For python 2 {_w}\n')


if len(sys.argv) < 2:
   print(f'''
python {sys.argv[0]} <username> <password> <reponame>
Example : python {sys.argv[0]} myusername mypassword mynamerepo
          ''')
else:
   print(f"""
        {_b} [ GITHUB TRAFFIC USER INFORMATION ]{_w}
         [ Codename ] : JaxBCD
         [ By ] : 407 Authentic Exploit

   """)
   github_traffic(
    sys.argv[1],
    sys.argv[2],
    sys.argv[3]
   ).request()
