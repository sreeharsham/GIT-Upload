class Node():
    def __init__(self, val):
        self.value = val
        self.next = None

# firstNode = Node(10)
# secondNode = Node(20)
# print(firstNode.value)
# print(secondNode.value)


class LinkedList():
    def __init__(self):
        self.head = None

    def list_empty(self):
        return self.head is None

    def add_item_at_begin(self, item):
        new_node = Node(item)   # ADD NODE
        new_node.next = self.head # CONNECT new_node TO OLD LIST
        self.head = new_node # HEAD IS NOW ON THE NEW NODE

    def list_size(self):
        count = 0
        current = self.head
        while current is not None:
            count += 1
            current = current.next
        return count

    def search(self, item):
        current = self.head
        while current is not None:
            if current.value == item:
                return True
            current = current.next
        return False

    def remove(self, item):
        current = self.head
        previous = None
        while True:
            if current.value == item:
                break
            previous = current
            current = current.next

        if previous is None:
            self.head = current.next
        else:
            previous.next = current.next

    def print(self):
        current = self.head
        while current is not None:
            print(current.value)
            current = current.next


ll = LinkedList()
print(ll.list_empty())
ll.add_item_at_begin(10)
ll.add_item_at_begin(20)
ll.add_item_at_begin(30)
print(ll.list_size())
print(ll.print())