#include<bits/stdc++.h>
using namespace std;

int getdistinctAscii(string str){
	int count = 0;
	bool isvisited[26] = {false};
	for(int i=0;i<str.size();i++){
		if(!isvisited[str[i]-'a']){
          isvisited[str[i]-'a'] = true;
          count+=int(str[i]);
		}
	}
	return count;
}

void printSameWord(vector<string> &str){
	unordered_map<int,vector<string> >mp;
	for(int i =0;i<str.size();i++) {
		int key = getdistinctAscii(str[i]);
		mp[key].push_back(str[i]);
	}
	//print same value
    for(auto it : mp){
    	for(auto v : it.second){
    		cout<<v<<" ";
    	}
    	cout<<endl;
    }
}

int main(){
	int n;
	cin>>n;
	vector<string> str;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
        str.push_back(s);
	}
    printSameWord(str);
}