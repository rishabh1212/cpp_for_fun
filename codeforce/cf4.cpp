#include <iostream>
#include <map>
#include <queue>
using namespace std;
class edge{
	int a,b;
public:
	edge(c,d){
		a=c;
		b=d;
	}
};
int parent(int i,int *c){
	if(c[i]==-1){
		return i;
	}
	return parent(c[i],c);
}
void unite(int i,int j,int *c){
	if(parent(i,c)==parent(j,c)){
		return;	
	}
	c[parent(i,c)]=parent(j,c);
	return;
}
int main(){
	int n;
	cin>>n;
	int *b=new int[n];
	int *c=new int[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
		c[i]=-2;
	}
	edge *e=new int[n];
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		e[i]=edge(x,y);
	}
	queue<int > w;
	for(int i=0;i<n-1;i++){
		if(b[e[i].x-1]==0&&b[e[i].y-1]==0){
			w.push(i);
			c[e[i].x-1]=c[e[i].y-1]=-1;
		}
	}
	while(!w.empty()){
		int x=w.back();
		w.pop();
		unite(e[i].x-1,e[i].y-1,c);
	}
	for(int i=0;i<n;i++){
		if(c[i]==-1){
			cout<<i+1<<endl;
		}
	}
}