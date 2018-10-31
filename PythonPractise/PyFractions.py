class Fraction:
    def __init__(self, top, bottom):
        self.n = top
        self.d = bottom
    def __str__(self):
        return str(self.n)+"/"+str(self.d)

myFrac = Fraction(3,10)
print myFrac

# def gcd(m,n):
#     while m%n != 0:
#         oldm = m
#         oldn = n
#
#         m = oldn
#         n = oldm%oldn
#     return n
#
# print(gcd(20,6))