#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
	int T;
	map<char,int>m;
	m['a']=1;
	m['e']=2;
	m['i']=3;
	m['o']=4;
	m['u']=5;
	string a;
	vector<string> b;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>a;
		b.push_back(a);
	}
	for(int i=0;i<T;i++){
		char x = b[i][b[i].size()-1];
		if(x=='y'){
			cout<<"Case #"<<i+1<<": "<<b[i]<<" is ruled by nobody."<<endl;
			continue;
		}
		if(m.find(x)!=m.end()){
			cout<<"Case #"<<i+1<<": "<<b[i]<<" is ruled by a queen."<<endl;
			continue;
		}
		else{
			cout<<"Case #"<<i+1<<": "<<b[i]<<" is ruled by a king."<<endl;
		}
		
	}
}