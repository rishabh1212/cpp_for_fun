/*
	minimum heap data structure implementation
*/
#include <iostream>
#include <vector>
using namespace std;
class minheap{
	vector<int> v;
public:
	minheap(int i){
		v.push_back(-1);
	}
	int getmin(){
		if(v.size()==1){
			return -1;
		}
		return v[1];
	}
	void insert(int i){
		v.push_back(i);
		int j=v.size()-1;
		while(v[j/2]>v[j]&&j!=1){
			int x=v[j/2];
			v[j/2]=v[j];
			v[j]=x;
			j=j/2;
		}
	}
	void delete_min(){
		int x=v[v.size()-1];
		v.pop_back();
		v[1]=x;
		int j=1;
		while(1){
			if(2*j>=v.size()){
				break;
			}
			if(2*j<v.size()){
				if(v[j]>v[2*j]){
					int x=v[j];
					v[j]=v[2*j];
					v[2*j]=x;
					j=2*j;
					continue;
				}
				else{
					break;
				}
			}
			if(2*j+1<v.size()){
				if(v[j]>v[2*j+1]){
					int x=v[j];
					v[j]=v[2*j+1];
					v[2*j+1]=x;
					j=2*j+1;
					continue;
				}
				else{
					break;
				}
			}
		}
	}
};
int main(){

}