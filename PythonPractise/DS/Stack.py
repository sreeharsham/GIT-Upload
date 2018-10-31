a = [1,2,3,4]
#print(a[-1])


class Stack:

# is_empty, push, pop, peek, size


    def __init__(self):
        self.items = []


    def is_empty(self):
        return self.items == []


    def push(self, item):
        self.items.append(item)
        # self.items.insert(0, item) ; for beginning of list

    def pop(self):
        return self.items.pop()
        # self.items.pop(0); for beginning of list
    
    def peek(self):
        return self.items[-1]
        # self.items[0]; for beginning of list


    def size(self):
        return len(self.items)


s = Stack()
'''
s = Stack()
s.push(1)
s.push('cat')
print(s.peek())
s.push(True)
print(s.size())
print(s.is_empty())
s.push(8.4)
print(s.pop())
print(s.pop())
print(s.size())

'''
    



