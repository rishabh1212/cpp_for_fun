#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
	int T ;
	cin>>T;
	int *c=new int[T];
	for(int i=0;i<T;i++){
		vector <string> e ;
		string c;string d="";
		int count=0, a , b;
		cin>>a;//char *a1=new char[a][100];
		map<string , int>m;
		getline(cin,c);
		for(int j=0;j<a;j++){
			getline(cin,c);
			//cout<<c<<endl;
			//m[c]=0;
			e.push_back(c);
		}
		cin>>b;
		getline(cin,c);
		for(int j=b-1;j>-1;j--){
			std::getline(std::cin,c);
			//cout<<c<<endl;
			if(c.compare(d)){
				d=c;
				m[c]++;
				int k=0;
				for(map<string , int>::iterator it = m.begin();it!=m.end();++it){
					if(it->second==0)break;
					else{
						k++;
					}
				}
				if(k==a){
					count++;
					for(k=0;k<a;k++){
						m[e[k]]=0;
					}
				}
			}
		}
		c[i]=count;
		cout<<endl<<"Case #:"<<i+1<<" "<<count;
	}
	
}