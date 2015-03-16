#include "joint.h"				// Including Joints class
#include "matrix.h"				// Including Some Matrix Operations

struct jointList {				// A linked List Structure Intented to Store Consecutive Joints' Data

	joint node;					// Data Part. Joint Class instances will be held here.
	int index;					// Count or Index of the Node in the Linked List.
	jointList* next;			// A pointer pointing its own Structure to make links with Same Kind of Structure

};

int total_joints = 0;			// Global Variable to Store Total Number of Joints

void createJoint(double, char, double, double, double, jointList**);
void removeJoint(int, jointList**);
void updateIt(int, jointList**);
void listJoints(jointList**);

void addJoint(jointList** List){							// Joint Add Menu

	double rot, L_x, L_y, L_z;								// Joint Class Parameters to Use to Create A Joint
	char axis;

	cout << "\t\t --ADD JOINT--\n\n";

	if (*List == NULL)										// If list is Empty, The Joint We will Add First is the Base
		cout << "\tBase Joint\n" << endl;
	else
		cout << "\t" << total_joints << ".Joint\n" << endl;			// Otherwise Joint number-whatever

	cout << "Rotation Angle    :   ";								// Getting parameters
	cin >> rot;
	cout << "Rotation Axis     :   ";
	cin >> axis;
	cout << "Link Length (xyz) :   ";
	cin >> L_x >> L_y >> L_z;

	createJoint(rot, axis, L_x, L_y, L_z, List);					// Sending Parameters and A Linked List Pointer to Create Function

	cout << "\nJoint Has Been Created Succesfully..." << endl;
	getchar(); getchar();

};

void deleteJoint(jointList** List){							// Joint Delete Function

	int select;												// Selection Number will store the number of the joint we want to delete

	cout << "\t\t --DELETE JOINT--\n\n";

	listJoints(List);										// First List All the Joints We Have

	if (!total_joints){
		cout << "\nNo Joints to delete. Terminating..." << endl;
		return;
	}

	cout << "Index of the Choice : (Base can not be Deleted)" << endl;
	cin >> select;												// Get which Joint is wanted to be deleted

	removeJoint(select, List);									// Send Them to Another Remove Function

	cout << "\nJoint Has Been Deleted Succesfully..." << endl;	// After previous functions closes succesfully, say the operation is done.
	getchar(); getchar();													// To prevent Insta-clear
};

void updateJoint(jointList** List){				// Update Function

	int selected;

	cout << "\t\t --UPDATE JOINT--\n\n";

	listJoints(List);							// Listing the Options

	if (!total_joints)
		return;

	cout << "\nIndex of the Choice :  ";
	cin >> selected;							// Selection

	updateIt(selected, List);					// Update

	cout << "\nJoint Has Beed Updated Succesfully." << endl;	//Done
	getchar(); getchar();
};

void finalMatrix(jointList* List){

	cout << "\t\t --FINAL TRANSITION MATRIX--\n\n";

	if (total_joints == 0){
		cout << "No Joints Found...\n";
		getchar(); getchar();
		return;
	}

	else if (total_joints == 1){

		List->node.displayMat();
		cout << "\nMatrix Derived from 1 Joint...\n\n";
		getchar(); getchar();
		return;

	}

	else {

		double result[4][4] = { { 1, 0, 0, 0, },						// Initial Result Matrix
								{ 0, 1, 0, 0, },
								{ 0, 0, 1, 0, },
								{ 0, 0, 0, 1  }
							};

		jointList* traverse = new jointList;							// Memory Allocation For Traverse Pointer
		traverse = List;												// Setting List to the Traverse Pointer

		while (traverse != NULL){

			transMult(result, traverse->node.trans, result);			// Result Will be the Next Matrix Multiplied by the Result Itself
			traverse = traverse->next;

		}

		delete traverse;												// Memory Deallocation

		displayMatrix(result);
		cout << "\nMatrix Derived from " << total_joints << " Joints...\n\n";
		getchar(); getchar();
	}

}

void createJoint(double rot, char axis, double L_x, double L_y, double L_z, jointList** List){		// Creating a Joint and adding it to the List

	joint temp(rot, axis, L_x, L_y, L_z);								// Initializing a variable by Using Constructor

	if (*List == NULL){													// If the List Empty or rather Creating the First Joint -Base-

		(*List) = new jointList;										// Create a Pointer to Start Pointing some Objects
		(*List)->index = 0;												// Initial Index of 0
		(*List)->next = NULL;											// Next element set to NULL
		(*List)->node = temp;											// Copying the Data to Node Part

		total_joints++;													// Number of Joints Increases

		return;															// When Invoked Finish This Function
	}

	jointList *traverse = new jointList;
	traverse = *List;

	while (traverse->next != NULL)
		traverse = traverse->next;

	jointList *next_p = new jointList;									// Allocation for new element
	next_p->node = temp;
	next_p->next = NULL;
	next_p->index = (traverse->index + 1);								// Simply Previous Count + 1

	traverse->next = next_p;											// Setting the new Element to Next Place
	traverse = traverse->next;
	traverse->next = NULL;												// And getting List Pointer to the end of The List After Adding New Joint

	total_joints++;														// Number of Joints Increases

};

void removeJoint(int select, jointList** List){							// Removing Joint's Node in List


	jointList *traverse = new jointList;								// Traverse pointer makes us traverse the List without modifying the real Head Pointer
	traverse = *List;

	if (-1>select || select>total_joints){

		if (select == -1)
			return;

		cout << "Invalid Number. Try again. (-1 to Main Menu)   :  ";   // So, Someone Entered an Invalid Number
		cin >> select; removeJoint(select, List);
	}

	while (traverse->index != select && traverse->next != NULL){	// If the Index of the Next Joint is What We Were Looking For
		if (traverse->next->index == select){						// Link the Target's Previous to the Target's Next 
			// So Now the Target has No Connection with List
			traverse->next = ((traverse->next->next) == NULL) ? NULL : traverse->next->next;
			total_joints--;
			// don't forget to delete when debugging
			break;
		}

		traverse = traverse->next;										// New Joint After the Deleted One
	}

	traverse = traverse->next;

	while (traverse != NULL){											// Set Next Joints Indexes to count-1 

		traverse->index--;
		traverse = traverse->next;
	}

	delete traverse;													// Deallocate Memory
};


void updateIt(int select, jointList** List){

	double angle, x, y, z;
	char axis;

	jointList *traverse = new jointList;
	traverse = *List;

	if (-1>select || select>total_joints){

		if (select == -1)
			return;

		cout << "Invalid Number. Try again. (-1 to Main Menu)   :  ";   // So, Someone Entered an Invalid Number
		cin >> select; updateIt(select, List);							// Recursively Do This Step Over and Over
	}

	cout << "\nNew Rotation Angle    :   "; cin >> angle;
	cout << "New Rotation Axis     :   "; cin >> axis;
	cout << "New Link Length (xyz) :   "; cin >> x >> y >> z;


	while (traverse->index != select && traverse->next != NULL){		// Call Joint Class's Speacial Public Update Function
		if (traverse->next->index == select){							// For Selected Joint and Re-assing Values
			traverse->next->node.update(angle, axis, x, y, z);
			break;
		}
	}

	delete traverse;													// Memory Deallocation
}

void listJoints(jointList** List){										// Listing All the Joints


	jointList *traverse = new jointList;
	traverse = *List;

	if (traverse == NULL){												// No List, No Joints To Find
		cout << "No joints found." << endl;
		return;
	}

	cout << total_joints << " joints found." << endl << endl;			// Total Found

	while (traverse != NULL){
		if (traverse->index == 0)										// Index 0 : Base
			cout << "\tBase Joint :\n" << endl;
		else
			cout << "\t" << traverse->index << ". Joint :\n" << endl;

		traverse->node.print();											// Print Function in Joint Class to print some properties
		traverse = traverse->next;
	}
	cout << "\n\n";

	(total_joints == 1) ? cout << total_joints << " Joint Listed Succesfully...\n" : cout << total_joints << " Joints Listed Succesfully...\n";

	delete traverse;													// Memory Deallocation
};

bool operate(int choice, jointList** List){

	switch (choice) {													// Depending on the Choice Perform One of These
	case 1:
		addJoint(List);
		break;
	case 2:
		deleteJoint(List);
		break;
	case 3:
		updateJoint(List);
		break;
	case 4:
		listJoints(List);
		getchar(); getchar();
		break;
	case 5:
		finalMatrix(*List);
		break;
	case 6:
		return true;
	default:
		cout << "Invalid entry. Try again : (6 to quit)" << endl;		// Recursively Getting People To Avoid Invalid Keys
		cin >> choice;
		operate(choice, List);
		break;
	}

	return false;
};