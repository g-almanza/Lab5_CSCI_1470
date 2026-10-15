/////////////////////////////////////////////////////////////////////
// Name: Gilberto Almanza
// Date: 10/14/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Program reads patient information from a file
// and calculates BMI and weight class.
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int patient;
int pCount = 0;
string name;
double convToMeters(double heightCm);
double calcBMI(double weightKg, double heightM);
string classBMI(double BMI);

int main() {

	ifstream inFile;
	inFile.open("patients.txt");
	inFile >> patient;

	if (patient <= 0) {
		cout << "No valid patients. Closing system.";
		return 0;
	}
	cout << " " << endl;
	cout << " " << endl;

	while (pCount < patient) {
		string firstName;
		string lastName;
		inFile >> firstName >> lastName;
		name = firstName + " " + lastName;

		double weightKg = 0;
		double heightCm = 0;

		inFile >> weightKg;
		if (weightKg <= 0) {
			cout << "ERROR: The value " << weightKg << " is invalid for weight in kilograms."
				<< "\nProgram ended.";
			return 0;

		}

		inFile >> heightCm;
		if (heightCm <= 0) {
			cout << "ERROR: The value " << heightCm << " is invalid for height in centimeters."
				<< "\nProgram ended.";
			return 0;

		}
		double heightM = convToMeters(heightCm);
		double BMI = calcBMI(weightKg, heightM);
		string classification = classBMI(BMI);
		cout << "(#" << pCount + 1 << ") " << name << "'s BMI is: " << fixed << setprecision(2) << BMI << endl;
		cout << "The BMI classification is " << classification << endl;
		cout << " " << endl;
		cout << " " << endl;
		pCount++;
	}
	cout << "Thank you for using our system." << endl;

	return 0;
}
double convToMeters(double heightCm) {
	return heightCm / 100;
}
double calcBMI(double weightKg, double heightM) {
	return weightKg / (heightM * heightM);
}
string classBMI(double BMI) {
	if (BMI < 18.5) {
		return "Underweight";
	}
	else if (BMI < 25) {
		return "Normal";
	}
	else if (BMI < 30) {
		return "Overweight";
	}
	else {
		return "Obese";
	}
}