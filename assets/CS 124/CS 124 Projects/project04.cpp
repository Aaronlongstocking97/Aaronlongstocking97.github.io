/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary:
*    Asking the user for there monthly income. Once they type that in
*    they will be prompted for a list of other items, that will be displayed
*    in a table. This table will consist of there monthly budget in two 
*    groups. There normal budget and there actual budget.
*
*    Estimated:  3.0 hrs   
*    Actual:     5.0 hrs
*    Running testBed and getting everything fixed.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
  * Prompting the user for there income. 
 ***********************************************************************/
double getIncome()
{
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;

   return income;
}

/**********************************************************************
  * Prompting the user for there budget living expenses.
 ***********************************************************************/
double getBudgetLiving()
{
   double budgetLiving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;

   return budgetLiving;         
}

/**********************************************************************
  * Prompting the user for there actual living expenses.
 ***********************************************************************/
double getActualLiving()
{
   double actualLiving;
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;

   return actualLiving;  
}

/**********************************************************************
  * Prompting the user for there actual tax withholding.
 ***********************************************************************/
double getActualTax()
{
   double actualTax;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;

   return actualTax;  
}

/**********************************************************************
  * Prompting the user for there tithe offering.
 ***********************************************************************/
double getActualTithing()
{
   double actualTithing;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;

   return actualTithing;  
}

/**********************************************************************
  * Prompting the user for there actual other expenses. 
 ***********************************************************************/
double getActualOther()
{
   double actualOther;
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;

   return actualOther;
}

/**********************************************************************
  * Calculating the tax from the income by using
  * a tax bracket system.  
 ***********************************************************************/
double computeTax(double income)
{
   if (income * 12 > 0 && income * 12 <= 15100)
      return income * 0.10;
   else if (income * 12 > 15100 && income * 12 <= 61300)
      return 1510.00 / 12 + (income - 15100.00 / 12) * 0.15;
   else if (income * 12 > 61300 && income * 12 <= 123700)
      return 8440.00 / 12 + (income - 61300.00 / 12) * 0.25;
   else if (income * 12 > 123700 && income * 12 <= 188450)
      return 24040.00 / 12 + (income - 123700.00 / 12) * 0.28;
   else if (income * 12 > 188450 && income * 12 <= 336550)
      return 42170.00 / 12 + (income - 188450.00 / 12) * 0.33;
   else if (income * 12 > 336550)
      return 91043.00 / 12 + (income - 336550.00 / 12) * 0.35;
}

/**********************************************************************
  * Calculating the tithing based on the income.
 ***********************************************************************/
double computeTithing(double income)
{
   return (income * 0.10);
}

/**********************************************************************
 * Calculating the actual differences from the income.
 ***********************************************************************/
double getActualDifference(double income, double actualTaxes,
                           double actualTithe, double actualLiving,
                           double otherExpenses)
{
   return income - (actualTaxes + actualTithe +  actualLiving +
                   otherExpenses);
}

/**********************************************************************
 * Calculating the budget other from the income.
 ***********************************************************************/
double calculateBudgetOther(double income, double budgetLiving,
                           double budgetTithing, double budgetTax)
{
   return income - (budgetLiving + budgetTithing + budgetTax);
}

/**********************************************************************
  * Displaying the text on the screen in two columns. 
 ***********************************************************************/
void display(double income, double budgetLiving, double actualLiving,
             double actualTaxes, double actualTithe, double otherExpenses,
             double actualDifference, double budgetTithing, double budgetTax,
             double budgetOther)
{

   cout << "\n"; // print a empty line.

   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";

   cout << "\t===============" << setw(16) << "==============="
        << setw(16) << "===============" << endl;

   cout << "\tIncome" << setw(11) << "$" << setw(11) << income
        << setw(5) << "$" << setw(11) << income << endl;
   
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << budgetTax
        << setw(5) << "$" << setw(11) << actualTaxes << endl;

   cout << "\tTithing" << setw(10) << "$" << setw(11)
        << computeTithing(income) 
        << setw(5) << "$" << setw(11) << actualTithe << endl;

   cout << "\tLiving" << setw(11) << "$" << setw(11) << budgetLiving
        << setw(5) << "$" << setw(11) << actualLiving  << endl;

   cout << "\tOther" << setw(12) << "$" << setw(11) << budgetOther
        << setw(5) << "$" << setw(11) << otherExpenses << endl;

   cout << "\t===============" << setw(16) << "==============="
        << setw(16) << "===============" << endl;
   
   cout << "\tDifference" << setw(7) << "$" << setw(11) << 0.00
        << setw(5) << "$" << setw(11) << actualDifference << endl;
}

/**********************************************************************
  * This is where the variables are connected to the functions above.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);     // No scientific notation 
   cout.setf(ios::showpoint); // Always shows the decimal point
   cout.precision(2);         // Only shows two decimal points

   cout << "This program keeps track of your monthly budget" << endl;
   cout << "Please enter the following:" << endl;
   
   double income = getIncome();   
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTaxes = getActualTax();
   double actualTithe = getActualTithing();
   double otherExpenses = getActualOther();
   double actualDifference = getActualDifference(income, actualTaxes,
                            actualTithe, actualLiving, otherExpenses);
   double budgetTithing = computeTithing(income);
   double budgetTax = computeTax(income);
   double budgetOther = calculateBudgetOther(income, budgetLiving,
                       budgetTithing, budgetTax);
 
   display(income, budgetLiving, actualLiving, actualTaxes, actualTithe,
           otherExpenses, actualDifference, budgetTithing, budgetTax,
           budgetOther);   

   return 0;
}
