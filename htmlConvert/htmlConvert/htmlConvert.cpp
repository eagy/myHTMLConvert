// Version 0.50/////////////////////////////////////////
// Programmer: Daniel J Eagy////////////////////////////
////////////////////////////////////////////////////////
// this program converts a cpp file to a html file and//
// changes the '<' and '>' to html compatible items so//
// it displays correctly.                             //
////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	//Variable declarations
	ifstream ins;
	ofstream outs;
	char next;
	string fileName;

	cout << "Enter the filename or path of the input file: ";
	cin >> fileName;
	
	if (cin.fail()) {
		cout << "INVALID INPUT\n";
		exit(1);
	}

	ins.open(fileName);
	
	cout << "Enter the filename or path of the output file: ";
	cin >> fileName;

	if (cin.fail()) {
		cout << "INVALID INPUT\n";
		exit(1);
	}

	outs.open(fileName + ".html");

	outs << "<pre>\n";
	ins.get(next);

	while (!ins.eof()) {
		if (next == '<') {
			outs << "&lt;";
		}
		else if (next == '>') {
			outs << "&gt;";
		}
		else
			outs.put(next);
		ins.get(next);
	}
	outs << "</pre>";


	ins.close();
	outs.close();
    return 0;
} // end main
//////////////////////////////////////////////////

void 