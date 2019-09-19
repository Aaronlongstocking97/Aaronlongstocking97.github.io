"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program displays to the user a circle that is controlled by
    Game class and represents a bullet being fired. It derives from
    the FlyingObjects class through the use of Inheritance.
                     
"""

import math
from global_ import *
from flying_objects import FlyingObjects

"""
* This class will represent a bullet that will be used through
* the Game class and take in the global variable for the radius.
"""
class Bullet(FlyingObjects):

    def __init__(self):
        super().__init__()
        self.radius = BULLET_RADIUS

    """
    * Creates the circle object that will be displayed to the user.
    """
    def draw(self):
        arcade.draw_circle_filled(self.center.x, self.center.y, BULLET_RADIUS, BULLET_COLOR)
    
    """
    * Redefines the Velocities that are inherited through the FlyingObjects
    * class and uses the global BULLET_SPEED to calculate the direction of
    * the objects momentum. 
    """
    def fire(self, angle: float):
        self.velocity.dx = math.cos(math.radians(angle)) * BULLET_SPEED
        self.velocity.dy = math.sin(math.radians(angle)) * BULLET_SPEED
