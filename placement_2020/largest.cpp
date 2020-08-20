#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	priority_queue<int> q;
    for(int i=0;i<n;i++) q.push(arr[i]);
    for(int i=0;i<3;i++){
    	int n = q.top();
    	q.pop();
    	cout<<n<<endl;
    }
    return 0;
}