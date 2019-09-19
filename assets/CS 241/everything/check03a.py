"""
 Program:
    CS241 Checkpoint 03A, Intro to Classes and Objects 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    Uses a Class Operator to call multiple objects that are assigned
    to the student class. These objects will call for the users input
    and display this information to the user. The information will be
    displayed to the user through main as main calls the student class
    and the objects that are tied to it.
                     
"""
# 
class Student:
    # The initializer or Constructor gives the new instances of student
    # an initial state value.
    def __init__(self):
        self.first_name = "" 
        self.last_name = ""
        self.id_number = 0 
    
def prompt_student():
    user = Student() # Instantiate object of type student
    
    # Uses the user object to perform the first_name method and
    # input data from the user.
    user.first_name = input("Please enter your first name: ")
    user.last_name = input("Please enter your last name: ")
    user.id_number = int(input("Please enter your id number: "))
        
    return user
    
def display_student(user):
    print("{} - {} {}" .format(user.id_number, user.first_name, user.last_name))
       

def main():
    
    # Since the user object is already defined as the student class
    # you wont need to use the user object to initalized each defined
    # object in the student class.
    user = prompt_student()
    print()
    print("Your information:")
    display_student(user)
    
if __name__ == "__main__":
    main()
       
    
