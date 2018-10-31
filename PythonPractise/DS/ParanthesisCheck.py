from Stack import Stack


def par_check(symbol_string):
    s = Stack()
    balanced = True
    index = 0
    while index < len(symbol_string) and balanced:
        symbol = symbol_string[index]
        if symbol == '(':
            s.push(symbol)
        else:
            if s.is_empty():
                balanced = False
            s.pop()
        index += 1


    if balanced and s.is_empty():
        return True
    else:
        return False


print(par_check('((()))'))
print(par_check('(()'))
