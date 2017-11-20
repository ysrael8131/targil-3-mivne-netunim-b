#include "HuffmanTree.h"

void HuffmanTree::encode(string sourceFileName, string destFileName)
{
	int * freqTable;
	string * codTable;
	stringstream strStream;
	ifstream inFile;
	string str;
	inFile.open(sourceFileName);//open the input file
	if (!inFile.good())
	{
		cout << "Cannot open file\n";
		return;
	}
	strStream << inFile.rdbuf();
	str = strStream.str();
	freqTable = buildFrequencyTable(str);
	buildTree(freqTable);
	codTable = buildCodedTabe();

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
		cout << (int)text[i] - 1 << "	" << table[(int)text[i] - 1] << endl;
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
		cout << pQueue.top()->getFrequency();
	}
	root = pQueue.top();
}

string* HuffmanTree::buildCodedTabe()
{
	string* table = new string[256];
	for (int i = 0; i < 256; i++)
	{
		table[i] = "";
	}
	codec(root,"", table);
	return table;
}

void HuffmanTree::codec(HuffmanNode* Node, string a, string* & table)
{
	if (a==""&&Node->getpointerR()==nullptr)
	{
		table[(int)Node->getStr() - 1] = "0";
		return;
	}
	if (Node->getpointerR()==nullptr)
	{
		table[(int)Node->getStr() - 1] = a;
	}
	return codec(Node->getpointerL(), a += "0", table);
	return codec(Node->getpointerR(), a += "1", table);
}

