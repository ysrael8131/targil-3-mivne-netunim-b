#pragma once
#include<iostream>
#include<string>
#include <sstream>
#include<algorithm>
#include"tables.h"
#include<vector>
#include<queue>
using namespace std;
class HuffmanNode
{
	friend class compareNode;
private:
	char str;
	int frequency;
	HuffmanNode* right;
	HuffmanNode* left;
public:
	HuffmanNode(char s,int f):str(s),frequency(f){}
	~HuffmanNode();
};

class compareNode
{
public:
	bool operator()(HuffmanNode* const & n1, HuffmanNode* const & n2)
	{
		return n1->frequency > n2->frequency;
	}
};

