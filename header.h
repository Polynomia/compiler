#include <map>
#include<ctype.h>
#include <fstream>
#include<iostream>
#include<string.h>
#include <vector>
#include <algorithm>

using namespace std;

class grammar
{
public:
	string left;
	vector<string> right;
	bool epsilon();
//private:
	grammar(){}
	grammar(string s){left=s;}
	~grammar(){}
};

bool grammar::epsilon()
{
	 vector<string>::iterator result = find(right.begin( ), right.end( ), '#' );
	if (result==right.end())
		return false;
	else return true; 
}
