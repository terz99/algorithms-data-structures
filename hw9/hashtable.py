class Node:

    """ Represents a Node of a HashTable """

    def __init__(self, key=None, value=None):
        """
        Constructor
        type key: int (default: None)
        type value: int (default: None)
        """
        self.key = key
        self.value = value

MOD = 1000003

class HashTable:

    """ Represents a HashTable """

    def __init__(self, maxSize=MOD):
        """
        Constructor
        type maxSize: int (default: MOD=1000003)
        """
        self.maxSize = maxSize
        self.currSize = 0
        self.arr = [None]*maxSize

    def hashCode(self, key):
        """
        Hashcode function for getting the index of the element in the table.
        multiplies each digit from the key, starting from the least significant digit,
        by 31 and adds 13. Takes the mod of member variable maxSize.
        type key: int
        rtype: int
        """
        ret = 0
        while key > 0:
            ret = (ret*31 + key%10 + 13)%self.maxSize
            key //= 10
        return ret

    def insertNode(self, key, value):

        """
        Inserts a new key-value pair Node into the hash table. First 
        it gets the hash from the key and then maps it to that position in 
        the table. If that position is already taken, it finds the next available
        position in the table.
        type key: int
        type value: int
        rtype: int (returns the index from the hash function)
        """

        if self.currSize == self.maxSize:
            return -1
        idx = self.hashCode(key)
        start = -1
        while self.arr[idx] != None and self.arr[idx].key != key and idx != start:
            if start == -1:
                start = idx
            idx += 1
            idx %= self.maxSize
        if idx == start:
            return -1
        if self.arr[idx] == None:
            self.currSize += 1
        self.arr[idx] = Node(key, value)
        return idx

    def get(self, key):
        """
        Gets the value of the key given. If the key does not exist in the table
        it returns -1
        type key: int
        rtype: int
        """
        idx = self.hashCode(key)
        start = -1
        while self.arr[idx] != None and self.arr[idx].key != key and start != idx:
            if start == -1:
                start = idx
            idx = (idx+1)%self.maxSize
        if self.arr[idx] == None or idx == start:
            return -1
        return self.arr[idx].value

    def isEmpty(self):
        """
        rtype: True if empty, False otherwise
        """
        return self.currSize == 0