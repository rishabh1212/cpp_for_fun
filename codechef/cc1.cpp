#include <iostream>
using namespace std;
int check(string s,int i){
	if(i>s.size()-3){
		return i;
	}
	if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o'){
		return check(s,i+2);
	}
	return i;
}
int main(){
	int n;
	cin>>n;
	string s;
	string t;
	cin>>s;
	for(int i=0;i<n;i++){
		int j=check(s,i);
		if(j==i){
			t.push_back(s[i]);
		}
		else{
			t.push_back('*');
			t.push_back('*');
			t.push_back('*');
			i=j;
		}
	}
	cout<<t;
}