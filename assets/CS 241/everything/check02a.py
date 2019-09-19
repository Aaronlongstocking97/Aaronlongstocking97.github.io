"""
 Program:
    CS241 Checkpoint 02A, The Sum of Three Positive Numbers
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    Prompting the user for a positive number if that number 
    is not in those parameters then it will return .Invalid 
    entry." In addition the program adds three positive 
    numbers together to a sum function and displays the 
    result of that function.
                     
"""
# We want to prompt the user for the input at least once.
def prompt_number():
    pos_number = -1 # initiates the While loop 
  
    while pos_number < 0:   # the user will enter a number greater than zero
        pos_number = int(input("Enter a positive number: "))
        if pos_number < 0:
            print("Invalid entry. The number must be positive.")
    print()
    
    return pos_number    
# compute_sum function takes in 3 numbers from the main.
# Three varibales cominmg from the main.
def compute_sum(num1, num2, num3):
    
    sum_num = num1 + num2 + num3
    
    return sum_num

def main():
    num1 = prompt_number()
    num2 = prompt_number()
    num3 = prompt_number()
    
    sum_num = compute_sum(num1, num2, num3)
    print("The sum is: {}" .format(sum_num))
    

    
if __name__ == "__main__":
    main()
       
    
    