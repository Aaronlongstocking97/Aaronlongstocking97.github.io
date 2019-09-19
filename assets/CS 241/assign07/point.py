"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This Class will set the inital state values for
    both x and y axis as well as set each point to
    a floating point value. It will also be
    passed through multiple class with a "Has - A"
    relationship and give the default values as
    listed below. 
                     
"""

"""
* This class will set the intial values that can be
* passed into other classes.
"""
class Point:

    def __init__(self):
        self.x = 0.0
        self.y = 0.0
