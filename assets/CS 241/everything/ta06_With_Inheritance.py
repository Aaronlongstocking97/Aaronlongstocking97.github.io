"""
 Program:
    CS241 Team Activity 06, 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    The Circle class "Is - A" Point class
    
"""

class Point:
    
    def __init__(self):
        self.x = 0.0
        self.y = 0.0
        
    def prompt_for_point(self):
        self.x = input("Enter x: ")
        self.y = input("Enter y: ")
        
    def display(self):
        print("Center: ")
        print("({},{})" .format(self.x, self.y))


class Circle(Point):
    
    def __init__(self):
        super().__init__()
        self.radius = 0.0
        
    def prompt_for_circle(self):
        self.prompt_for_point()
        self.radius = input("Enter radius: ")
    
    def display(self):
        super().display()
        print("Radius: {}" .format(self.radius))



def main():

    c = Circle()
    c.prompt_for_circle()
    print()
    c.display()
    print()

if __name__ == "__main__":
    main()
