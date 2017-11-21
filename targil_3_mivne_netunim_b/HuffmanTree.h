#pragma once
#include <fstream>
#include"HuffmanNode.h"
class HuffmanTree
{
private:
	HuffmanNode* root;
public: 
	HuffmanTree()
	{
		root = nullptr;
	}
	~HuffmanTree()
	{
		delete root;
	}
	void encode(string sourceFileName, string destFileName);
	void decode(string sourceFileName, string destFileName);
	int* buildFrequencyTable(string text);
	void buildTree(int n, string letters, string tree);
	void buildTree(int * frequencyTable);
	void buildTree(HuffmanNode* root,string&);
	string * buildCodedTabe();
	//void encode(char letter, string * codedTable);
	//void deleteTree();
	void codec(HuffmanNode* Node, string a, string* & table);
	void HuffmanTree::print(HuffmanNode* root);
};

