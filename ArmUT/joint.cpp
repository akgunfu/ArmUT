#include <iostream>					// I/O Stream Library , provides useful functions
#include <cmath>					// CMath is Necessary for Sin and Cos Functions in the Matrices
#include <iomanip>					// I/O Manipulation Library to stylize the Outputs

#define pi 3.14159					// Defined Pi to be able to Convert Doubles to Radians

#include "joint.h"					// Including Class File

using namespace std;				// std Namespace need for functions like cout , cin

joint::joint(double rot, char axis, double l_x, double l_y, double l_z)		// A constructor with parameters
{
	rot_angle = rot * pi / 180.0;											// Rotation in Radians
	rot_axis = axis;														// Rotation Axis
	axis == 'x' ? (x = 1, y = 0, z = 0) : (axis == 'y' ? (x = 0, y = 1, z = 0) : (x = 0, y = 0, z = 1));	// Setting Up Axis Flags
	L_x = l_x;								// XYZ Components of The Link Length of The Joint
	L_y = l_y;
	L_z = l_z;

	transform();							// Calculating Transform Matrix Each Time an Object Created
};

void joint::transform(){					// Transformation Matrix  // Note 4th column should be changed soon...

	trans[0][0] = cos((1 - x)*rot_angle);	trans[0][1] = sin((-z)*rot_angle);		
	trans[0][2] = sin((-y)*rot_angle);		trans[0][3] = L_x*(x + (1 - x)*cos(rot_angle)) - sin(rot_angle)*(L_z*y + L_y*z);

	trans[1][0] = sin(z*rot_angle), trans[1][1] = cos((1 - y)*rot_angle);	
	trans[1][2] = sin((-x)*rot_angle);		trans[1][3] = L_y*(y + (1 - y)*cos(rot_angle)) - sin(rot_angle)*(L_z*x - L_x*z);

	trans[2][0] = sin(y*rot_angle), trans[2][1] = sin(x*rot_angle);			
	trans[2][2] = cos((1 - z)*rot_angle);	trans[2][3] = L_z*(z + (1 - z)*cos(rot_angle)) + sin(rot_angle)*(L_x*y + L_y*x);

	trans[3][0] = 0;						trans[3][1] = 0;						
	trans[3][2] = 0;						trans[3][3] = 1;

};

void joint::update(double rot, char axis, double l_x, double l_y, double l_z){		// Update Funtion identical to Constructor with Parameters
																					// Only difference is that constructor only be called when
	rot_angle = rot * pi / 180;														// the object created. But this function can be called
	rot_axis = axis;																// anytime needed.
	axis == 'x' ? (x = 1, y = 0, z = 0) : (axis == 'y' ? (x = 0, y = 1, z = 0) : (x = 0, y = 0, z = 1));	// Setting Up Axis Flags
	L_x = l_x;
	L_y = l_y;
	L_z = l_z;

	transform();

};

void joint::print(){				// Print Function to Print Some Basic Properties

	cout << "\t   Rotation Angle : " << rot_angle / pi << " " << (char) 227 << endl;
	cout << "\t   Rotation Axis  : " << rot_axis << endl;
	cout << "\t   Link Length    : " << "(" << L_x << ", " << L_y << ", " << L_z << ")" << endl << endl << endl;

};

void joint::displayMat(){			// Function to Display Transition Matrix

	for (int row = 0; row < 4; row++){

		cout << "\t";

		for (int column = 0; column < 4; column++){

			cout << internal << setw(6) << fixed << setprecision(3) << trans[row][column] << "\t\t";
		}

		cout << endl;

	}
}

joint::~joint()						// Deconstructor
{
};
