# Fetch data from key's value

ans = 'Yash'

lst = {
  # Name: Relationship 
    'Nitin': 'self',
    'Yash': 'bff',
    'Anji': 'close frnd',
    'Somi': 'sister',
    'Zeba': 'sister from other mother',
    'Sanju': 'mother',
    'Shiv': 'friend'
    }

if ans in lst:
    # print(lst[ans])
    print("Relationship of {} with me is of {}".format(ans, lst[ans]))
    
    