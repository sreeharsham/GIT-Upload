def BubbleSort(myList):
    # print(myList)
    moreSwap = True
    # print("in")
    while moreSwap:
        moreSwap = False
        for element in range(len(myList) - 1):
            
            if myList[element] > myList[element+1]:
                moreSwap = True

                temp = myList[element]
                myList[element] = myList[element+1]

                myList[element+1] = temp
    return myList
    # for i in range(len(myList)):
    #     print(i, myList[i])



if __name__ == "__main__":
    # print("hi")
    unSortedList = [3, 2, 6, 1, 5, 4]
    sortedList = BubbleSort(unSortedList)
    print(sortedList)
