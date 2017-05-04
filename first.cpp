#include"header.h"
void find_first(int a);
int main()
{
	readtxt();
	int i,j,size;
			
	set<string>::iterator it;
	for(i=0;i<vnset.size();i++){
		find_first(i);
		it=vnset[i].first.begin();
		for(;it!=vnset[i].first.end();it++){
				cout<<*it<<" ";}
		cout<<endl;	
	}
	return 0;
}


void find_first(int a)
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
	
}
