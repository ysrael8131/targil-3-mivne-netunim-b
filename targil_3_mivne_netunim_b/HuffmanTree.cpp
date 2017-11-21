#include "HuffmanTree.h"

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
	inFile.open(sourceFileName);//open the input file
	if (!inFile.good())
	{
		cout << "Cannot open file\n";
		return;
	}
	strStream << inFile.rdbuf();
	inFile.close();
	str = strStream.str();
	freqTable = buildFrequencyTable(str);
	buildTree(freqTable);	
	codTable = buildCodedTabe(treeStruct, chars);
	cout << "Huffman code:" << endl;	
	for (int i = 0; i < 256; i++)
	{
		if (codTable[i] != "")
		{
			cout << (char)(i + 1) << ":	" <<  codTable[i] <<endl;
			for (int j = 0; j < freqTable[i]; j++)
			{
				str.replace(str.find((char)(i + 1)), 1, codTable[i]);
			}
		}
	}
	x = log2(chars.size());
	codLen = (x >(int)x) ? x + 1 : x;
	cout << "In the fixed - length code, the number of bits needed per character: " << codLen << endl;	
	cout << "Encoding in fixed-length code requires " <<codLen*str.size() << " bits." << endl;
	cout << "Encoding in Huffman code requires " <<str.size()  << " bits." << endl;	
	cout << "The encoded string is:" << endl;	
	ofstream outFile;
	outFile.open(destFileName);
	if (!outFile.good())
	{
		cout << "Cannot open file\n";
		return;
	}
	outFile << chars.size() << '\n'<<chars<<'\n'<<treeStruct<<'\n'<<str;
	cout << chars.size() << endl;
	cout << chars << endl;
	cout << treeStruct << endl;
	cout << str << endl;
	outFile.close();
}

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

void HuffmanTree::buildTree(int * frequencyTable)
{
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	for (int i = 0; i < 256; i++)
	{
		if (frequencyTable[i] != 0)
		{
			pQueue.push(new HuffmanNode((char)(i + 1), frequencyTable[i]));
		}
	}
	HuffmanNode* Node;
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

