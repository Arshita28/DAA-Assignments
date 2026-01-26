#include<iostream>
using namespace std;
int BinarySearch(int A[],int low,int high,int key){
	if(low<=high){
		int mid=(low+high)/2;
		if(A[mid]==key)
		return mid;
		else if(A[mid]<key)
		return BinarySearch(A,mid+1,high,key);
		else
		return BinarySearch(A,low,mid-1,key);
	}
return-1;
}
int main(){
	int A[]={2,5,8,12,16,23,38,56,72,91};
	cout<<BinarySearch(A,0,9,23);
	return 0;
}
