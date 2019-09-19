"""
 Program:
    CS241 Assignment 03, Intro to Classes and Objects 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will prompt the user for a command that will control
    the position of the Robot(class) at the starting point (10,10) with
    the fuel level starting at 100. If the fuel level drops below 0 then
    the user will not be able to input anymore commands for the Robot and
    will need to quit the game with the command 'quit'. Everytime the user
    enters a new command the Robot will move, but the user will not see
    the movements in the parameters (#,#) until they enter the command keyword
    'status'.
                     
"""


"""
* A Class that uses multiple objects to control the movement and fuel levels
* of a 'Robot'.
"""
class Robot:
    # The initializer or Constructor gives the new instances of Complex
    # an initial state value.
    def __init__(self):
        self.x = 10
        self.y = 10
        self.fuel = 100
        
    """
    * An object that has the Robot move left when called by the user.
    """
    def left(self):
        if self.fuel < 5: # As long as the fuel is greater than five
            # the user can keep inputing new commmands
            print("Insufficient fuel to perform action")
        else:
            self.x = self.x - 1
            self.fuel = self.fuel - 5

    """
    * An object that has the Robot move right when called by the user.
    """
    def right(self):
        if self.fuel < 5:
            print("Insufficient fuel to perform action")
        else:
            self.x = self.x + 1
            self.fuel = self.fuel - 5
            
    """
    * An object that has the Robot move up when called by the user.
    """    
    def up(self):
        if self.fuel < 5:
            print("Insufficient fuel to perform action")
        else:
            self.y = self.y - 1
            self.fuel = self.fuel - 5
        
    """
    * An object that has the Robot move down when called by the user.
    """    
    def down(self):
        if self.fuel < 5:
            print("Insufficient fuel to perform action")
        else:
            self.y = self.y + 1
            self.fuel = self.fuel - 5
            
    """
    * An object that has the Robot fire when called by the user.
    """
    def fire(self):
        if self.fuel < 15:# As long as the fuel is greater than fifteen
            # the user can keep inputing new commmands
            print("Insufficient fuel to perform action")
        else:
            self.fuel = self.fuel - 15
            print("Pew! Pew!")
            
    """
    * An object that displays the status of the Robots movement and fuel level
    * when prompted by the user.
    """  
    def status(self):
        
        print(("({}, {}) - Fuel: {}") .format(self.x, self.y, self.fuel))

"""
* A function that is called by main and used as a clossing to the while looop.
"""  
def quitt():              
# the quitt function is not indented because it is not part of the Robot Class     
    print("Goodbye.")
       

"""
* The driver function that initializes the while loop and defines the Robot class.
"""  
def main():
    r = Robot() # Defining the Robot class 
    command = "" # Setting the command variable to a string
    while command != "quit":
        # Loops through each command until user enters quit or
        # the Robot runs out of fuel
        command = input("Enter command: ")
        if command == "left":
            r.left()
        elif command == "right":
            r.right()
        elif command == "up":
            r.up()
        elif command == "down":
            r.down()
        elif command == "fire":
            r.fire()
        elif command == "status":
            r.status()
    
    quitt() # This is outside of the Robot class so it doesn't require a tie
    # the class such as "r."
 
  
# If this is the main program being run, call our main function above
if __name__ == "__main__":
    main()
