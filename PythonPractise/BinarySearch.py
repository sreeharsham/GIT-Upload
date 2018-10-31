def binarySearch(myItem, myList):
    found = False
    first = 0
    last = len(myList)
    counter = 0
    # current = (first + last) / 2
    # middle = 0
    while not found:
        middle = (first + last) // 2
        if myList[middle] == myItem:
            found = True
            return found, counter + 1
            # return True
        else:
            if first >= last:
                found = False
                return found, counter + 1
            else:
                if myList[middle] > myItem:
                    last = middle - 1
                    counter = counter + 1
                else:
                    first = middle + 1
                    counter = counter + 1
    return found, counter

if __name__  == '__main__':
    numList = [1, 4, 6, 8, 12, 15, 18, 19, 24, 27, 31, 42, 43, 58]
    item = int(input("Enter number to be searched:"))
    counter = 0
    isFound, counter = binarySearch(item, numList)
    if isFound:
        print("Number found")
        print("Searched for %s times" % str(counter))
    else:
        print("Number not found")
        print("Searched for %s times" % str(counter))
