"""
 Program:
    CS241 Data Structures assign 07, 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 

"""

def fib(n):
# Base Cases
if n <= 0:
return 0
elif n == 1:
return 1
elif n == 2:
return 1

# By definition: fib(n) = fib(n-1) + fib(n-2)
return fib(n-1) + fib(n-2)

# Print out the first 20 fib numbers
for i in range(20):
print("fib({}) = {}" .format(i, fib(i)))

# By the way, this is not wise for larger values of 20. The
# 100th Fib number is 354,224,848,179,261,915,075. This can not be done
# with recurrsion. You can solve this problem a lot easier with a loop.

# With that said, this is a really easy one to see how recursion works.