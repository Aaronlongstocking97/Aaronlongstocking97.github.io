// CS165 - Checkpoint 02A

#include <iostream>
using namespace std;

struct Student
{
    string firstName;
    string lastName;
    int id;
};

// Display the student information
// Student is constant and passed by reference
// However it is a constant so it cannot be modified
void displayStudent(const Student &student)
{
    cout << student.id << " - " << student.firstName << " " <<
            student.lastName << endl;
}

// Driver
int main()
{
   Student student;

   cout << "Please enter your first name: ";
   cin >> student.firstName;
   cout << "Please enter your last name: ";
   cin >> student.lastName;
   cout << "Please enter your id number: ";
   cin >> student.id;

   cout << "\nYour information:\n";
   displayStudent(student);

   return 0;
}
