
#include <iostream>
using namespace std;

#include "voxel.h"
#include "world.h"

/**************************************************************
 * Function: main
 * Purpose: The driver for the program. Creates a world, sets
 *  some Voxels and displays them.
 **************************************************************/
int main()
{
   cout << "Starting Program.\n";

   World *world = new World();

   world->display();  // Because world is a pointer, use the arrow (->)

   // Create a voxel for air
   Voxel air(180, 200, 255, 'A');

   world->setBox(50, 60, 70, air);

   // Create a voxel for grass
   Voxel grass(25, 255, 50, 'G');

   world->setBox(45, 20, 10, grass);

   world->displayBox(50, 60, 70);
   world->displayBox(45, 20, 10);

   delete world; // Always need to deallocate memory when you use the "new"

   cout << "Ending Program.\n";
   return 0;
}
