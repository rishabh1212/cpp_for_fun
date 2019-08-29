#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
void form_table(string test , string pattern , int *F){
	F[0]=0;
	F[1]=0;
	int j;
	int size = pattern.size()+1;
	for(int i = 2 ; i < size ; ){
		j = F[i-1];
		for(;;){
			if(pattern[j]==pattern[i-1]){
				F[i] = j+1;
				i++;
				break;
			}
			if(j==0){
				F[i] = 0;
				i++;
				break;
			}
			j = F[j];
		}
	}
}
void check_pattern(string test , string pattern){
	int *F = new int[pattern.size()];
	form_table(string test , string pattern , F);
	test_size = test.size();
	for(int j = 0 ; j < test_size ; j++){
		if(test[j]==pattern[i]){
			j++;
			i++;
			if(i==m){
				cout<<"found"<<endl;
				return;
			}
		}
		else{ 
			if(i>0){
				i = F[i];
			}
			else{
				j++;
			}
		}
	}
	cout<<"not found"<<endl;

}
int main(){
	string test , pattern;
	cin>>test>>pattern;
	check_pattern(test , pattern , F);
	return 0;
}