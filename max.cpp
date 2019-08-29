#include <iostream>
#include <map>
#include <vector>
using namespace std;
class xx{
	public:
		int n;
		bool operator< (const xx& b) const {
		int x=this->n;
		int y=b.n;
		int x1=this->n;
		int y1=b.n;
		if(x==0||y==0)return x<y;
		while(x1>=10||y1>=10){
			if(x1<10&&y1>=10){
				x=10*x+9;
				y1=y1/10;
			}
			else{
				if(x1>=10&&y1<10){
					y=10*y+9;
					x1=x1/10;
				}
				else{
					x1=x1/10;
					y1=y1/10;
				}
			}
		}
		return x<y;
		}
};

int main(){
	int n;
	cin>>n;
	map<xx , int> m;
	xx d;d.n=0;
	
	vector<int> v;
	for(int i = 0 ; i<n ; i++){
		int x;
		cin>>x;
		xx y;y.n=x;
		m[y]=m[y]+1;
	}
	for(map<xx , int>::iterator it = m.begin() ; it!=m.end() ; ++it){
		int c = (it->first).n;
		int d = it->second;
		for(int i = 0 ; i<d ; i++){
			v.push_back(c);
		}
	}
	for(int i=v.size()-1 ; i>-1 ; i--){
		cout<<v[i];
	}
}