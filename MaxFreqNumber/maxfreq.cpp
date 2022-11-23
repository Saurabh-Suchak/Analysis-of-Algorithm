// this code considers no. of elements in array as 15 while the code in readme has n=10

#include <bits/stdc++.h>
using namespace std;


int binarySearch(int array[], int x, int low, int high) {
  
int ans=-1;	
  while (low <= high) {
    
    int mid = low + (high - low) / 2;

    if (array[mid] == x || array[mid]<x)
      {
        ans=mid;
        low=mid+1;
        }
    else 
      {
        high = mid - 1;
    }
    
  }

  return ans;
}



int main(){

 int arr[15];

 for(int i=0;i<15;i++){
    arr[i]=rand()%3;
 }
 cout<<"the array obtained is - "<<endl;
 for(int i=0;i<15;i++){
    cout<<arr[i]<<" ";
 }
cout<<endl;
sort(arr,arr+15);

 cout<<"the array after sorting is - "<<endl;
 for(int i=0;i<15;i++){
    cout<<arr[i]<<" ";
 }

int ending0 = binarySearch(arr,0,0,14);
int ending1 = binarySearch(arr,1,ending0+1,14);

cout<<endl;

cout<<"the index where 0 ends is "<<ending0<<endl;
cout<<"the index where 1 ends is "<<ending1<<endl;

int num0=(ending0!=-1)?ending0+1:0;
int num1=(ending1!=-1)?ending1-ending0:0;
int num2= 15-num1-num0;

cout<<"no of zeroes in array are "<<num0<<endl;
cout<<"no of ones in array are "<<num1<<endl;
cout<<"no of two in array are "<<num2<<endl;

cout<<endl<<"printing the output according to maximum freq element"<<endl;
if(num0>num1 && num0>num2)cout<<"X";
else if(num1>num0 && num1>num2)cout<<"Y";
else cout<<"Z";

}
