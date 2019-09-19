/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*    To create stub functions for a program that can manage vehicle costs.
*
*    Estimated:  0.3 hrs   
*    Actual:     0.45 hrs
*    The hardest part about this assignment was working on organization.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * A function that keeps track of the devalue
 ***********************************************************************/
float promptDevalue()
{
   return 0.0;
}

/**********************************************************************
 * A function that keeps track of the insurance
 ***********************************************************************/
float promptInsurance()
{
   return 0.0;
}

/**********************************************************************
 * A function that keeps track of the parking
 ***********************************************************************/
float promptParking()
{
   return 0.0;
}

/**********************************************************************
 * A function that keeps track of the mileage
 ***********************************************************************/
float promptMileage()
{
   return 0.0;
}

/**********************************************************************
 * A function that keeps track of the gas
 ***********************************************************************/
float promptGas()
{
   return 0.0;
}

/**********************************************************************
 * A function that keeps track of the repairs 
 ***********************************************************************/
float promptRepairs()
{
   return 0.0;
}

/**********************************************************************
 * A function that keeps track of the tires
 ***********************************************************************/
float promptTires()
{
   return 0.0;
}

/**********************************************************************
 * A function that keeps track of multiple functions
 ***********************************************************************/
void getPeriodicCost(float costPeriodic)
{
   float devalueCost = 0.0;
   float insuranceCost = 0.0;
   float parkingCost = 0.0;

   devalueCost = promptDevalue();
   insuranceCost = promptInsurance();
   parkingCost = promptParking();

   costPeriodic = 0.0;
}

/**********************************************************************
 * A function that keeps track of multiple functions 
 ***********************************************************************/
void getUsageCost(float costUsage)
{
   float mileage = 0.0;
   float gasCost = 0.0;
   float repairsCost = 0.0;
   float tiresCost = 0.0;

   mileage = promptMileage();
   gasCost = promptGas();
   repairsCost = promptRepairs();
   tiresCost = promptTires();

   costUsage = 0.0;
}

/**********************************************************************
 * A function displays based on other functions 
 ***********************************************************************/
void display(float costUsage, float costPeriodic)
{
   cout << "Success\n";
}

/**********************************************************************
 * Keeps track of all other functions and conversions 
 ***********************************************************************/
int main()
{
   float costPeriodic = 0.0;
   float costUsage = 0.0;

   getPeriodicCost(costPeriodic);
   getUsageCost(costUsage);
   display(costUsage, costPeriodic);
   
   return 0;
}
