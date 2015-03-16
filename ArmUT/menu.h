#include <iostream>
#include <stdlib.h>				// A Library, Specially Needed for System() Function

using namespace std;

void printTitle(){				// A Function to Print Title (ASCII characters intended)

	cout << "         ^            |  |                                     \n";
	cout << "        /_\\  |-\\ |\\/| |  | -|-                                   \n";
	cout << "       /   \\ |   |  | |__|  |_                                   \n";
	cout << "                                                                 \n";
	cout << "         ArmUt Version 1.27                                      \n";

}

void printJoints(int total){	// By Using the Total Number of Joints, This Function chooses what to Print and Prints

	switch (total){

	case 0:

		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "_________________________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	case 1:

		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "       ___O___                                                   \n";
		cout << "       |     |                                                   \n";
		cout << "_______|_____|___________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	case 2:

		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "              O                                                  \n";
		cout << "             /                                                   \n";
		cout << "            /                                                    \n";
		cout << "           /                                                     \n";
		cout << "       ___O___                                                   \n";
		cout << "       |     |                                                   \n";
		cout << "_______|_____|___________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	case 3:

		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "              O-------O                                          \n";
		cout << "             /                                                   \n";
		cout << "            /                                                    \n";
		cout << "           /                                                     \n";
		cout << "       ___O___                                                   \n";
		cout << "       |     |                                                   \n";
		cout << "_______|_____|___________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	case 4:

		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "              O-------O                                          \n";
		cout << "             /         \\                                         \n";
		cout << "            /           \\                                        \n";
		cout << "           /             O                                       \n";
		cout << "       ___O___                                                   \n";
		cout << "       |     |                                                   \n";
		cout << "_______|_____|___________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	case 5:

		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "              O-------O                                          \n";
		cout << "             /         \\                                         \n";
		cout << "            /           \\                                        \n";
		cout << "           /             O------O                                \n";
		cout << "       ___O___                                                   \n";
		cout << "       |     |                                                   \n";
		cout << "_______|_____|___________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	case 6:

		cout << "                                                                 \n";
		cout << "                                                                 \n";
		cout << "                                    O                            \n";
		cout << "              O-------O            /                             \n";
		cout << "             /         \\          /                              \n";
		cout << "            /           \\        /                               \n";
		cout << "           /             O------O                                \n";
		cout << "       ___O___                                                   \n";
		cout << "       |     |                                                   \n";
		cout << "_______|_____|___________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	default:

		cout << "                                                                 \n";
		cout << "           O                                                     \n";
		cout << "            \\                                                    \n";
		cout << "             \\                                                   \n";
		cout << "              O-----O    7+ Joints Are                           \n";
		cout << "             / \\   /     Not Necessary.                          \n";
		cout << "            /   \\ /                                              \n";
		cout << "           /     O       If you need it                          \n";
		cout << "       ___O___           Contact Me:                             \n";
		cout << "       |     |             akgunfu@gmail.com                     \n";
		cout << "_______|_____|___________________________________________\n"; cout << "Number of Joints: " << total << endl;
		break;

	}

}

void printMenu(int total_joints){											// Basic Menu Interface

	system("cls");															// Clears the Screens Every Time Called
	system("color 71");														// Changes the Progmram's Color
	printTitle();															// Displays Title
	printJoints(total_joints);												// Display Imaginary Robot with the Number of Total Joints 
	cout << endl;
	cout << "1.Add a Joint                          4.List All Joints             \n";
	cout << "2.Delete a Joint                       5.Final Transformation Matrix \n";
	cout << "3.Update a Joint                       6.Quit                        \n" << endl << endl;
	cout << "Selection : ";

};