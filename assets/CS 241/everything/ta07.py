"""
 Program:
    CS241 Team Activity 07, Polymorphism
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
    
"""

class Employee:
    
    def __init__(self, name):
        self.name = name
        
    def display(self):
        print(self.name)


class HourlyEmployee(Employee):
    
    def __init__(self, name, wage):
        super().__init__(name)
        self.hourly_wage = wage
        
    def display(self):
        print("{} - ${}/hour" .format(self.name, self.hourly_wage))

class SalaryEmployee(Employee):
    
    def __init__(self, name, salary):
        super().__init__(name)
        self.salary = salary
    
    def display(self):
        print("{} - ${}/year" .format(self.name, self.salary))


def main():

    employees = []
    command = ""
    
    while command != "q":
        command = input("Enter 'h' (hourly employee), 's', (salary employee) or 'q': ")
      
        if command == 'h':
            name = input("Enter name: ")
            wage = input("Enter wage: ")
            
            e = HourlyEmployee(name, wage)
            employees.append(e)
            
        elif command == 's':
            name = input("Enter name: ")
            salary = input("Enter salary: ")
            
            e = SalaryEmployee(name, salary)
            employees.append(e)
            
    for employee in employees:
        employee.display()
                        


if __name__ == "__main__":
    main()
