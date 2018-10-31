from PythonPractise.StackImplementation import Stack


def to_binary(dec):
    s = Stack()
    # print(dec)
    while dec > 0:
        n = dec % 2
        s.push(n)
        dec = dec // 2
    return s.print_stack()

bin_val = (to_binary(242))[::-1]
print(''.join(str(x) for x in bin_val))
