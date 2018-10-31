filename = input()
# print(filename)
with open(filename) as f:
    file_read = f.read()
# print(read_data)

dic = {}
for line in file_read.split('\n'):
    # print(line.split(' ')[0])
    if line != '':
        host = line.split(' ')[0]
        # print(host)
        if host not in dic:
            dic[host] = 1
        else:
            dic[host] += 1
# print(dic)

# dic = "Hello"
print(dic)
print_ln = ""
with open("records_" + filename, 'w') as fp:
    for key in dic.keys():
        print_ln = key + " " + str(dic[key]) + '\n'
        # print(print_ln)
        fp.write(print_ln)





