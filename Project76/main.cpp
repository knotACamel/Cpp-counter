#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Item.h"

                                     //map included in the global scope for its utility across functions.
std::map<std::string, Item> itemMap; //map uses a string for key, and a user defined class Item for values.

using namespace std;

void displayMenu() { //Menu options are only meant to give visual feedback to users representing their available options.
	cout << "==================== Menu ====================" << endl;
	cout << "Option 1: Return frequency for specific item." << endl;
	cout << "Option 2: Print all items bought with frequency." << endl;
	cout << "Option 3: Print histogram - all items with frequencxy." << endl;
	cout << "Option 4: Exit program." << endl;
}

void readInputFile() {
	ifstream inputFile("data.txt");
	string line;
	
	while (getline(inputFile, line)) {             //iterate through to end of file.
		if (itemMap.find(line) != itemMap.end()) { //if line already exists in the map, 
			itemMap[line].incrementFrequency();    //then retrieve value associated with line and call incrementFrequency by 1
		}
		else {                                     //else, 
			itemMap[line] = Item(line, 1);         //Create new key value pair with line being the key, and a newly instantiated item as the value. New Item objects will always begin with a frequency of 1.
		}
	}
	inputFile.close(); //close input file.
}

void writeBackupFile() {
	ofstream outputFile("Frequency.dat");

	for (const auto& pair : itemMap) {                    //iterate through each key value pair in the map.
		outputFile << pair.second.getItemName() << " "    // Write the item's name to the file
				   << pair.second.getFrequency() << endl; // Write the item's frequency and moves to the next line
	}
	outputFile.close();
}

void option1() {
	string userItem;

	cout << "Enter item name" << endl;
	cin >> userItem;

	while (true) { //runs until user enters a valid option or loses the will to keep trying.
		if (itemMap.find(userItem) != itemMap.end()) {        //checks if userItem is in map
			cout << itemMap[userItem].getFrequency() << endl; //if it is, returns frequency of item. 
			break;
		}
		else if (userItem == "q") { //the easy way out. Returns user to menu.
			cout << endl;
			break;
		}
		else { //User feedback for when their item does not exist in the map. 
			cout << "Invalid. Try a different item or enter q to return to menu." << endl;
			cin >> userItem; //retake user input.
		}
	}
}

void option2() {
	for (const auto& pair : itemMap) {             //Iterate through each key value pair in the map.
		cout << pair.second.getItemName() << " "   // Output the item's name
			<< pair.second.getFrequency() << endl; // Output the item's frequency and moves to the next line
	}
}

void option3() {
	for (const auto& pair : itemMap) {                         // Iterate through each key value pair in the map.
		cout << pair.second.getItemName() << " ";              // Output the item's name
		for (int i = 0; i < pair.second.getFrequency(); ++i) { // Iterates through frequency,
			cout << "*";     								   // and prints asterisks equal to frequency
		}
		cout << endl;
	}
}

int main() {
	bool running = true;
	int choice;

	readInputFile();   // Reads the input file, populates a map with the contents
	writeBackupFile(); // Iterates through populated map to create backup file, Frequency.dat

	while (running) {
		displayMenu(); // User feedback, displays all menu options available to user


		cin >> choice;

		switch (choice) {
		case 1:
			option1(); // Gets user defined item name and outputs frequency of item per map
			break;
		case 2:
			option2(); // Prints all items and their frequency in numeric value
			break;
		case 3: 
			option3(); // Prints a histogram including item name and frequency represented by asterisks
			break;
		case 4:        // Exits program.
			running = false; 
			break;
		default:       // User Feedback for when a non valid numeric entry is input. 
			cout << "Invalid, try again." << endl;
		}
		

	}

	return 0;
}