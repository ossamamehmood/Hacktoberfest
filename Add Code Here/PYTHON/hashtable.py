
# In computing, a hash table (hash map) is a data structure which implements an associative array abstract
# data type, a structure that can map keys to values. A hash table uses a hash function to compute an index
# into an array of buckets or slots, from which the desired value can be found.

# Python's built-in data type dictionary uses hash tables to retrieve key value pairs.

class HashMap(object):
    def __init__(self):
        self.hash_map = [[(None, None)] for _ in range(10)]

    def insert(self, key, value):
        hash_key = hash(key) % len(self.hash_map)
        key_exists = 0
        hash_list = self.hash_map[hash_key]
        # print(key, value)
        for i, key_value_pair in enumerate(hash_list):
            key_in_table, value_in_table = key_value_pair
            if key == key_in_table or key_in_table == None:
                key_exists = 1
            if key_exists:
                hash_list[i] = ((key, value))
            else:
                hash_list.append((key, value))

    def get(self, key):
        hash_key = hash(key) % len(self.hash_map)
        hash_list = self.hash_map[hash_key]
        for i, key_value in enumerate(hash_list):
            key_in_table, value_in_table = key_value
            return value_in_table
        raise KeyError

if __name__ == '__main__':
    myDict = HashMap()
    myDict.insert('Omkar', 'Pathak')
    myDict.insert('Jagdish', 'Pathak')
    value = myDict.get('Omkar')
    print(value)
