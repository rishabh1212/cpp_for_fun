#include <iostream>
#include <queue>
using namespace std;
int main(){
	string a;
	cin>>a;
	int *b=new int[256];
	int m=a.size();
	for(int i=0;i<256;i++){
		b[i]=-2;
	}
	for(int i=0;i<m;i++){
		b[a[i]]=-1;
	}
	string c;
	cin>>c;
	int n=c.size();
	queue<int> q;
	int h=0;
	vector<int> k;
	for(int i=0;i<n;){
		if(b[c[i]]==-1){
			q.push(i);
			b[c[i]]=i;
			i++;
			h++;
			if(h==m){
				h--;
				int g=q.front();
				q.pop();
				b[c[g]]=-1;
				k.push_back(g);
			}
			continue;
		}
		if(b[c[i]]==-2){
			i++;
			h=0;
			while(!q.empty()){
				q.pop();
			}
			continue;
		}
		if(b[c[i]]>-1){
			i++;
			h=0;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				b[c[x]]==-1;
			}
		}
	}
	int u=k.size();
	for(int i=0;i<u;i++){
		for(int j=k[i];j<k[i]+m;j++){
			cout<<c[j];
		}
		cout<<endl;
	}
}