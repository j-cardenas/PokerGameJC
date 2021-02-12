#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "setup.h"



int main()
{
  char answer = '\0'; //To restart game
  do{
	//shows title screen
    setup();


    cout << "\nPress E to end program." << endl; 
    cout << "\nPress any other key to restart."<<endl;
    cin >> answer;
  } while (answer != 'E' && answer != 'e');
}

