#include"header.h"

int main()
{
	map<string,int>dic;
	vector<grammar>vnset;
	
	ifstream ifile;
	ifile.open("input.txt");
	
	string str,s;
	char line[512];
	int size,i;
	while(ifile.getline(line,512)){
		str=string(line);
		size=str.length();
		for(i=0;i<size;i++){
			if(isblank(str[i])) continue;
			if(s[i]=='-') break;
			s+=s[i];
		}
		if(!dic[s]){
			vnset.push_back(s);
			dic[s]=vnset.size();
		}
}

	cout<<vnset[0].left<<endl;
	return 0;
			
}
