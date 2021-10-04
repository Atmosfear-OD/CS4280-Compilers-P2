The FSA table is located in scanner.cpp
The driver function is located in testScanner.cpp

To compile the project:
1. run 'make frontEnd' 
2. the program can be invoked three different ways: file specification (no extension), file redirection (with extension), and keyboard input
	file: ./frontEnd fileName
	redirection: ./frontEnd < fileName.ext
	keyboard: ./frontEnd 	// User then types input and presses ctrl+d to simulate EOF

Note: More than one argument will output an error message and instructions to properly run program
Note: Program output is not printed to a file
