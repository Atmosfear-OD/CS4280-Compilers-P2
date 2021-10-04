/*
 * main.cpp by Pascal Odijk 3/25/2021
 * P2 CS4280 Professor Hauschild
 *
 * This file contains the main function for P2. The project starts by taking input in three different ways: file specification, redirection, or through keyboard input followed by ctrl+d (simulated EOF). 
 * If the user starts the program with ./frontEnd, this will trigger the keyboard input form, ./frontEnd < fileName.ext will trigger redirection, and ./frontEnd fileName will trigger file input. If more than one 
 * argument is encountered, the program will output an error message. This function will then call the function testScanner which is the driver for the project 1 scanner.
 */

#include <iostream>
#include <fstream>
#include "parser.h"
#include "printTree.h"

using namespace std;

int main(int argc, char *argv[]) {
	string fileName;
	ifstream ifile;
	
	if(argc == 1){ // Handles program initialization of ./frontEnd (keyboard) or ./frontEnd < fileName.ext (redirection)
		try {
			string userInput;
			ofstream tempFile;
	
			fileName = "temp.sp2021";
	
			tempFile.open(fileName.c_str());

			while(getline(cin, userInput)) {
				tempFile << userInput << "\n";
			}

			tempFile.close();

		} catch(const ifstream::failure& e){
			cout << "Error file not found\n";
			return 1;
		}

	} else if(argc == 2){ // Handles program initialization of ./frontEnd fileName (read from file)	
		fileName = argv[1];
		fileName.append(".sp2021");

	} else if(argc > 2){ // Error if more than one argument is entered
		cout << "ERROR: Too many arguments\n";
		cout << "USAGE: ./scanner [keyboard input], or ./scanner fileName, or ./scanner < fileName.ext\n";
		return 1;
	}
	
	// Open input file and call testScanner
	ifile.open(fileName.c_str());
	
	// Build tree
	node *parseTree = parser(ifile);

	// Print tree
	printTree(parseTree);

	// Close input file
	cout << "\nNow closing file...\n";
	ifile.close();
		
	return 0;
}
