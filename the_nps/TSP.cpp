#include <iostream>
#include <vector>
using namespace std;

vector <int> path(int **a , int i , int *s){
	int min=-1;
	vector<int> v1;
	for(int j=1;j<n && j!=i;j++){
		if(s[j]==-1){
			continue;
		}
		s[i]=-1;
		vector<int> v = path(a,j,s);
		if(min==-1||min>v.back()+a[i][j]){
			min = v.back()+a[i][j];
			v1=v.pop_back();
			v1.push_back(i).push_back()
		}
		s[i]=i;
	}
	return v1;
}
int main(){
	int n;
	cin>>n;
	int a[n][n];
	int s[n];
	for(int i=0;i<n;i++){
		s[i]=i;
		for(int j=i;j<n;j++){
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	}
	int cost[n];
	cost[0]=-1;
	int min_i = -1;
	int min = -1;
	vector < vector <int> > path;
	for(int i=1;i<n;i++){
		path.push_back(s_path(a,i,s));
		if(min == -1 || min > a[0][i]+path.back().back()){
			min_i = i;
			min = a[0][i]+path.back().back();
		}
	}
	cout<<min<<endl;
}