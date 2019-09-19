/***********************************************************************
* Program:
*    Assignment 14, Functions
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.30 hrs   
*    Actual:     0.40 hrs
*      The hardest part was trying to get the code to compile.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Display the quesiton asked by Peter.
***********************************************************************/
void questionPeter()
{

   cout << "Lord, how oft shall my brother sin against me, and I"
        << " forgive him?" << endl;
   cout << "Till seven times?" << endl;
   
}

/**********************************************************************
* Display the response in the form of an integer.
***********************************************************************/
int responseLord()
{

   return (7 * 70);
}

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
