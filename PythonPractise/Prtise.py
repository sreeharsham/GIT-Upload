# # a = raw_input("enter bdate")
# #
# # print type(a)
#
# # b = raw_input("Enter name")
# # year = ""
# # count = 0
# #
# #
# # for c in b:
# #     # while count < 4:
# #         # year = year + c
# #     print c
# #     year = year + c
# #     # count  = count + 1
# #
# #
# # print year
# # # print year
#
# # a = input("please enter name")
# # print(type(a))
# # print("your name is " + a)
# dob = input("Please enter your data of birth:")
# n = int(input("How many times do you want to print the message"))
# lists = dob.split('-')
# # print(lists[0])
# lists[0] = int(lists[0])
# hundred = lists[0] + 100
# # print(type(lists[0]))
# # while n > 0:
# #     print("You will turn 100 in " + str(hundred))
# #     n = n - 1
# print(n* ("You will turn 100 in " + str(hundred) + "\n"))

# a = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
# b = []
# n = int(input("Enter number"))
# for num in a:
#     if num < n:
#         # print(num)
#         b.append(num)
#
# print(b)

# n = int(input("Enter number to find divisors:"))
# listnum = list(range(1,n))
# listnum.append(len(listnum) + 1)
# # print(listnum)
# for i in listnum:
#     if n%i == 0:
#         print(i)
# import random
# # a = [1,4,3,2]
# a = []
# b = []
# # b = sorted(a)
# # a.sort()
# # sorted(a)
# # print(b)
# # print(random.randrange(0,10))
# for n in range(0,random.randrange(1,11)):
#     a.append(random.randrange(0,10))
# for m in range(0,random.randrange(1,11)):
#     b.append(random.randrange(0,10))
# a.sort()
# b.sort()
# # print(5 in a)
# print(a)
# print(b)
# c = [];
# for numbers in b:
#     if numbers in a:
#         c.append(numbers)
# print(c)

# a = [1,2,3,4,5]
# print(a[:-1])
# letters = "ancd"
# print(letters[2:4])

# checkword = input("Enter word for palindrome check:")
# wordcheck = ""
# # print(checkword)
# for letters in checkword:
#     wordcheck = letters + wordcheck
#     print(letters)
#     print(wordcheck)
# print(wordcheck)
# if checkword == wordcheck:
#     print("Entered String " + checkword + " is a palindrome")
# else:
#     print("Not a palindrome")

# wrd=input("Please enter a word")
# wrd=str(wrd)
# rvs=wrd[::-1]
# print(rvs)
# if wrd == rvs:
#     print("This word is a palindrome")
# else:
#     print("This word is not a palindrome")

# words = "Manyhappyreturns"
# word = words[-6::1]
# word = words[:-6:1]
# print(word)

# a = [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
# # onlyeven = []
# # for num in a:
# #     if num % 2 == 0:
# #         onlyeven.append(num)
# # print(onlyeven)
# onlyeven = [num for num in a if num % 2 == 0]
# print(onlyeven)

# a = "r"
# print(a.upper())

#CAN ALSO USE R=1, S=2, P=3. if DIFF(a-b) is -1 or 2 then A elif -2 or 1 then B else TIED

# userpick1 = input("Enter user1 pick from R for ROCK/P for PAPER/S for SCISSORS:")
# userpick2 = input("Enter user2 pick from R for ROCK/P for PAPER/S for SCISSORS:")
#
# if userpick1.upper() not in ("R", "P", "S") or userpick2.upper() not in ("R", "P", "S"):
#     print("Invalid choice!")
# else:
#     if (userpick1 == 'R' and userpick2 == 'P') or (userpick1 == 'P' and userpick2 == 'S') or (userpick1 == 'S' and userpick2 =='R'):
#         print("Player 2 wins!")
#     elif (userpick1 == userpick2):
#         print("TIED!")
#     else:
#         print("Player 1 wins!")

# user1 = input("What's your name?")
# user2 = input("And your name?")
# user1_answer = input("%s, do yo want to choose rock, paper or scissors?" % user1)
# user2_answer = input("%s, do you want to choose rock, paper or scissors?" % user2)
# print(user1)
# print(user2)
# print(user1_answer)
# print(user2_answer)


# import  random
# genrand = random.randint(1,9)
# userchoice = 0
#
# while userchoice != genrand and userchoice != "exit":
#     userchoice = input("Enter your guess:")
#     userchoice = int(userchoice)
#     if userchoice > genrand:
#         print("Too High!")
#
#     elif userchoice < genrand:
#         print("Too Low!")
#
#     else:
#         print("Right!")
#
# import random
#
# number = random.randint(1, 9)
# guess = 0
# count = 0
#
# while guess != number and guess != "exit":
#     guess = input("What's your guess?")
#
#     if guess == "exit":
#         break
#
#     guess = int(guess)
#     count += 1
#
#     if guess < number:
#         print("Too low!")
#     elif guess > number:
#         print("Too high!")
#     else:
#         print("You got it!")
#         print("And it only took you", count, "tries!")

class MyClass:
    Greeting = ""
    def __init__(self, Name="there"):
        self.Greeting = Name + "!"
    def SayHello(self):
        print("Hello {0}".format(self.Greeting))
MyInstance = MyClass()
MyInstance.SayHello()
MyInstance = MyClass("Amy")
MyInstance.SayHello()