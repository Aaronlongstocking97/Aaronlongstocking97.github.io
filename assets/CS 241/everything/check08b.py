"""
 Program:
    CS241 Checkpoint 08b, Intro to Properties 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will take in the value for a GPA and
    set the inputed value to a letter. It will then prompt
    the user to enter a new letter which intern will set the
    complimentary number to that letters value.
    
"""

class GPA():
    
    def __init__(self):
        self.gpa = 0.0
    
    def _get_gpa(self):
        return self._gpa
    
    def _set_gpa(self, gpa):
        if gpa < 0.0:
            self._gpa = 0.0
        else:
            self._gpa = gpa

    def _get_letter(self):
        
        if self._gpa <= 0.99:
            return "F"
        elif self._gpa <= 1.99:
            return "D"
        elif self._gpa <= 2.99:
            return "C"
        elif self._gpa <= 3.99:
            return "B"
        else:
            return "A"
    
    def _set_letter(self, letter):
        
        if letter == "A":
            self._gpa = 4.0
        elif letter == "B":
            self._gpa = 3.0
        elif letter == "C":
            self._gpa = 2.0
        elif letter == "D":
            self._gpa = 1.0
        else:
            self._gpa = 0.0

    gpa = property(_get_gpa, _set_gpa)
    
    @property
    def letter(self):
        return self._get_letter()
    
    @letter.setter
    def letter(self, letter):
        self._set_letter(letter)
        
        
def main():

    student = GPA()

    print("Initial values:")
    print("GPA: {:.2f}".format(student.gpa))
    print("Letter: {}".format(student.letter))

    value = float(input("Enter a new GPA: "))

    student.gpa = value

    print("After setting value:")
    print("GPA: {:.2f}".format(student.gpa))
    print("Letter: {}".format(student.letter))

    letter = input("Enter a new letter: ")

    student.letter = letter

    print("After setting letter:")
    print("GPA: {:.2f}".format(student.gpa))
    print("Letter: {}".format(student.letter))
    
    
if __name__ == "__main__":
    main()

