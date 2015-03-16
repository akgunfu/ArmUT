#include "menu.h"							// Including Predefined Menu Functions
#include "operations.h"						// Including Core Operations

int main(){

	bool end = 0;							// End Flag to To Control While-Loop
	int choice;								// Menu Choice by User

	jointList *joints = NULL;				// Setting First Element of List NULL , initialization

	while (!end){
		printMenu(total_joints);			// Printing the Menu
		cin >> choice;						// Getting Input
		cout << "\n\n";
		end = operate(choice, &joints);		// Depending on Input, Perform And Operation and Choose to Continue or Not
	}

	delete joints;							// Releasing Memory Occupied for the Linked List  // Don't Forget to Fix for All Links
}