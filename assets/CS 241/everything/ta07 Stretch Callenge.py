"""
 Program:
    CS241 Team Activity 07, Polymorphism
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
    
"""

from abc import ABC
from abc import abstractmethod

class Employee(ABC):
    
    def __init__(self):
        self.name = ""
        
    @abstractmethod
    def display(self):
        pass

    @abstractmethod
    def get_paycheck(self):
        pass

class HourlyEmployee(Employee):
    
    def __init__(self):
        super().__init__()
        self.name = ""
        self.hourly_wage = 0
        self.hours = 0
        
    def display(self):
        print("{} - ${}/hour" .format(self.name, self.hourly_wage))
        
    def get_paycheck(self):
        return self.hours * self.hourly_wage

class SalaryEmployee(Employee):
    
    def __init__(self):
        super().__init__()
        self.name = ""
        self.salary = 0
    
    def display(self):
        print("{} - ${}/year" .format(self.name, self.salary))
        
    def get_paycheck(self):
        return self.salary // 24
    
def display_employee_data(Employee):
    Employee.display()
    print("Your paycheck amount is: {}" .format(Employee.get_paycheck()))

def main():

    employees = []
    command = ""
    
    while command != "q":
        command = input("Enter 'h' (hourly employee), 's', (salary employee) or 'q': ")
      
        if command == 'h':
            name = input("Enter name: ")
            hourly_wage = float(input("Enter wage: "))
            hours = float(input("Enter hours: "))
            
            h = HourlyEmployee()
            h.name = name
            h.hourly_wage = hourly_wage
            h.hours = hours
            employees.append(h)
            
        elif command == 's':
            name = input("Enter name: ")
            salary = float(input("Enter salary: "))
            
            s = SalaryEmployee()
            s.name = name
            s.salary = salary
            employees.append(s)
        
    for employee in employees:
        display_employee_data(employee)
        
        
        
    
       

                        


if __name__ == "__main__":
    main()

