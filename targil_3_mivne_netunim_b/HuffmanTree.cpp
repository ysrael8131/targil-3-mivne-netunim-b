#include "HuffmanTree.h"



HuffmanTree::HuffmanTree()
{
}


HuffmanTree::~HuffmanTree()
{
}
void HuffmanTree::encode(string sourceFileName, string destFileName)
{
	int * table;
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
	table = buildFrequencyTable(str);
	buildTree(table);

}
int* HuffmanTree::buildFrequencyTable(string text)
{
	int* table = new int[256];
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
	char a;
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	for (int i = 0; i < 256; i++)
	{
		if (frequencyTable[i] != 0)
		{
			pQueue.push(new HuffmanNode((char)(i + 1), frequencyTable[i]));
		}
	}

	
}

