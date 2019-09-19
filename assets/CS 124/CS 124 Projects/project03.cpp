/***********************************************************************
* Program:
*    Project 03, Monthly Budget
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*     Asking the user for there monthly income. Once they type that in
*    they will be prompted for a list of other items, that will be displayed
*    in a table. This table will consist of there monthly budget in two 
*    groups. There normal budget and there actual budget.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.2 hrs
*      Running testBed and getting all of my code fixed 
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
   double tax;

   cout << "\tYour actual taxes withheld: ";
   cin >> tax;


   return tax;
}


/**********************************************************************
 * Prompting the user for there tithe offering.
 ***********************************************************************/
double getActualTithe()
{
   double tithing;

   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;

   return tithing;
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
 * Calculating the tax from the income by using a tax bracket system.
 ***********************************************************************/
double computeTax()
{



   return 0;
}


/**********************************************************************
 * Calculating the tithing based on the income. 
 ***********************************************************************/
double computeTithing(double income)
{

   double tithe = (income * 0.10);

   return tithe;
}

/**********************************************************************
 * Calculating the budget other from the income.
 ***********************************************************************/
double calculateBudgetOther(double income, double tithe, double budgetLiving) 
{

   double budgetOther = (income - tithe - budgetLiving);


   return budgetOther;
}

/**********************************************************************
 * Calculating the actual differences from the income.
 ***********************************************************************/
double getActualDifference(double income, double tax, double tithing, 
                           double actualLiving, double actualOther) 
{
   
   double dif = (income - tax - tithing - actualLiving - actualOther);
   

   return dif;
}

/**********************************************************************
 * Displaying the text on the screen in two columns.
 ***********************************************************************/
void display(double income, double budgetLiving, double tax, double tithing,
              double actualLiving, double actualOther, double budgetOther, 
              double tithe, double dif)
{
   
   cout << "\n";
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   
   cout << "\t=============== =============== ===============\n";
   
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income
        << setw(5) << "$" << setw(11) << income << endl;
   
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << 0.00
        << setw(5) << "$" << setw(11) << tax << endl;
   
   cout << "\tTithing" << setw(10) << "$" << setw(11) << tithe
        << setw(5) << "$" << setw(11) << tithing << endl;
   
   cout << "\tLiving" << setw(11) << "$" << setw(11) << budgetLiving 
        << setw(5) << "$" << setw(11) << actualLiving << endl;
   
   cout << "\tOther" << setw(12) << "$" << setw(11) << budgetOther
        << setw(5) << "$" << setw(11) << actualOther << endl;
   
   cout << "\t=============== =============== ===============\n";
   
   cout << "\tDifference" << setw(7) << "$" << setw(11) << 0.00
        << setw(5) << "$" << setw(11) << dif << endl;
   
}

/**********************************************************************
 * Displays a table consisting of you monthly income. All numbers are 
 * floated and the table has multiple items for that months income. 
 * There is an actual and a budget category for the monthly income.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);     // No scientific notation
   cout.setf(ios::showpoint); // Always shows the decimal point
   cout.precision(2);         // Only shows two decimals after the integer
   
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   
   double income = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double tax = getActualTax();
   double tithe = computeTithing(income);
   double tithing = getActualTithe();
   double actualOther = getActualOther();
   double budgetOther = calculateBudgetOther(income, tithe, budgetLiving);
   double dif = getActualDifference(income, tax, tithing, actualLiving, actualOther);



   display(income, budgetLiving, tax, tithing, actualLiving, actualOther, budgetOther,             tithe, dif);
   
   return 0;
}
