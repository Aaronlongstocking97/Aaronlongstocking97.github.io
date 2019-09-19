"""
 Program:
    CS241 Data Structures assign 03, Display Even and Odd numbers
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
        This program will take in values into two empty lists
        that will have even numbers and odd numbers.
"""

# Start with empty lists
evenNum = []
oddNum = []
    
# Loop until 0 is entered
number = 1
while (number != 0):
    number = int(input("Enter a number (0 to quit): "))
    # If number is even (and not 0) then add to even list
    # If number is odd then add to odd list
    if (number != 0 and number % 2 == 0):
        evenNum.append(number)
    elif (number % 2 == 1):
        oddNum.append(number)

# Print out both lists

print()
print("Even numbers:")
for number in evenNum:
    print(number)
    
print()
print("Odd numbers:")
for number in oddNum:
    print(number)

    