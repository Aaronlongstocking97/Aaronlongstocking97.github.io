"""
 Program:
    CS241 Data Structures assign 10, List Manipulation
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 

"""

numbers = [12, 18, 128, 48, 2348, 21, 18, 3, 2, 42, 96, 11, 42, 12, 18]
#           0   1    2   3     4   5   6  7  8   9  10  11  12  13  14
print("List: {}" .format(numbers))

numbers.insert(0,5)
print("First step: {}" .format(numbers))

numbers.remove(2348)
print("Second step: {}" .format(numbers))

new_numbers = [10, 20, 30, 40, 50]
numbers += new_numbers
print("Third step: {}" .format(numbers))

numbers.sort()
print("Fourth step: {}" .format(numbers))

numbers.sort(reverse = True)
print("Fifth step: {}" .format(numbers))

print("Six step: {}" .format(numbers.count(12)))

print("Seventh step: {}" .format(numbers.index(96)))

middle = len(numbers) // 2
left = numbers[:middle]
right = numbers[middle:]
print("Eighth step: left{}, right{}" .format(left, right))

skip_list = numbers[::2]
print("Ninth step: {}" .format(skip_list))

last_five = numbers[-5:]
print("Tenth step: {}" .format(skip_list))

