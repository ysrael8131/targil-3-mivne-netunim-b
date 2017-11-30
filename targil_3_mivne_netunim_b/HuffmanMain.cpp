/*
Targil 3
isreal rechtshaffer 301790283
raz zorno 36786960
*/
#include <list>
#include "HuffmanTree.h"
using namespace std;

//void priorityQueueExapmple();

int main()
{
	int choice;
	int size = 0;
	string text = "", temptext = "";
	string inputname, outputname, str;
	stringstream strStream;
	ifstream inFile;
	ofstream outfile;
	double x;
	int codeLen, BT1, BT2 = 0;
	HuffmanTree * tree = new HuffmanTree();
	system("color 9f");
	do
	{
		cout << "Please enter 1 to encode a text file\n";
		cout << "Please enter 2 to decode a text file\n";
		cout << "Please enter 3 to exit\n";
		cin >> choice;
		switch (choice)
		{
			//Coding of information
		case 1:
			cout << "Enter a text file" << endl;
			cin >> inputname;
			cout << "Enter a name for output file" << endl;
			cin >> outputname;
			tree->encode(inputname, outputname);
			break;
		

		   //Decryption of information
		case 2:
			cout << "Enter an encoded file" << endl;
			cin >> inputname;
			cout << "Enter a name for decoded file" << endl;
			cin >> outputname;
			tree->decode(inputname, outputname);
			break;
		
		}
	} while (choice != 3);
	return 0;
}



