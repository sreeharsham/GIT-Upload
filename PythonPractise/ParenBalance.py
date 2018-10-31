from PythonPractise.StackImplementation import Stack


def paren_balance(parenthesis):
    s = Stack()
    balanced = True
    index = 0
    while index < len(parenthesis): # and balanced--- why?
        paren = parenthesis[index]
        if paren in "{[(":
            s.push(paren)
        else:
            if s.is_empty():
                balanced = False
            else:
                top = s.pop()
                if not is_match(top, paren):
                    balanced = False
        index += 1
    if s.is_empty() and balanced:
        return True
    else:
        return False


def is_match(p1, p2):
    if p1 == '{' and p2 == '}':
        return True
    elif p1 == '[' and p2 == ']':
        return True
    elif p1 == '(' and p2 == ')':
        return True
    else:
        return False


print(paren_balance('))'))



