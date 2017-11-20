#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
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
	//frequencyTable *table = new frequencyTable[256];
	//string kidud[256];
	//string binaryCode;
	//double x;
	//int codeLen, BT1, BT2 = 0;
	HuffmanTree * tree = new HuffmanTree();
	//priorityQueueExapmple();

	system("color 9f");
	do
	{
		cout << "Please enter 1 to encode a text file\n";
		cout << "Please enter 2 to decode a text file\n";
		cout << "Please enter 3 to exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter a text file" << endl;
			cin >> inputname;
			cout << "Enter a name for output file" << endl;
			cin >> outputname;
			tree->encode(inputname, outputname);
		//	cout << text << endl;

		//	table = tree->buildFrequencyTable(text, size); // Build frequency table

		//	cout << "Frequency table. size = " << size << endl;
		//	for (int i = 0; i < size; i++)
		//		cout << table[i].ltr << " " << table[i].frq << endl;

		//	tree->buildTree(table, size);  // Build Huffman tree

		//	tree->buildTableCode(kidud, 256);  // Build code for each character
		//	for (int i = 0; i < 256; i++)
		//		if (kidud[i] != "")
		//		{
		//			int j = 0;
		//			cout << "The code of letter " << (char)i << " is " << kidud[i] << endl;
		//			for (; j < size && (table[j].ltr[0] != (char)i); j++);
		//			BT2 += table[j].frq * kidud[i].length();
		//		}

		//	x = log10(size) / log10(2);
		//	codeLen = (x >(int)x) ? x + 1 : x;
		//	BT1 = codeLen * text.length();
		//	cout << "B(T) not compressed = " << BT1 << endl;
		//	cout << "B(T) compressed = " << BT2 << endl;
		//	cout << "Huffman saving % = " << (double)(BT1 - BT2) / BT1*100.0 << "%\n";

		//	binaryCode = tree->encode(kidud, text);
		//	cout << binaryCode << endl;
		//	outfile.open(outputname);
		//	if (outfile.is_open())
		//	{
		//		outfile << binaryCode << endl;
		//		outfile.close();
		//	}
		//	else
		//		cout << "Unable to open file";
		//	break;
		//case 2:
		//	cout << "Enter an encoded file" << endl;
		//	cin >> inputname;
		//	cout << "Enter a name for decoded file" << endl;
		//	cin >> outputname;

		//	inFile.open(inputname);//open the input file
		//	if (!inFile.good())
		//	{
		//		cout << "Cannot open file\n"; break;
		//	}
		//	inFile >> binaryCode;
		//	inFile.close();
		//	string text = tree->decode(binaryCode);
		//	cout << "The encoded text is: " << binaryCode << endl;
		//	cout << "The decoded text is: " << text << endl;
		//	outfile.open(outputname);
		//	if (outfile.is_open())
		//	{
		//		outfile << text << endl;
		//		outfile.close();
		//	}
		//	else cout << "Unable to open file";

		}
	} while (choice != 3);
	return 0;
}

//class Job
//{
//private:
//	string job;
//	int pri;
//public:
//	Job(string j, int p) : job(j), pri(p) {}
//	string getJob() { return job; }
//	int getPri() { return pri; }
//};
//
//class Less
//{
//public:
//	bool operator()(Job j1, Job j2)
//	{
//		return j1.getPri() < j2.getPri();
//	}
//};
//
//void priorityQueueExapmple()
//{
//	priority_queue<Job, vector<Job>, Less> q;
//
//	q.push(Job("Shopping", 2));
//	q.push(Job("Playing music", 1));
//	q.push(Job("Making homework", 4));
//	q.push(Job("Washing the dishes", 3));
//
//	while (!q.empty())
//	{
//		cout << q.top().getPri() << " " << q.top().getJob() << endl;
//		q.pop();
//	}
//	cout << "**************************************************\n";
//}