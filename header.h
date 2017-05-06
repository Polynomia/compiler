#include <map>
#include<ctype.h>
#include <fstream>
#include<iostream>
#include<string.h>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;
//*******************define the grammar class******************
class grammar
{
public:
	string left;
	vector<vector<string> > right;
	set<string> first;
	set<string> follow;
	map<string, int>select;	
	bool epsilon();
	bool first_e();
	void delete_e();
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

bool grammar::first_e()
{
	set<string>::iterator it;
	it=first.find("#");
	if(it!=first.end()) return true;
	else return false;
}

void grammar::delete_e()
{
	set<string>::iterator it;
	it=follow.find("#");
	if(it==follow.end())return;
	follow.erase(it);
	return;
}

//*****************end define class************************
	map<string,int>dic;//dictionary change string to int
	vector<grammar>vnset;//vector of nonterminal grammars
	vector<string>vtset;
//***************read in the txt***************************
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
				if(x){ 
				vnset[num].right[j].push_back(s2);}
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

//**************************find vtset******************************//
bool isvn(string s)
{
	int i;
	for(i=0;i<vnset.size();i++){
		if(s==vnset[i].left) return true;}
	return false;
}
void delete_e()
{
	vector<string>::iterator it;
	it=find(vtset.begin(),vtset.end(),"#");
	vtset.erase(it);
	return;
}

void get_vt()
{
	int i,j,k;
	vector<string>::iterator it,it1;
	for(i=0;i<vnset.size();i++){
		for(j=0;j<vnset[i].right.size();j++){
			it=vnset[i].right[j].begin();
			for(;it!=vnset[i].right[j].end();it++){
				if(isvn(*it))continue;
				else{
					it1=find(vtset.begin(),vtset.end(),*it);
					if(it1==vtset.end()) vtset.push_back(*it);
					else continue;
				}
			}
		}
	}
}

void forTable()
{
	get_vt();
	delete_e();
}


//************************get the first set of input***************

/*void find_first(int a)
{
	int i,j,size,num;
	vector<string>::iterator it;
	for(j=0;j<vnset[a].right.size();j++){
		it=vnset[a].right[j].begin();
		for(;it!=vnset[a].right[j].end();it++){
			if(!dic[*it]) {vnset[a].first.insert(*it);break;}
			else {
				num=dic[*it];
				if(!vnset[num].epsilon()){
					find_first(num);
					vnset[a].first.insert(vnset[num].first.begin(),vnset[num].first.end());break;}
				else {continue;}
			}
		}
	}
	
}*/


void find_first(int a)
{
	int i,j,size,num;
	set<string>::iterator it1;
	vector<string>::iterator it;
	for(j=0;j<vnset[a].right.size();j++){
		it=vnset[a].right[j].begin();
		for(;it!=vnset[a].right[j].end();it++){
			if(!dic[*it]) {vnset[a].first.insert(*it);
				if(!vnset[a].select[*it]) vnset[a].select[*it]=j; 
				 break;}
			else {
				num=dic[*it];
				if(!vnset[num].epsilon()){
					find_first(num);
					vnset[a].first.insert(vnset[num].first.begin(),vnset[num].first.end());
					for(it1=vnset[num].first.begin();it1!=vnset[num].first.end();it1++)			
					if(!vnset[a].select[*it1]) vnset[a].select[*it1]=j;
					break;}
				else {continue;}
			}
		}
	}
	
}

void first(){
	int i;
	for(i=0;i<vnset.size();i++)
		find_first(i);	
}

//*****************get the follow set of input*******************

void find_follow(int a)
{
	int i,j,num;
	vnset[a].follow.insert("$");
	vector<string>::iterator it,it1;
	string s=vnset[a].left;
	for(i=0;i<vnset.size();i++){
		for(j=0;j<vnset[i].right.size();j++){
			it=find(vnset[i].right[j].begin(),vnset[i].right[j].end(),s);
			if(it==vnset[i].right[j].end())continue;
			else {
				for(;it!=vnset[i].right[j].end();it++){	
				if(it==vnset[i].right[j].end()-1) {
					if(s==vnset[i].left) break;
					find_follow(i);
					vnset[a].follow.insert(vnset[i].follow.begin(),vnset[i].follow.end());break;}
				else{	
					it1=it+1;
					num=dic[*it1];
					if(!dic[*it1])	{vnset[a].follow.insert(*it1);break;}
					vnset[a].follow.insert(vnset[num].first.begin(),vnset[num].first.end());
					if(!vnset[num].first_e()){break;}
					else if(it1++==vnset[i].right[j].end())
						{find_follow(i);
					 	vnset[a].follow.insert(vnset[i].follow.begin(),vnset[i].follow.end()); break; }
						else {continue;}
			}}
			}
		}
	}
}

void follow()
{
	int i;
	for(i=0;i<vnset.size();i++){
		find_follow(i);
		vnset[i].delete_e();
	}
}


