"""
 Program:
    CS241 Data Structures assign 04, Student Help Center
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 

"""

from collections import deque

### Represents a student with their tutoring needs
class Student:

    ### Initialize student object
    def __init__(self):
        self.name = ""
        self.course = ""

    ### Prompt for student name and course needing help
    def prompt(self):
        self.name = input("Student Name: ")
        self.course = input("Course Name: ")

    ### Display student information
    def display(self):
        print("{} - {}" .format(self.name, self.course))

### Represents a Help System which implements a queue of
### students needing help
class HelpSystem:

    ### Initialize the HelpSystem object with an empty queue
    def __init__(self):
        self.waiting_list = deque()

    ### Determine if there are any students in the queue.
    def is_student_waiting(self):
        return (len(self.waiting_list) > 0)

    ### Add a student to the queue
    def add_to_waiting_list(self, student):
        self.waiting_list.append(student)

    ### Remove the next student from the queue and display their information.
    ### If the queue is empty, then display a message.
    def help_next_student(self):
        if self.is_student_waiting():
            student = self.waiting_list.popleft()
            print("Now helping:")
            student.display()
            if self.is_student_waiting():
                print("Get ready:")
                student = self.waiting_list[0]
                student.display()
            else:
                print("No one to help.")

### Provide menu to use the HelpSystem
def main():
    selection = 0
    help_system = HelpSystem()
    while (selection != 3):
        print()
        print("Options:")
        print("1. Add a new student")
        print("2. Help next student")
        print("3. Quit")
        selection = int(input("Enter selection: "))
        print()
        if selection == 1:
            student = Student()
            student.prompt()
            help_system.add_to_waiting_list(student)
        elif selection == 2:
            help_system.help_next_student()
    print("Goodbye")

if __name__ == "__main__":
    main()