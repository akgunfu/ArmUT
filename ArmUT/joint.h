#pragma once

class joint
{

private:
	double rot_angle;			// Rotation Angle in Degrees
	double L_x;					// X component of Link of the Joint
	double L_y;					// Y component of Link of the Joint
	double L_z;					// Z component of Link of the Joint
	char rot_axis;				// The Axis in which Rotation Occurs
	int x;						// X rotation flag , 1 rotates in X, 0 don't rotate in X
	int y;						// Y rotation flag , 1 rotates in Y, 0 don't rotate in Y
	int z;						// Z rotation flag , 1 rotates in Z, 0 don't rotate in Z

public:
	double trans[4][4];			// Transformation Matrix of Given Joint
	void transform();			// Calculates the Transformation Matrix
	void print();				// Prints Some Properties
	void update(double, char, double, double, double);		// Updates data of Joints
	void displayMat();			// A Function to Display Transition Matrix	

	joint(double = 0.0, char = 'x', double = 1.0, double = 0.0, double = 0.0);		// Constructor With Default Parameters
	~joint();					// Deconstructor

};