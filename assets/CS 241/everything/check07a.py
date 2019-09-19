"""
 Program:
    CS241 Checkpoint 07a, Types of Cars
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    Passes the abstract class through the multiple sub classes
    and each sub class redefines the member varaibles as well as
    the abstractmethod function get_door_specs. All data from every
    class is passes to a seperate function that takes in the value
    of the ABC Car class and displays each one of the sub classes input
    data.
                     
"""

from abc import ABC
from abc import abstractmethod

class Car(ABC):
    
    def __init__(self):
        self.name = "Unknown model"
        
    @abstractmethod
    def get_door_specs(self):
        return "Unknown doors"


class Civic(Car):
    
    def __init__(self):
        super().__init__()
        self.name = "Civic"
        
    def get_door_specs(self):
        return "4 doors"


class Odyssey(Car):
    
    def __init__(self):
        super().__init__()
        self.name = "Odyssey"
        
    def get_door_specs(self):
        return "2 front doors, 2 sliding doors, 1 tail gate"


class Ferrari(Car):
    
    def __init__(self):
        super().__init__()
        self.name = "Ferrari"
        
    def get_door_specs(self):
        return "2 butterfly doors"


def attach_doors(Car):
    print("Attaching doors to {} - {}" .format(Car.name, Car.get_door_specs()))
    
# TODO: Create your attach_doors function here
# It should accept any type of car and use its
# name and get_door_specs function to print out
# the necessary data.
# It should not be a member function of any class,
# but rather just a "regular" function.


def main():
    car1 = Civic()
    car2 = Odyssey()
    car3 = Ferrari()

    attach_doors(car1)
    attach_doors(car2)
    attach_doors(car3)

if __name__ == "__main__":
    main()
