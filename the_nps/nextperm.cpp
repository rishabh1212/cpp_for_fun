#include <iostream>
#include <map>
#include <deque>
using namespace std;
string nextperm(string a , string b){
	if(a.compare(b)==0){
		return "";
	}
	int max=0,j=0;
	int size=a.size();
	while(j<size){
		if(a[max]<a[j])max=j;
		j++;
	}
	string s = a.substr(0 , max);
	s+=s.substr(max+1 , size-max-1);
	string c=b.substr(1,size-1);
	c=nextperm(s,c);
	if(c.compare("")!=0){
		return c.substr(0,max)+a[max]+c.substr(max+1,size-max-1);
	}
	else{
		return c.substr(0,max-1)+a[max]+c[max-1]+c.substr(max+1,size-max-1);
	}
}
int main(){
	string a,b;
	cin>>a;
	map<char , int>m;
	int n=a.size();
	for(int i=0;i<n;i++){
		m[a[i]]++;
	}
	b=a;int o=0;
	for(map<char , int>::iterator it=(m.begin());it!=m.end();++it){
		char a=it->first;
		int j=it->second;
		o=o+j;
		while(j>0){
			b[n-o+j-1]=it->first;
			j--;
		}
	}
	cout<<b;
	//string c=nextperm(a , b);
	//cout<<c;
}