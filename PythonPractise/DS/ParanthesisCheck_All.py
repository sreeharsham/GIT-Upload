PAIRINGS = {
    '(': ')',
    '{': '}',
    '[': ']'
}


def is_balanced(symbols):
    stack = []
    for s in symbols:
        if s in PAIRINGS.keys():
            stack.append(s)
            print("APPEND", stack)
            continue
        try:
            expected_opening_symbol = stack.pop()
            print("POP", expected_opening_symbol)
        except IndexError:  # too many closing symbols
            print("INDEX ERROR")
            return False
        if s != PAIRINGS[expected_opening_symbol]:  # mismatch
            return False
    return len(stack) == 0  # false if too many opening symbols

#print(is_balanced('{{([][])}()}'))  # => True
print(is_balanced('{([])'))  # => False
#is_balanced('((()))')  # => True
#is_balanced('(()')  # => False
#is_balanced('())')  # => False