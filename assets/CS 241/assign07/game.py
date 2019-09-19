"""
 Program:
    CS241 Assignment 07, Skeet Project
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This class handles all the game callbacks and interaction
    It assumes the following classes exist:
        - Rifle
        - Target (and it's sub-classes)
        - Point
        - Velocity
        - Bullet
    This class will then call the appropriate functions of
    each of the above classes.
                     
"""

import arcade
import math
import random
from global_ import *
from rifle import Rifle
from target import Target
from bullet import Bullet
from standard_target import StandardTarget
from strong_target import StrongTarget
from safe_target import SafeTarget

"""
* Sets up the initial conditions of the game
* :param width: Screen width
* :param height: Screen height
"""
class Game(arcade.Window):

    def __init__(self, width, height):
        super().__init__(width, height)
        self.rifle = Rifle()
        self.score = 0
        self.background = arcade.load_texture("image3.jpg")
        self.bullets = []
        # TODO: Create a list for your targets (similar to the above bullets)
        self.targets = []

    """
    * Called automatically by the arcade framework.
    * Handles the responsibility of drawing all elements.
    """
    def on_draw(self):
        # clear the screen to begin drawing
        arcade.start_render()
        arcade.draw_texture_rectangle(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2,
                                      SCREEN_WIDTH, SCREEN_HEIGHT, self.background)
        # draw each object
        self.rifle.draw()

        for bullet in self.bullets:
            bullet.draw()
        # TODO: iterate through your targets and draw them...
        for target in self.targets:
            target.draw()

        self.draw_score()
        
    """
    * Puts the current score on the screen
    """
    def draw_score(self):
        score_text = "Score: {}".format(self.score)
        start_x = 5
        start_y = SCREEN_HEIGHT - 30
        arcade.draw_text(score_text, start_x=start_x, start_y=start_y, font_size=18, color=arcade.color.BLACK)

    """
    * Update each object in the game.
    * :param delta_time: tells us how much time has actually elapsed
    """
    def update(self, delta_time):
        self.check_collisions()
        self.check_off_screen()
        # decide if we should start a target
        if random.randint(1, 50) == 1:
            self.create_target()
        for bullet in self.bullets:
            bullet.advance()
        # TODO: Iterate through your targets and tell them to advance
        for target in self.targets:
            target.advance()

    """
    * Creates a new target of a random type and adds it to the list.
    * :return:
    """
    def create_target(self):
        # TODO: Decide what type of target to create and append it to the list
        #for target in self.targets:
        random_targets = random.randint(1,4)
        safe = SafeTarget()
        strong = StrongTarget()
        standard = StandardTarget()
        
        if random_targets == 1:
            self.targets.append(standard)
        elif random_targets == 2:
            self.targets.append(strong)
        elif random_targets == 3:
            self.targets.append(safe)

    """
    * Checks to see if bullets have hit targets.
    * Updates scores and removes dead items.
    * :return:
    """
    def check_collisions(self):
        # NOTE: This assumes you named your targets list "targets"
        for bullet in self.bullets:
            for target in self.targets:
                # Make sure they are both alive before checking for a collision
                if bullet.alive and target.alive:
                    too_close = bullet.radius + target.radius
                    if (abs(bullet.center.x - target.center.x) < too_close and
                                abs(bullet.center.y - target.center.y) < too_close):
                        # its a hit!
                        bullet.alive = False
                        self.score += target.hit()
                        # We will wait to remove the dead objects until after we
                        # finish going through the list
        # Now, check for anything that is dead, and remove it
        self.cleanup_zombies()

    """
    * Removes any dead bullets or targets from the list.
    * :return:
    """
    def cleanup_zombies(self):
        for bullet in self.bullets:
            if not bullet.alive:
                self.bullets.remove(bullet)

        for target in self.targets:
            if not target.alive:
                self.targets.remove(target)

    """
    * Checks to see if bullets or targets have left the screen
    * and if so, removes them from their lists.
    * :return:
    """
    def check_off_screen(self):
        for bullet in self.bullets:
            if bullet.is_off_screen(SCREEN_WIDTH, SCREEN_HEIGHT):
                self.bullets.remove(bullet)

        for target in self.targets:
            if target.is_off_screen(SCREEN_WIDTH, SCREEN_HEIGHT):
                self.targets.remove(target)
    
    """
    * Takes in the values from _get_angle_degrees() and controls the
    * rifle through a mouse movement. 
    """
    def on_mouse_motion(self, x: float, y: float, dx: float, dy: float):
        # set the rifle angle in degrees
        self.rifle.angle = self._get_angle_degrees(x, y)

    """
    * Takes in values from _get_angle_degrees() and when the mouse is
    * pressed the bullets will fire from the rifle. 
    """
    def on_mouse_press(self, x: float, y: float, button: int, modifiers: int):
        # Fire!
        angle = self._get_angle_degrees(x, y)
        bullet = Bullet()
        bullet.fire(angle)
        self.bullets.append(bullet)

    """
    * Gets the value of an angle (in degrees) defined
    * by the provided x and y.
    * Note: This could be a static method, but we haven't
    * discussed them yet...
    """
    def _get_angle_degrees(self, x, y):
        # get the angle in radians
        angle_radians = math.atan2(y, x)
        # convert to degrees
        angle_degrees = math.degrees(angle_radians)
        return angle_degrees

# Creates the game and starts it going
window = Game(SCREEN_WIDTH, SCREEN_HEIGHT)
arcade.run()