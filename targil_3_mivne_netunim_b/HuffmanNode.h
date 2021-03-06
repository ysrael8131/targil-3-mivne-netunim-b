/*
Targil 3
isreal rechtshaffer 301790283
raz zorno 36786960
*/
#pragma once
#include<iostream>
#include<string>
#include <sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cmath>
using namespace std;
//class A node in a tree
class HuffmanNode
{
	friend class compareNode;
private:
	char str;
	int frequency;
	HuffmanNode* Right;
	HuffmanNode* Left;
public:
	HuffmanNode(char s = {}, int f = 0, HuffmanNode*r = nullptr, HuffmanNode*l = nullptr) :str(s), frequency(f) { Right = nullptr; Left = nullptr; }
	int getFrequency() { return this->frequency; }
	char getStr() { return this->str; }
	void setStr(char s) { str = s; }
	HuffmanNode*getpointerR() { return Right; }
	HuffmanNode*getpointerL() { return Left; }
	void setpointerR(HuffmanNode* r) { Right = r; }
	void setpointerL(HuffmanNode* l) { Left = l; }
	void setFrequency(int freq) { frequency = freq; }
	
};

class compareNode
{
public:
	bool operator()(HuffmanNode* const & n1, HuffmanNode* const & n2)
	{
		return n1->frequency > n2->frequency;
	}
};

