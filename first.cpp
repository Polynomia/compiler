#include"header.h"

int main()
{
	map<string,int>dic;
	vector<grammar>vnset;
	
	ifstream ifile;
	ifile.open("input.txt");
	set<string> right1;
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
				if(x) vnset[num].right[j].insert(s2);
				s2.clear();right1.clear();j++;
				vnset[num].right.push_back(right1);
				continue;}
			if(isblank(str[i])){
				s2.clear();continue;	
			}
			x=1;
			s2+=str[i];
				if(isblank(str[i+1])) 
			{vnset[num].right[j].insert(s2);
				x=0;}
		}
		vnset[num].right[j].insert(s2);
		s2.clear();
		right1.clear();
		s.clear();
	}
set<string>::iterator it;
for(j=0;j<vnset.size();j++){
cout<<"grammer "<<j<<":"<<endl;
for(i=0;i<vnset[j].right.size();i++){
it=vnset[j].right[i].begin();
for(;it!=vnset[j].right[i].end();it++)
cout<<*it<<" ";
cout<<endl;
}}
	cout<<vnset[0].left<<endl;
	cout<<vnset[1].left<<endl;
	for(j=0;j<vnset.size();j++)
		if(vnset[j].epsilon()) cout<<"grammer "<<j<<" has #"<<endl;
	return 0;

			
}
