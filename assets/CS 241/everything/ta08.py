"""
 Program:
    CS241 Team Activity 08, Getters / Setters
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
    
"""

class Time():
    
    def __init__(self):
        self._hours = 0
        self._minutes = 0
        self._seconds = 0
    
    def get_hours(self):
        return self._hours
    
    def set_hours(self, hours):
        if hours > 23:
            self._hours = 0
        else:
            self._hours = hours

    def get_minutes(self):
        return self._minutes
    
    def set_minutes(self, minutes):
        if minutes > 59:
            self._minutes = 0
        else:
            self._minutes = minutes
            
    def get_seconds(self):
        return self._seconds
    
    def set_seconds(self, seconds):
        if seconds > 59:
            self._seconds = 0
        else:
            self.seconds = seconds
        
    #hours = property(get_hours, set_hours)
    #minutes = property(get_minutes, set_minutes)
    #seconds = property(get_seconds, set_seconds)
    
    @property
    def hours(self):
        return self._hours
    
    @hours.setter
    def hours(self, hours):
        self._hours(hours)
    
    @property
    def mintues(self):
        return self.get_minutes()
    
    @minutes.setter
    def minutes(self, minutes):
        self.set_minutes(minutes)
    
    @property
    def seconds(self):
        return self.get_seconds()
    
    @seconds.setter
    def seconds(self, seconds):
        self.set_seconds(seconds)
        
        
def main():

    time = Time()

    hours = int(input("Enter the number of hours: "))
    minutes = int(input("Enter the number of minutes: "))
    seconds = int(input("Enter the number of seconds: "))
    
    time.hours = hours
    time.minutes = minutes
    time.seconds = seconds
    
    print("The time is: {}:{}:{}" .format(time.hours, time.minutes,
                                          time.seconds))

    
if __name__ == "__main__":
    main()
