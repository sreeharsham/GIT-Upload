line = '8BADF00D'
line2 = 'COFFEE1C'



if len(line) != 8:
    print('INVALID')
else:
    first_six = line[:6]
    print(first_six)
    hex_val = int(first_six, 16)
    while hex_val > 0:
        dec_val =






