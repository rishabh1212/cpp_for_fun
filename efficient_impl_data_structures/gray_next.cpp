#include <iostream>
using namespace std;
string next(string s);
string previous(string c);
string previous(string c){
	if(c.size()==1){
		if(c[0]=='0'){
			return "";
		}
		return "0";
	}
	string s=c.substr(1,c.size()-1);
	if(c[0]=='0'){
		s=previous(s);
		if(s.size()==0){
			return "";
		}
		return "0"+s;
	}
	if(c[0]=='1'){
		s=next(s);
		if(s.size()==0){
			c[0]='0';
			return c;
		}
		return "1"+s;
	}
}
string next(string s){
	if(s.size()==1){
		if(s[0]=='0'){
			return "1";
		}
		return "";
	}
	string c=s.substr(1,s.size()-1);
	if(s[0]=='0'){
		c=next(c);
		if(c==""){
			s[0]='1';
			return s;
		}
		return "0"+c;
	}
	if(s[0]=='1'){
		c=previous(c);
		if(c.size()==0){
			return "";
		}
		return "1"+c;
	}
}
int main(){
	string s;
	cin>>s;
	int i=0;
	string c=s;
	c=next(c);
	while(c.size()!=0){
		int j=1;
		for(int i=c.size()-1;i>=0;i--){
			if(c[i]!=s[i]){
				cout<<i<<endl;
			}
			j=j*2;
		}
		s=c;
		c=next(c);
	}
}