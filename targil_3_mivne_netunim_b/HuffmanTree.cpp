/*
Targil 3
isreal rechtshaffer 301790283
raz zorno 36786960
*/
#include "HuffmanTree.h"
#include<stack>
//Builds Table of Frequencies and tree encoding and table encoding
void HuffmanTree::encode(string sourceFileName, string destFileName)
{

	int * freqTable;
	string * codTable;
	stringstream strStream;
	ifstream inFile;
	string str;
	string treeStruct = "";
	string chars = "";
	double x;
	int codLen;
	//open file to read
	inFile.open(sourceFileName);//open the input file
	if (!inFile.good())
	{
		cout << "Cannot open file\n";
		return;
	}
	//read from in file
	strStream << inFile.rdbuf();
	inFile.close();
	str = strStream.str();
	freqTable = buildFrequencyTable(str);
	buildTree(freqTable);
	codTable = buildCodedTabe(treeStruct, chars);
	cout << "Huffman code:" << endl;
	//replace the letters in coded
	for (int i = 0; i < 256; i++)
	{
		if (codTable[i] != "")
		{
			cout << (char)(i + 1) << ":	" << codTable[i] << endl;
			for (int j = 0; j < freqTable[i]; j++)
			{
				str.replace(str.find((char)(i + 1)), 1, codTable[i]);
			}
		}
	}
	x = log2(chars.size());
	codLen = (x > (int)x) ? x + 1 : x;
	cout << "In the fixed - length code, the number of bits needed per character: " << codLen << endl;
	cout << "Encoding in fixed-length code requires " << codLen*str.size() << " bits." << endl;
	cout << "Encoding in Huffman code requires " << str.size() << " bits." << endl;
	cout << "The encoded string is:" << endl;
	//open file to writing
	ofstream outFile;
	outFile.open(destFileName);
	if (!outFile.good())
	{
		cout << "Cannot open file\n";
		return;
	}
	//Writes to a file and outputs to the screen 

	//1.The number of different letters in the text
	//2.different letters in the text
	//3.The tree structure is coded
	//4.The text is coded
	outFile << chars.size() << '\n' << chars << '\n' << treeStruct << '\n' << str;
	cout << chars.size() << endl;
	cout << chars << endl;
	cout << treeStruct << endl;
	cout << str << endl;
	outFile.close();
	delete_tree(root);

}
//build frequency table
int* HuffmanTree::buildFrequencyTable(string text)
{
	int *table = new int[256];
	for (int i = 0; i < 256; i++)
	{
		table[i] = 0;
	}
	for (int i = 0; i < text.length(); i++)
	{
		table[(int)text[i] - 1]++;
	}
	return table;
}
//build tree
void HuffmanTree::buildTree(int * frequencyTable)
{
	//Priority Queue
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	for (int i = 0; i < 256; i++)
	{
		if (frequencyTable[i] != 0)
		{
			pQueue.push(new HuffmanNode((char)(i + 1), frequencyTable[i]));
		}
	}
	HuffmanNode* Node;
	//build tree By algorithm HuffmanNode Code
	while (pQueue.size() != 1)
	{
		Node = new HuffmanNode();
		Node->setpointerL(pQueue.top());
		int f = pQueue.top()->getFrequency();
		pQueue.pop();
		f += pQueue.top()->getFrequency();
		Node->setFrequency(f);
		Node->setpointerR(pQueue.top());
		pQueue.pop();
		pQueue.push(Node);
		root = Node;
	}
}
//build coded tabel
string* HuffmanTree::buildCodedTabe(string & treeStruct, string & chars)
{
	string* table = new string[256];
	for (int i = 0; i < 256; i++)
	{
		table[i] = "";
	}
	codec(root, "", table, treeStruct, chars);
	treeStruct += "1";
	return table;
}
// encoding letters by Huffman code 
void HuffmanTree::codec(HuffmanNode* Node, string cod, string* & table, string & treeStruct, string & chars)
{
	if (cod == ""&&Node->getpointerR() == nullptr)
	{
		table[(int)Node->getStr() - 1] = "1";
		chars += Node->getStr();
		return;
	}
	if (Node->getpointerR() == nullptr)
	{
		table[(int)Node->getStr() - 1] = cod;
		chars += Node->getStr();
		return;
	}
	string cod1 = cod;
	codec(Node->getpointerL(), cod += "0", table, treeStruct += "0", chars);
	codec(Node->getpointerR(), cod1 += "1", table, treeStruct += "1", chars);
}
//Decoding code by The data in file
void HuffmanTree::decode(string sourceFileName, string destFileName)
{
	ifstream inFile;
	ofstream outFile;
	string str[5];
	string* table;
	string str1 = "";
	int i = 0;

	inFile.open(sourceFileName);//open the input file
	if (!inFile.good())
	{
		cout << "Cannot open file\n";
		return;
	}
	//reading from file
	while (!inFile.eof())
	{
		inFile >> str[i];
		i++;
	}
	buildTree(str[1], str[2]);

	table = buildCodedTabe(str1, str1);
	//Write the decrypted code in file
	outFile.open(destFileName);
	if (!outFile.good())
	{
		cout << "Cannot open file\n";
		return;
	}
	cout << "Huffman code:" << endl;
	for (int i = 0; i < 256; i++)
	{
		if (table[i] != "")
			cout << (char)(i + 1) << ":	" << table[i] << endl;
	}
	cout << "The decoded string is: ";
	for (int i = 0; i < str[3].length(); i++)
	{
		str[4] += str[3].at(i);
		for (int i = 0; i < 256; i++)
		{
			if (str[4] == table[i])
			{
				outFile << (char)(i + 1);
				cout << (char)(i + 1);
				str[4] = "";
				break;

			}
		}
	}
	cout << endl;
}
//delete tree
void HuffmanTree::delete_tree(HuffmanNode* root)
{
	if (root == NULL)
		return;
	delete_tree(root->getpointerL());
	delete_tree(root->getpointerR());
	if (root->getpointerL() == NULL&&root->getpointerR() == NULL)
		delete root;
}
//build tree from in the data in file
void HuffmanTree::buildTree(string letters, string tree)
{
	//stack for storage pointer type HuffmanNode* t
	stack<HuffmanNode*> temp;
	root = new HuffmanNode();
	HuffmanNode* p = root;
	for (int i = 0; i < tree.length(); i++)
	{

		if (tree.at(i) == '0')
		{
			HuffmanNode* t = NULL;
			p->setpointerL(new HuffmanNode());
			p->setpointerR(new HuffmanNode());
			t = p->getpointerR();
			temp.push(t);
			p = p->getpointerL();
		}
		if (tree.at(i) == '1'&&p != root)
		{
			p->setStr(letters.front());
			letters.erase(0, 1);
			if (!temp.empty())
			{
				p = temp.top();
				temp.pop();
			}
		}
	}

}



