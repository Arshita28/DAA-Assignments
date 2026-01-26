#include<iostream>
using namespace std;
int partition(int A[],int p,int r){
	int i=p-1;
	for(int j=p;j<r;j++){
		if(A[j]<=A[r]){
			i=i+1;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}
void quicksort(int A[],int p,int r){
	if(p<r){
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
int main(){
	int A[]={4, 2, 6, 9, 2 };
	quicksort(A,0,4);
	for(int i=0;i<5;i++)
	cout<<A[i]<<" ";
}
