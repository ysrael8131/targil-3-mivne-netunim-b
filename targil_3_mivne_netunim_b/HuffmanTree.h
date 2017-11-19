#pragma once
#include <fstream>
#include"HuffmanNode.h"
class HuffmanTree
{

public:
	HuffmanTree();
	~HuffmanTree();
	void encode(string sourceFileName, string destFileName);
	void decode(string sourceFileName, string destFileName);
	int* buildFrequencyTable(string text);
	void buildTree(int n, string letters, string tree);
	void buildTree(int * frequencyTable);
	void buildCodedTabe();
	void encode(char letter, string * codedTable);
	void deleteTree();
};

