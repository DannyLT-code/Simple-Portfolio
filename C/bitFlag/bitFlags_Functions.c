#include <stdio.h>
#include <math.h>
//
void printMainMenu();
void printLengthsMenu();
void printWeightsMenu();
//
void convert_lengths();
//
void lengthToMetric();
//
void readLengthUS(int* feet, double* inches);
void convert_length_to_metric(int feet, double inches, int* meters, double* centimeters);
void outputLengthMetric(int feet, double inches, int meters, double centimeters);
//
void lengthToUS();
//
void readLengthMetric(int* meters, double* centimeters);
void convert_length_to_us(int meters, double centimeters, int* feet, double* inches);
void outputLengthUS(int meters, double centimeters, int feet, double inches);
//
void convert_weights();
//
void weightToMetric();
//
void readWeightUS(int* pounds, double* ounces);
void convert_weight_to_metric(int pounds, double ounces, int* kilograms, double* grams);
void outpoutWeightMetric(int pounds, double ounces, int kilograms, double grams);
//
void weightToUS();
//
void readWeightMetric(int* kilograms, double* grams);
void convert_weight_to_us(int kilograms, double grams, int* pounds, double* ounces);
void outputWeightUS(int kilograms, double grams, int pounds, double ounces);
//
int getSwitchCase(int userChoice);
//
void clearKeyboardBuffer();

int main(int argc, char* argv[]) {
	int userChoice;
	printMainMenu();
	scanf("%d", &userChoice);
	clearKeyboardBuffer();
	//Do-while infinite loop until userChoice = 0 (Exit).
	do {
		switch (userChoice) {
		case 0:
			//If user inputs 0 it breaks and exits. 
			break;
		case 1:
			convert_lengths();
			printMainMenu();
			userChoice = -1;
			userChoice = getSwitchCase(userChoice);
			break;
		case 2:
			convert_weights();
			printMainMenu();
			userChoice = -1;
			userChoice = getSwitchCase(userChoice);
			break;
		default:
			//Infinite loop until a valid choice (0 - 2) is input. 
			while (userChoice != 0 && userChoice != 1 && userChoice != 2) {
				printf("Error: Invalid choice\nPlease choose from (1, 2, 0):\n");
				scanf("%d", &userChoice);
				clearKeyboardBuffer();
			}
		}
	} while (userChoice != 0);
	//Exits loop and program if user inputs 0.
	printf("User chose to exit.\n");
}

//Prints Main Menu. 
void printMainMenu() {
	printf("1. convert lengths\n");
	printf("2. convert weights\n");
	printf("0. Exit\n");
	printf("Please choose from (1, 2, 0)\n");
}
void printLengthsMenu() {
	printf("1. convert lengths to metric\n");
	printf("2. convert lengths to US\n");
	printf("0. Return to Main Menu\n");
}
void printWeightsMenu() {
	printf("1. convert weights from pounds/ounces to kilograms/grams\n");
	printf("2. convert weights from kilograms/grams to pounds/ounces\n");
	printf("0. Return to Main Menu\n");
}
//
void convert_lengths() {
	int userChoice;
	printLengthsMenu();
	scanf("%d", &userChoice);
	clearKeyboardBuffer();
	do {
		switch (userChoice) {
		case 0:
			break;
		case 1:
			lengthToMetric();
			printLengthsMenu();
			userChoice = -1;
			userChoice = getSwitchCase(userChoice);
			break;
		case 2:
			lengthToUS();
			printLengthsMenu();
			userChoice = -1;
			userChoice = getSwitchCase(userChoice);
			break;
		default:
			while (userChoice != 0 && userChoice != 1 && userChoice != 2) {
				printf("Error: Invalid choice\nPlease choose from (1, 2, 0):\n");
				scanf("%d", &userChoice);
				clearKeyboardBuffer();
			}
		}
	} while (userChoice != 0);

	printf("User chose to go to Main Menu\n");
	return;
}
//
void lengthToMetric() {
	int feet = 0, meters = 0;
	double inches = 0.0, centimeters = 0.0;
	readLengthUS(&feet, &inches);
	convert_length_to_metric(feet, inches, &meters, &centimeters);
	outputLengthMetric(feet, inches, meters, centimeters);
}
void readLengthUS(int* feet, double* inches) {
	int userFeet;
	double userInches;
	printf("Enter feet and inches (separated by a space):\n");
	scanf("%d %lf", &userFeet, &userInches);
	clearKeyboardBuffer();
	while (userFeet < 0 || userInches < 0) {
		printf("Error. Try again\n");
		printf("Enter feet and inches (separated by a space):\n");
		scanf("%d %lf", &userFeet, &userInches);
		clearKeyboardBuffer();
	}
	*feet = userFeet;
	*inches = userInches;
	return;
}
void convert_length_to_metric(int feet, double inches, int* meters, double* centimeters) {
	int userFeet = feet, userMeters = 0;
	double userInches = inches, userCentimeters = 0;
	userInches = userInches / 12;
	userInches = userFeet + userInches;
	userCentimeters = userInches * 0.3048 * 100;
	while (floor(userCentimeters) >= 100) {
		userCentimeters -= 100;
		userMeters++;
	}
	*meters = userMeters;
	*centimeters = userCentimeters;
	return;
}
void outputLengthMetric(int feet, double inches, int meters, double centimeters) {
	printf("%d feet and %.4lf inches converted to %d meters and %.4lf centimeters.\n", feet, inches, meters, centimeters);
	return;
}
//
void lengthToUS() {
	int meters = 0, feet = 0;
	double centimeters = 0.0, inches = 0.0;
	readLengthMetric(&meters, &centimeters);
	convert_length_to_us(meters, centimeters, &feet, &inches);
	outputLengthUS(meters, centimeters, feet, inches);
}
void readLengthMetric(int* meters, double* centimeters) {
	int userMeters;
	double userCentimeters;
	printf("Enter meters and centimeters (separated by a space):\n");
	scanf("%d %lf", &userMeters, &userCentimeters);
	clearKeyboardBuffer();
	while (userMeters < 0 || userCentimeters < 0) {
		printf("Error. Try again\n");
		printf("Enter feet and inches (separated by a space):\n");
		scanf("%d %lf", &userMeters, &userCentimeters);
		clearKeyboardBuffer();
	}
	*meters = userMeters;
	*centimeters = userCentimeters;
	return;
}
void convert_length_to_us(int meters, double centimeters, int* feet, double* inches) {
	int userMeters = meters, userFeet = 0;
	double userCentimeters = centimeters, userInches = 0;
	userCentimeters = userCentimeters / 100;
	userCentimeters = (double)userMeters + userCentimeters;
	userInches = userCentimeters / 0.3048;
	while (floor(userInches) >= 1) {
		userInches -= 1;
		userFeet++;
	}
	userInches = userInches * 12;
	*feet = userFeet;
	*inches = userInches;
	return;
}
void outputLengthUS(int meters, double centimeters, int feet, double inches) {
	printf("%d meters and %.4lf centimeters converted to %d feet and %.4lf inches.\n", meters, centimeters, feet, inches);
	return;
}
//
void convert_weights() {
	int userChoice;
	printWeightsMenu();
	scanf("%d", &userChoice);
	clearKeyboardBuffer();
	do {
		switch (userChoice) {
		case 0:
			break;
		case 1:
			weightToMetric();
			printWeightsMenu();
			userChoice = -1;
			userChoice = getSwitchCase(userChoice);
			break;
		case 2:
			weightToUS();
			printWeightsMenu();
			userChoice = -1;
			userChoice = getSwitchCase(userChoice);
			break;
		default:
			while (userChoice != 0 && userChoice != 1 && userChoice != 2) {
				printf("Error: Invalid choice\nPlease choose from (1, 2, 0):\n");
				scanf("%d", &userChoice);
				clearKeyboardBuffer();
			}
		}
	} while (userChoice != 0);

	printf("User chose to go to Main Menu\n");
	return;
}
//
void weightToMetric() {
	int pounds = 0, kilograms = 0;
	double ounces = 0.0, grams = 0.0;
	readWeightUS(&pounds, &ounces);
	convert_weight_to_metric(pounds, ounces, &kilograms, &grams);
	outpoutWeightMetric(pounds, ounces, kilograms, grams);
	return;
}
//
void readWeightUS(int* pounds, double* ounces) {
	int userPounds;
	double userOunces;
	printf("Enter pounds and ounces (separated by a space):\n");
	scanf("%d %lf", &userPounds, &userOunces);
	clearKeyboardBuffer();
	while (userPounds < 0 || userOunces < 0) {
		printf("Error. Try again\n");
		printf("Enter feet and inches (separated by a space):\n");
		scanf("%d %lf", &userPounds, &userOunces);
		clearKeyboardBuffer();
	}
	*pounds = userPounds;
	*ounces = userOunces;
	return;
}
void convert_weight_to_metric(int pounds, double ounces, int* kilograms, double* grams) {
	int userPounds = pounds, userKilograms = 0;
	double userOunces = ounces, userGrams = 0.0;
	userOunces = userOunces / 16;
	userOunces = userOunces + userPounds;
	userGrams = userOunces / 2.2046;
	while (floor(userGrams) >= 1) {
		userGrams -= 1;
		userKilograms++;
	}
	userGrams = userGrams * 1000;
	*kilograms = userKilograms;
	*grams = userGrams;
	return;
}
void outpoutWeightMetric(int pounds, double ounces, int kilograms, double grams) {
	printf("%d pounds and %.4lf ounces converted to %d kilograms and %.4lf grams.\n", pounds, ounces, kilograms, grams);
}
//
void weightToUS() {
	int kilograms = 0, pounds = 0;
	double grams = 0.0, ounces = 0.0;
	readWeightMetric(&kilograms, &grams);
	convert_weight_to_us(kilograms, grams, &pounds, &ounces);
	outputWeightUS(kilograms, grams, pounds, ounces);
	return;
}
void readWeightMetric(int* kilograms, double* grams) {
	int userKilograms;
	double userGrams;
	printf("Enter kilograms and grams (separated by a space):\n");
	scanf("%d %lf", &userKilograms, &userGrams);
	clearKeyboardBuffer();
	while (userKilograms < 0 || userGrams < 0) {
		printf("Error. Try again\n");
		printf("Enter feet and inches (separated by a space):\n");
		scanf("%d %lf", &userKilograms, &userGrams);
		clearKeyboardBuffer();
	}
	*kilograms = userKilograms;
	*grams = userGrams;
	return;
}
void convert_weight_to_us(int kilograms, double grams, int* pounds, double* ounces) {
	int userKilograms = kilograms, userPounds = 0;
	double userGrams = grams, userOunces = 0.0;
	userGrams = userGrams / 1000;
	userGrams = userGrams + userKilograms;
	userOunces = userGrams * 2.2046;
	while (floor(userOunces) >= 1) {
		userOunces -= 1;
		userPounds++;
	}
	userOunces = userOunces * 16;
	*pounds = userPounds;
	*ounces = userOunces;
	return;
}
void outputWeightUS(int kilograms, double grams, int pounds, double ounces) {
	printf("%d kilograms and %.4lf grams converted to %d pounds and %.4lf ounces.\n", kilograms, grams, pounds, ounces);
	return;
}

int getSwitchCase(int userChoice) {
	scanf("%d", &userChoice);
	clearKeyboardBuffer();
	while (userChoice != 0 && userChoice != 1 && userChoice != 2) {
		printf("Error: Invalid choice\nPlease choose from (1, 2, 0):\n");
		scanf("%d", &userChoice);
		clearKeyboardBuffer();
	}
	return userChoice;
}
//Clears buffer in case of string input.
void clearKeyboardBuffer() {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n' && ch != '\0') {
		scanf("%c", &ch);
	}
}