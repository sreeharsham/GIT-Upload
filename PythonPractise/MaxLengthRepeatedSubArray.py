def findLength(A, B):
    """
    :type A: List[int]
    :type B: List[int]
    :rtype: int
    """
    x = len(A)
    y = len(B)
    dynTable = [[0 for j in range(y + 1)] for i in range(x + 1)]
    # dynTable[1][0] = 4
    # print(dynTable)

    count = 0

    i = 0
    val = 0

    for i in range(x):
        for j in range(y):
            if (A[i] == B[j]):
                val = dynTable[i][j] + 1
                dynTable[i + 1][j + 1] = val
                if count < val:
                    count = val
            else:
                dynTable[i + 1][j + 1] = 0
    print(dynTable)
    return count

A= [1,2,3,2,1]
B= [3,2,1,4,7]

counting = findLength(A,B)
print(counting)