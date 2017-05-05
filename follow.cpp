#include"header.h"
void find_follow(int a);
int main(){
readtxt();
first();
find_follow(0);
int i;
set<string>::iterator it;
for(i=0;i<vnset.size();i++){
find_follow(i);
vnset[i].delete_e();
it=vnset[i].follow.begin();
	for(;it!=vnset[i].follow.end();it++)
cout<<*it<<" ";
cout<<endl;
}
return 0;
}

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

