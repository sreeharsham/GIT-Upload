class Stack():
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def print_stack(self):
        return self.items

    def is_empty(self):
        return self.items == []

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            return "Stack is empty!"


# s = Stack()
# s.push(1)
# s.push(2)
# print(s.print_stack())
# s.pop()
# s.pop()
# # print(s.peek())