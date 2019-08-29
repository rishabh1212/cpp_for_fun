#include <iostream>
#include <list>
#include <limits.h>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
class graph_g{
public:
	int v ; vector< vector<int> > adj;
	graph_g(int n){
		this->v = n;
		vector<int > m;
		for(int i=0;i<n+1;i++){
			adj.push_back(m);
		}
	}
	~graph_g(){}
	void add_edge(int m , int n){
		(this->adj)[m].push_back(n);
	}
};
int main(){
	int v,e;
	cin>>v>>e;
	graph_g g(v) ;
	for(int i = 0 ; i < e ; i++){
		int m,n;
		cin>>m>>n;
		g.add_edge(m,n);
	}
	queue<queue<int> > y;
	for(int i = 1; i < v+1 ; i++){
		queue<int > y1;
		for(int j = 0 ; j < g.adj[i].size() ; j++){
			y1.push(g.adj[i][j]);
		}
		y.push(y1);
	}

	int *visited = new int[v+1];
	int *point = new int[v+1];
	for(int i = 1 ; i < v+1 ; i++){
		visited[i] = 0;
		point[i] = 0;
	}
	visited[0] = -1;
	deque<int> q;
	q.push_back(1);
	int x ;
	while(!y.empty()){
		while((y.front()).empty()){
			y.pop();
			if(y.empty()){
				break;
			}
		}
		if(y.empty()){
			break;
		}
		x = y.front().front();
		q.push_back(x);
		while(!q.empty()){
			x = q.back();
			while(!y.empty()){
				if((y.front()).empty()){
					y.pop();
				}
			
				else{
					if(y.front().front()==x){
						y.front().pop();
						if((y.front()).empty()){
							y.pop();
						}
						break;
					}
					break;
				}
			}
			visited[x] = 1;
			if(point[x]<g.adj[x].size()){
				if(visited[g.adj[x][point[x]]]!=1){
					q.push_back(g.adj[x][point[x]]);
					visited[g.adj[x][point[x]]] = 1;
				}
				else{
					cout<<"cycle"<<endl;
				}
				point[x]++;
			}
			else{
				q.pop_back();
			}
		}
		while(!y.empty()){
			if(y.front().empty()){
				y.pop();
				continue;
			}
			if(visited[y.front().front()]==1){
				y.pop();
			}
			else{
				break;
			}
		}
	}

}