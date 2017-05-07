#include"header.h"
#define WIDTH 20
int main()
{
	readtxt();
	first();
	follow();
	forTable();
	print_first();
	print_follow();
	cout<<"************************parsing table************************"<<endl;
	int i,j,num,length,k;
	string str;
	vector<string>::iterator it;
	cout<<left;
	cout<<setw(10)<<" ";
	for(i=0;i<vtset.size();i++){
		cout<<setw(WIDTH)<<vtset[i];}
	cout<<endl;
	for(i=0;i<vnset.size();i++){
		cout<<setw(WIDTH/2)<<vnset[i].left;
		for(j=0;j<vtset.size();j++){
			length=0;
			if(!vnset[i].select[vtset[j]]) {
				if(vnset[i].select["#"]){
					k=vnset[i].select["#"]-1;
					if(vnset[i].isFollow(vtset[j])){
					it=vnset[i].right[k].begin();
					cout<<vnset[i].left;
					length+=vnset[i].left.length();
					cout<<"->";
					length+=2;
					for(;it!=vnset[i].right[k].end();it++){
 	                 	cout<<*it<<" ";
    	              	length+=(*it).length();
        	          	length++;
            	  	} }
				}
			}
			else{	
			num=vnset[i].select[vtset[j]]-1;
			cout<<vnset[i].left<<"->";
			length+=2;
			it=vnset[i].right[num].begin();
			length+=vnset[i].left.length();
			for(;it!=vnset[i].right[num].end();it++){
				cout<<*it<<" ";
				length+=(*it).length();
				length++;}
			}			
			cout<<setw(WIDTH-length)<<" ";
		}
		cout<<endl;
	}
	
/*	for(i=0;i<vtset.size();i++) cout<<vtset[i]<<" ";
	cout<<endl;
	map<string,int>::iterator itr;
	for(i=0;i<vnset.size();i++){
		itr=vnset[i].select.begin();
		for(;itr!=vnset[i].select.end();itr++){
			str=itr->first;
			j=itr->second;
			cout<<str<<":"<<j<<" ";}
		cout<<endl;}
*/
//if(vnset[0].isFollow("w")) cout<<"yes"<<endl;
/*	for(i=0;i<vtset.size();i++){
		if(!vnset[0].select[vtset[i]]) {cout<<vtset[i]<<"not in first"<<endl;continue;}
		cout<<vtset[i]<<" "<<vnset[0].select[vtset[i]]<<endl; }*/
	return 0;
}
