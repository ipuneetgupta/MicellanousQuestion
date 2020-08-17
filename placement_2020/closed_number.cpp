
// An array of size N and an integer x will be given and
// the task was to find the closest element to x in the array.
// In case of a tie, print the greater number.


#include<bits/stdc++.h>
#include<map>
using namespace std;

struct cmp{
	template<typename T>
	bool operator()(const T &a,const T &b)const
	{
		if (a.second == b.second){
			return a.first > b.first;
		}
		return a.second < b.second;
	}
};

bool cmp1(pair<int,int> &a,pair<int,int> &b){
	if(a.second==b.second){
       return a.first>b.first;
	}

	return a.second<b.second;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int m;
    cin>>m;
    map<int,int> mp;
    for(int i=0;i<n;i++){
    	mp.insert(make_pair(arr[i],abs(m-arr[i])));
    }
    map<int,int>:: iterator it;
    cout<<"Original Map ::"<<endl;
    for(it = mp.begin();it!=mp.end();it++){
    	cout<<(*it).first<<" , "<<(*it).second<<endl;
    }
    vector<pair<int,int> > dup(mp.begin(),mp.end());
    sort(dup.begin(),dup.end(),cmp1);
    cout<<"After Sorting using vector And Comparator Fucntion::"<<endl;
    for(auto it:dup){
    	cout<<it.first<<" , "<<it.second<<endl;
    }
    cout<<"Sorting Through Inbuilt Set::"<<endl;;
    set<pair<int,int> , cmp> st(mp.begin(),mp.end());
    for(auto it : st){
    	cout<<it.first<<" , "<<it.second<<endl;
    }
    cout<<"Sorting Through Multimap ::"<<endl;
    
}