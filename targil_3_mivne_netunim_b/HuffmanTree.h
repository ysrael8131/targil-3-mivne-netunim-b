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
		delete_tree(root);
	}
	void encode(string sourceFileName, string destFileName);
	void decode(string sourceFileName, string destFileName);
	int* buildFrequencyTable(string text);
	void buildTree(string letters, string tree);
	void buildTree(int * frequencyTable);
	void delete_tree(HuffmanNode*);
	string * buildCodedTabe(string & treeStruct, string & chars);
	//void encode(char letter, string * codedTable);
	//void deleteTree();
	void codec(HuffmanNode* Node, string cod, string* & table,string & treeStruct,string & chars);
	

};



