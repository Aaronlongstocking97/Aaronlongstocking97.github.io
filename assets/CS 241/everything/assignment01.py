"""
 Program:
    CS241 Assignment 01, Random Number Generator
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will pick a number and ask the user to guess that number.
    The program will accept guesses until you get the correct number. When
    finished it will display "play again".
"""

import random
from random import randint

print("Welcome to the number guessing game!")
seed = input("Enter random seed: ")
      
# Seed a random number 
random.seed(seed)

# In python there is no do while loop therefore 
# we need a way to get in the loop 
repeat = "yes"
while repeat == "yes":
    number = randint(1,100)
    print()
    # Input only taking a string value
    guess_number = int(input("Please enter a guess: "))
    guess_counter = 1
    while guess_number != number: 
        guess_counter += 1
        if guess_number > number:
            print("Lower\n")
            guess_number = int(input("Please enter a guess: "))
        elif guess_number < number:
            print("Higher\n")
            guess_number = int(input("Please enter a guess: "))
    print("Congratulations. You guessed it!")
    print("It took you {} guesses.\n" .format(guess_counter))
    repeat = input("Would you like to play again (yes/no)? ")
print("Thank you. Goodbye.")