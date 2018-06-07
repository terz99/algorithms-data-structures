from hashtable import *

if __name__ == "__main__":
    table = HashTable()
    while True:
        query = input().split()
        if query[0] == 'i':
            key = int(query[1])
            val = int(query[2])
            h = table.insertNode(key, val)
            print(h)
        elif query[0] == 'g':
            key = int(query[1])
            res = table.get(key)
            print(res)
        elif query[0] == 'q':
            break
