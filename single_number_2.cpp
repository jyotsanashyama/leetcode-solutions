#include<iostream>
#include <math.h>
using namespace std;

int find(int nums[], int n){
    long long int sinNum=0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<n;j++){
            int mask=(nums[j]>>i);
            if((mask & 1) ==1){
                count++;
            }
        }
        if(count%3!=0){
            sinNum+=pow(2,i);
        }
    }
    return (int)sinNum;
}

int main(){
int n;
cout<<"Enter size of array: ";
cin>>n;
int nums[n];
cout<<"Enter the elements of array: "<<endl;
for(int i=0;i<n;i++){
    cin>>nums[i];
}
int ans=find(nums,n);
cout<<"The number that appeared only once is: "<<ans<<endl;
return 0;
}
