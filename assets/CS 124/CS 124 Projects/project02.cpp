/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*    Asking the user for there monthly income. Once they type that in
*    they will be prompted for a list of other items, that will be
*    displayed in a table. This table will consist of there monthly
*    budget in two groups. There normal budget and there actual budget.
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




   return 0;
}


/**********************************************************************
 * Prompting the user for there budget living expenses.
 ***********************************************************************/
double getBudgetLiving()
{




   return 0;
}


/**********************************************************************
 * Prompting the user for there actual living expenses.
 ***********************************************************************/
double getActualLiving()
{




   return 0;
}


/**********************************************************************
 * Prompting the user for there actual tax withholding.
 ***********************************************************************/
double getActualTax()
{




   return 0;
}


/**********************************************************************
 * Prompting the user for there tithe offering.
 ***********************************************************************/
double getActualTithing()
{




   return 0;
}


/**********************************************************************
 * Prompting the user for there actual other expenses.
 ***********************************************************************/
double getActualOther()
{




   return 0;
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
double computeTithing()
{




   return 0;
}

/**********************************************************************
 * Calculating the actual differences from the income.
 ***********************************************************************/
double getActualDifference()
{




   return 0;
}

/**********************************************************************
 * Calculating the budget other from the income.
 ***********************************************************************/
double calculateBudgetOther()
{




   return 0;
}

/**********************************************************************
 * Displaying the text on the screen in two columns.
 ***********************************************************************/
void display()
{




   
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
   
   double getIncome;
   double getBudgetLiving;
   double getActualLiving;
   double getActualTaxes;
   double getActualTithe;
   double getActualOther;

   // Shows the number of columns and displays the numbers and text
   // on the screen
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   cout << "\tYour monthly income: ";
   cin >> getIncome;
   
   cout << "\tYour budgeted living expenses: ";
   cin >> getBudgetLiving;
   
   cout << "\tYour actual living expenses: ";
   cin >> getActualLiving;
   
   cout << "\tYour actual taxes withheld: ";
   cin >> getActualTaxes;
   
   cout << "\tYour actual tithe offerings: ";
   cin >> getActualTithe;
   
   cout << "\tYour actual other expenses: ";
   cin >> getActualOther;
   
   cout << "\n";
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   
   cout << "\t=============== =============== ===============\n";
   
   cout << "\tIncome" << setw(11) << "$" << setw(11) << getIncome
        << setw(5) << "$" << setw(11) << getIncome << endl;
   
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << 0.00
        << setw(5) << "$" << setw(11) << getActualTaxes << endl;
   
   cout << "\tTithing" << setw(10) << "$" << setw(11) << 0.00
        << setw(5) << "$" << setw(11) << getActualTithe << endl;
   
   cout << "\tLiving" << setw(11) << "$" << setw(11) << getBudgetLiving 
        << setw(5) << "$" << setw(11) << getActualLiving << endl;
   
   cout << "\tOther" << setw(12) << "$" << setw(11) << 0.00
        << setw(5) << "$" << setw(11) << getActualOther << endl;
   
   cout << "\t=============== =============== ===============\n";
   
   cout << "\tDifference" << setw(7) << "$" << setw(11) << 0.00
        << setw(5) << "$" << setw(11) << "0.00" << endl;

   
   return 0;
}
