"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will create a filled in circle that will symbolize
    the standard target. When the target has been considered hit then
    the user will be awarded one point for each target destroyed. 
                     
"""

from global_ import *
from target import Target

"""
* This class will take in the values from the FlyingObjects class
* as well as take in values from the Target class. This will be done
* through Polymorphism and will demonstrate the traits that are given
* through each child class or derived class'.
"""
class StandardTarget(Target):

    def __init__(self):
        super().__init__()

    """
    * Creates the object that will display once called through the Game class.
    """
    def draw(self):  
        return arcade.draw_circle_filled(self.center.x, self.center.y,
                                         TARGET_RADIUS, TARGET_COLOR)
    """
    * Once the target has a collision with the bullet object it will then
    * add one point to the users score.
    """
    def hit(self):
        delta_score = 1
        self.alive = False
        return delta_score 
