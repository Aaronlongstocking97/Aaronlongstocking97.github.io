"""
 Program:
    CS241 Checkpoint 10c, Bubble Sort 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
    
"""

def sort(numbers):
    """
    Fill in this method to sort the list of numbers
    """
    for sort_pos in range(len(numbers)-1, 0, -1):        

        for swap_pos in range(sort_pos):

            if numbers[swap_pos] > numbers[swap_pos+1]:
                numbers[swap_pos], numbers[swap_pos+1] = numbers[swap_pos+1],
                numbers[swap_pos]


def prompt_for_numbers():
    """
    Prompts the user for a list of numbers and returns it.
    :return: The list of numbers.
    """
    
    
    numbers = []
    print("Enter a series of numbers, with -1 to quit")


    num = 0


    while num != -1:
        num = int(input())


        if num != -1:
            numbers.append(num)


    return numbers


def display(numbers):
    """
    Displays the numbers in the list
    """
    print("The list is:")
    for num in numbers:
        print(num)


def main():
    """
    Tests the sorting process
    """
    numbers = prompt_for_numbers()
    sort(numbers)
    display(numbers)

if __name__ == "__main__":
    main()