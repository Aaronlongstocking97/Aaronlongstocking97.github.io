"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will use objects from the point classs as well as the
    angle thats defined in the member variable to create an rectangle
    object that mimics the ability to act like a rifle. 
                     
"""

from global_ import *
from point import Point

"""
* This class will be used to display an object that will mimic a
* rifle shooting bullets at targets.
"""
class Rifle:

    def __init__(self):
        self.center = Point()
        self.center.x = 0
        self.center.y = 0
        self.angle = 45

    """
    * Creates the object that will imitate a rifles barrel. 
    """
    def draw(self):
        arcade.draw_rectangle_filled(self.center.x, self.center.y, RIFLE_WIDTH, RIFLE_HEIGHT, RIFLE_COLOR, self.angle)
        