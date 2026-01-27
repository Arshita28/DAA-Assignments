//max subarray problem(divide and conquer method)
#include<iostream>
using namespace std;
int maxcrosssum(int A[],int p,int m,int q){
	int sum=0,leftsum=0;
	for(int i=m;i>=p;i--){
		sum+=A[i];
		leftsum=max(leftsum,sum);
	}
	sum=0;
	int rightsum=0;
		for(int i=m+1;i<=q;i++){
		sum+=A[i];
		rightsum=max(rightsum,sum);
	}
	return rightsum+leftsum;
}
int maxsum(int A[],int p,int q){
	if(p==q)
	return A[p];
	int m=(p+q)/2;
   int maxL=maxsum(A,p,m);
	int maxR=maxsum(A,m+1,q);
	int maxMid=maxcrosssum(A,p,m,q);
	return max(max(maxL,maxR),maxMid);
}
int main(){
	int x;
	cout<<"enter the number of elements you want "<<endl;
	cin>>x;
	int A[x];
	cout<<"enter the elements"<<endl;
	for(int i=0;i<x;i++){
		cin>>A[i];
	}
	cout<<"The max subarray sum is "<<maxsum(A,0,x-1);
	return 0;
}
