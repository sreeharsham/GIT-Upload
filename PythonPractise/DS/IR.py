import math

def main():
   array = []
   with open('test.txt', 'r') as filehandle:
       for line in filehandle:
           array.append(float(line))
   print(array)

   dcg =0
   for i in range(1,6):
       value = array[i-1]/math.log(i+1,2)
   #    print(value)
       dcg +=value

   print(dcg)


if __name__ == '__main__':
   main()