"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will create a filled in rectangle that will
    symbolize a safe target. Once this target is hit it will
    deduct ten points from the users score. 
                     
"""

from global_ import *
from target import Target

"""
* This class will take in the values from the FlyingObjects class
* as well as take in values from the Target class. This will be done
* through Polymorphism and will demonstrate the traits that are given
* through each child class or derived class'.
"""
class SafeTarget(Target):

    def __init__(self):
        super().__init__()

    """
    * 
    """
    def draw(self):
        return arcade.draw_rectangle_filled(self.center.x, self.center.y, TARGET_SAFE_WIDTH, TARGET_SAFE_HEIGHT, TARGET_SAFE_COLOR)
    
    """
    * 
    """
    def hit(self):
        delta_score = -10
        self.alive = False
        return delta_score
    