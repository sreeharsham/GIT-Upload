# b.py
print("Hello World from %s!" % __name__)
print("hi")

if __name__ == '__main__':
    print("Hello World again from %s!" % __name__)
else:
    print("Imported:%s" % __name__)
    for x in range(0, 3):
        print(x)
