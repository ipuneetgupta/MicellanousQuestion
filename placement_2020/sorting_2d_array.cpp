#include<bits/stdc++.h>
using namespace std;
#define ff(i,r,n) for(int i=r;i<n;i++)

bool cmp(const vector<int> &a ,const vector<int> &b){
     if (a[1]<b[1]){
        return true;
     }
     return false;
}

//pancake sorting
//its simple reverse
//step1 find max idx of current window size
//step3 flip(arr,maxidx)
//step2 flip(arr,currWindow-1) in currewindow == n
def flip(int *arr,int idx){
	int s = 0;
	for(int i=0;i<idx;i++){
       swap(arr[i],arr[i+1]);
       idx--;
	}
}


int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> >arr(n,vector<int>(m))(0);
	cout<<"Original Array::"<<endl;
    ff(i,0,n){
    	ff(j,0,m){
    		cin>>arr[i][j];
    		cout<<arr[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout<<"AFTER Sorting ::"<<endl;
    sort(arr.begin(),arr.end(),cmp);
    ff(i,0,n){
    	ff(j,0,m){
    		cout<<arr[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout<<"pancake sorting::"<<endl;

}