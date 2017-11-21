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
	string * buildCodedTabe(string & treeStruct, string & chars);
	//void encode(char letter, string * codedTable);
	//void deleteTree();
	void codec(HuffmanNode* Node, string cod, string* & table,string & treeStruct,string & chars);
	void buildTree(HuffmanNode* root, string &a);
	void print(HuffmanNode* root);

};



