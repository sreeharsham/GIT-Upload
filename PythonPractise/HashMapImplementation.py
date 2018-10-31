print(dir(dict))


print(hash('A') % 5)

dic = {10:'A', 20:'B', 10:'c'}
print(dic)



class Node:
    def __init(self, key, val):
        self.key = key
        self.value = val
        self.next = None

        
        
class HashMap:
    def __init__(self):
        self.hm_arr = [None] * 5
        self.head = None
    
    
    def insert(self, key, val):
        index = hash(key) % 5
        n = new Node()

        if not self.hm_arr[index]:
            hm_arr[index] = n
            self.head = n
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = n




        
        
        
        
hash_map = HashMap()
hash_map.insert(10, 'A')
hash_map.insert(20, 'B')
hash_map.insert(30, 'C')
