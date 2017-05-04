#include <map>
#include<ctype.h>
#include <fstream>
#include<iostream>
#include<string.h>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

class grammar
{
public:
	string left;
	vector<vector<string> > right;
	bool epsilon();
	grammar(){}
	grammar(string s){left=s;}
	~grammar(){}
};

bool grammar::epsilon()
{
	 vector<string>::iterator result;
	int i;
	for(i=0;i<right.size();i++){
	result=find(right[i].begin(),right[i].end(),"#");
	if (result!=right[i].end())
		return true;
	 }
	return false;
}


	map<string,int>dic;
	vector<grammar>vnset;
void readtxt(){	
	ifstream ifile;
	ifile.open("input.txt");
	vector<string> right1;
	string str,s,s2;
	char line[512];
	int size,i,num,j;
	while(ifile.getline(line,512)){
		str=string(line);
		size=str.length();
		for(i=0;i<size;i++){
			if(isblank(str[i])) continue;
			if(str[i]=='-') break;
			s+=str[i];
		}
		if(!dic[s]){
			vnset.push_back(s);
			dic[s]=vnset.size()-1;
		}
		num=dic[s];
		j=0;
		int x=1;
		while(true){
		if(str[i]=='-'||str[i]=='>'||isblank(str[i])) i++;
		else break;}
		vnset[num].right.push_back(right1);
		for(;i<size;i++){
			if(str[i]=='|') {
				if(x) vnset[num].right[j].push_back(s2);
				s2.clear();right1.clear();j++;
				vnset[num].right.push_back(right1);
				continue;}
			if(isblank(str[i])){
				s2.clear();continue;	
			}
			x=1;
			s2+=str[i];
				if(isblank(str[i+1])) 
			{vnset[num].right[j].push_back(s2);
				x=0;}
		}
		vnset[num].right[j].push_back(s2);
		s2.clear();
		right1.clear();
		s.clear();
}}

