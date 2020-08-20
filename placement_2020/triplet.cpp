#include <bits/stdc++.h>
using namespace std;

void findTriplet(vector<string> &ans,int *arr,int n){
      sort(arr,arr+n);
      for(int i=n-1;i>=1;i++){
         int k = i-1;
         int j = 0;
         while(j<k){
         	if(arr[i]==arr[j]+arr[k]){
         		string str = to_string(arr[i]) + to_string(arr[j]) + to_string(arr[k]);
         		ans.push_back(str);
         	}
         	else if(arr[i]<arr[j]+arr[k]) j++; 
         	else k--;
         }
      }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
        vector<string> ans;
        findTriplet(ans,arr,n);
        for(auto i : ans){
        	cout<<i<<endl;
        }
        cout<<"---------------------"<<endl;
	}
}