"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will be the top of a derived hierarchy, but will
    still Inherit the values from the FlyingObjects ABC. This class
    will also demonstrate forms of polymorphism through unique child
    classes that will be originated from this ABC.
                     
"""

import random
from global_ import *
from flying_objects import FlyingObjects
from abc import ABC
from abc import abstractmethod

"""
* This class will be the architecture for its child classes by establishing
* multiple abstract methods by acting as the parent class. It will also
* demonstrate uses of inheritance from objects in the FlyingObjects parent class.
"""
class Target(FlyingObjects, ABC):

    def __init__(self):
        super().__init__()
        self.center.y = random.uniform(250, SCREEN_HEIGHT - 40)
        self.velocity.dx = random.uniform(1,5) 
        self.velocity.dy = random.uniform(-2,5)
        self.radius = TARGET_RADIUS

    """
    * A decorated function that cannot be changed unless the abstract
    * methods or properties are overridden. 
    """
    @abstractmethod
    def draw(self):
        pass
    
    """
    * A decorated function that cannot be changed unless the abstract
    * methods or properties are overridden. 
    """
    @abstractmethod
    def hit(self):
        pass
