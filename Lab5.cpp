/////////////////////////////////////////////////////////////////////
// Name: Gilberto Almanza
// Date: 10/14/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Program take patient information and calculates BMI and weight class.
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int patient;
int pCount = 0;
string name;
double convToMeters(double heightCm);
double calcBMI(double weightKg, double heightM);
string classBMI(double BMI);

int main() {

	cout << "How many patients do you want to process today? ";
	cin >> patient;
	if (patient <= 0) {
		cout << "No valid patients. Closing system.";
		return 0;
	}
	cout << " " << endl;
	cout << " " << endl;
	cin.ignore();
	while (pCount < patient){
		cout << "Enter the patient’s name " << "(" << "#" << pCount + 1 << "): ";
		getline(cin, name);
		double weightKg;
		double heightCm;
		cout << "Enter weight in Kilograms: ";
		cin >> weightKg;
		if (weightKg <= 0) {
			cout << "ERROR: The value " << weightKg << " is invalid for weight in kilograms."
				<< "\nProgram ended.";
			return 0;

		}
		cout << "Enter height in centimeters: ";
		cin >> heightCm;
		cin.ignore();
		if (heightCm <= 0) {
			cout << "ERROR: The value " << heightCm << " is invalid for height in centimeters."
				<< "\nProgram ended.";
			return 0;

		}
		double heightM = convToMeters(heightCm);
		double BMI = calcBMI(weightKg, heightM);
		string classification = classBMI(BMI);
		cout << name << "'s BMI is: " << fixed << setprecision(2) << BMI << endl;
		cout << "The BMI classification is " << classification << endl;
		cout << " " << endl;
		cout << " " <<endl;
		pCount++;
	}
	cout << "Thank you for using our system." << endl;
		
	return 0;
}
double convToMeters(double heightCm) {
	return heightCm / 100;
}
double calcBMI(double weightKg, double heightM){
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