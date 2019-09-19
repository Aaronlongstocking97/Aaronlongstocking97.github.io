/**************************************************
* Program:
*    Test 1, Study for Test
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary:
*    This program will tell the user if he is ready to take the test
************************************************************/

#include <iostream>
using namespace std;

/*************************************************************************
 * promptUser
 *   Takes in the users input and stores it in a variable called 'score' 
 ************************************************************************/
int promptUser()
{
   int score = 0;
   cout << "What was your score on the practice final in percentage points? ";
   cin >> score;

   return score;
}

/*************************************************************************
 * DISPLAY
 *   Passes in the variable 'score' and displays two options. If the user
 *   needs to study more to take his test or if the user is ready.
 ************************************************************************/
void display(int score)
{
   if (score < 85)
      cout << "\tMore studying is required." << endl;
   else if (score >= 85)
      cout << "\tYou are ready to take the test!" << endl;

}

/*************************************************************************
 * MAIN
 *   Calls functions to get a score and display a result 
 ************************************************************************/
int main()
{
   
   int score = promptUser(); 
   
   display(score);

   return 0;
}



