#include <iostream>
using namespace std;
class big_number{
	string a;int size;
public:
	big_number(string s){
		if(s.size()==0){
			cout<<"null"<<endl;
		}
		if(s[0]=='0'&&s.size()!=1){
			cout<<"dont **** waste space you *****"<<endl;
		}
		a=s;
		size=a.size();
	}
	big_number operator+ (const big_number &b) &{
		if((b.a).size()==0){
			cout<<"dont waste my time"<<endl;
		}
		string e;
		if(size==b.a.size){
			int c=0;
			for(int i=size-1;i>-1;i--){
				int d=(a[i]+b.a[i]-96+c)%10;
				c=(a[i]+b.a[i]-96+c)/10;
				e.push_back(d+48);
			}
			string f;
			for(int i=e.size()-1;i>-1;i--){
				f.push_back(e[i]);
			}
			big_number s(f);
			return s;
		}
		if(size<b.size){
			int c=0;
			for(int i=size-1;i>-1;i--){
				int d=(a[i]+b.a[i]-96+c)%10;
				c=(a[i]+b.a[i]-96+c)/10;
				e.push_back(d+48);
			}
			for(int i=b.size-size-1;i>-1;i--){
				int d=(a[i]-48+c)%10;
				c=(a[i]-48+c)/10;
				e.push_back(d+48);
			}
			string f;
			for(int i=e.size()-1;i>-1;i--){
				f.push_back(e[i]);
			}
			big_number s(f);
			return s;
		}
		if(size>b.size){
			int c=0;
			for(int i=b.size-1;i>-1;i--){
				int d=(a[i]+b.a[i]-96+c)%10;
				c=(a[i]+b.a[i]-96+c)/10;
				e.push_back(d+48);
			}
			for(int i=b.size-size-1;i>-1;i--){
				int d=(a[i]-48+c)%10;
				c=(a[i]-48+c)/10;
				e.push_back(d+48);
			}
			string f;
			for(int i=e.size()-1;i>-1;i--){
				f.push_back(e[i]);
			}
			big_number s(f);
			return s;
		}
	}
};
int main(){

}