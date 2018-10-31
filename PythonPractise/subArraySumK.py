def subArraySum(mylist, k):
    counter = 0
    # summing = 0
    for i in range(len(mylist)):
        summing = 0
        if mylist[i] == k:
            counter = counter + 1
        for j in range(i, len(mylist)):
            # print(i, mylist[i], j, mylist[j])
            summing = summing + mylist[j]
            # print(mylist[i], mylist[j])
            # print("----")
            # print(mylist[i] + mylist[j])
            # print("xxxx")
            print(i, mylist[i], j,  mylist[j], summing)
            if summing == k:
                counter = counter + 1
            # if mylist[j] == k:
                # counter = counter + 1
            # elif mylist[i] + mylist[j] == k:
            #     counter = counter + 1
            # print(mylist[j])
    return counter

mainList = [-2, -2, 2, 3, -2, 1, -3]
finalres = subArraySum(mainList, -4)
print(finalres)