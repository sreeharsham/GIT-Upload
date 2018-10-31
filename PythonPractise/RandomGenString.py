import random


def generate(strlen):
    a = "abcdefghijklmnopqrstuvwxyz "
    # strlen = 28
    b = ""
    for i in range(strlen):
        b = b + a[random.randrange(27)]
    return b


def scoring(goal, test):
    numSame = 0
    for i in range(len(goal)):
        if goal[i] == test[i]:
            numSame = numSame + 1
    return numSame / len(goal)


def main():
    goalStr = "methinks it is like a weasel"
    newString = generate(28)
    while scoring(goalStr, newString) < 1:
        newString = generate(28)
        print newString


main()

#
