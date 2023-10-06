import requests
import json

def movie_list(title):
    list = []
    for i in range(1, 101):
        try:
            print('Pesquisando em pagina:', i)
            url = 'http://www.omdbapi.com/?apikey=yourKey' + title + '&type=movie&page=' + str(i)
            req = requests.get(url)
            response = json.loads(req.text)
            if response['Response'] == 'True':
                for movie in response['Search']:
                    tit = movie['Title']
                    year = movie['Year']
                    string = tit + ' (' + year + ')'
                    list.append(string)
            else:
                print('End of pages')
                break
        except:
            print('ERROR')
    return list

exi = False
while not exi:
    op = input('Type a movie name or EXIT to close: ')
    if op == "EXIT":
        exi = True
    else:
        mlist = movie_list(op)
        print('Filmes encontrados:', len(mlist))
        for movie in mlist:
            print(movie)
