def linearSearch(item, list):
    found = False
    position = 0
    # counter = 0
    while position < len(list):
        # counter = 0
        if list[position] == item:
            found = True
            # print("Returned after %s searches" % str(position + 1))
            return found, position + 1
        position = position + 1
    return found, position
        # counter = counter + 1
    # print(position)
    # print(counter)
    # print("Returned after %s searches" % str(counter))
    # return found

if __name__ == '__main__':
    shopping = ["oranges", "apples", 'bananas', 'bread']
    print(shopping)
    item = input("Enter item to search for:")
    isFound, counter = linearSearch(item, shopping)
    if isFound:
        print("found after %s searches" % str(counter))
    else:
        print("not found after %s searches" % str(counter))
    # print("ITEM SEARCHED FOR ", counter, "times")
        # shopping.append(item)
        # print("ITEM ADDED!")
        # print("New list", shopping)
