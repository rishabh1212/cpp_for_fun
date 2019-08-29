#include <iostream>
#include <vector>
#include <string>
using namespace std;
void gray(vector<string >& v,int n){
	if(n==1){
		v.push_back("0");
		v.push_back("1");
		return;
	}
	vector<string > v1;
	gray(v1,n-1);
	for(int i=0;i<v1.size();i++){
		v.push_back("0"+v1[i]);
	}
	for(int i=v1.size()-1;i>-1;i--){
		v.push_back("1"+v1[i]);
	}
}
int main(){
	int n;
	cin>>n;
	vector<string> v;
	gray(v,n);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}