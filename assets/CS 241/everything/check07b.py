"""
 Program:
    CS241 Checkpoint 07b, Assorted Shapes
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    Taking in the values for each shapes variable and returning
    the return values from get_area. this function is passed
    through each sub class from the base abstract class. Both sub
    classes are added to a list of shapes in the main function. The
    user will be prompted for either a circle of rectangle from the
    while loop. 
    
"""

from abc import ABC
from abc import abstractmethod

class Shape(ABC):
    def __init__(self):
        self.name = ""
    
    def display(self):
        print("{} - {:.2f}" .format(self.name, self.get_area()))

    @abstractmethod
    def get_area(self):
        pass


class Circle(Shape):
    
    def __init__(self):
        super().__init__()
        self.name = "Circle"
        self.radius = 0.0
        
    def get_area(self):
        return 3.14 * self.radius * self.radius
        

class Rectangle(Shape):
    
    def __init__(self):
        super().__init__()
        self.name = "Rectangle"
        self.length = 0.0
        self.width = 0.0
        
    def get_area(self):
        return self.length * self.width


def main():

    shapes = []
    command = ""

    while command != "q":
        command = input("Please enter 'c' for circle, 'r' for rectangle or 'q' to quit: ")

        if command == "c":
            radius = float(input("Enter the radius: "))
            c = Circle()
            c.radius = radius
            shapes.append(c)
            
        elif command == "r":
            length = float(input("Enter the length: "))
            width = float(input("Enter the width: "))
            r = Rectangle()
            r.length = length
            r.width = width
            shapes.append(r)

    for shape in shapes:
        shape.display()


if __name__ == "__main__":
    main()

