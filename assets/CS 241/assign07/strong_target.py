"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will draw a circle that has a number value inside
    of the circles radius. This number will varry based on the amount
    of times the circle has had a collision with the bullet. Once the
    bullet reaches less than one it will then be destroyed and will
    add five points to the users score. 
                     
"""

import random
from global_ import *
from target import Target

"""
* This class will take in the values from the FlyingObjects class
* as well as take in values from the Target class. This will be done
* through Polymorphism and will demonstrate the traits that are given
* through each child class or derived class'.
"""
class StrongTarget(Target):

    def __init__(self):
        super().__init__()
        self.lives = 3
        self.velocity.dx = random.uniform(1,3) 
        self.velocity.dy = random.uniform(-2,3) 
   
    """
    * Creates an object once called by the Game class.
    * this object will have a circle that is not filled in
    * but rather have a number value inside of this circle.
    """
    def draw(self):
        arcade.draw_circle_outline(self.center.x, self.center.y, TARGET_RADIUS, TARGET_COLOR)
        text_x = self.center.x - (TARGET_RADIUS / 2)
        text_y = self.center.y - (TARGET_RADIUS / 2)
        arcade.draw_text(repr(self.lives), text_x, text_y, TARGET_COLOR, font_size=20)
    
    """
    * Every time the bullet collides with the target it will
    * deduct one point from the lives the target has. Once the
    * target has less than one life it will then be considered
    * destroyed and the user will be awarded five points for
    * hitting this target. 
    """
    def hit(self):
        delta_score = 1
        self.lives -= 1
        if (self.lives == 0):
            self.alive = False
            delta_score = 5
        return delta_score 
          