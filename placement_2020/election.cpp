#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
    vector<pair<char,int> > map;


	for(int i=0;i<n;i++) map.push_back(make_pair(str[i],0));

	for(int i=0;i<n;i++){

		if (str[i]=='-'){
			continue;
		}
		
        else if(str[i]=='A'){//'a' voter

            for(int j=i-1;j>=0;j--){
            	if(map[j].first=='-') map[j] = make_pair(str[i],i-j);
            	else if(map[j].first=='B'&& map[j].second!=0){
                  if(map[j].second > i-j){
                  	map[j]=make_pair(str[i],i-j);
                  	// cout<<map[j].second<<i-j<<"--"<<endl;
                  }
                  else if(map[j].second == i-j)
                  	map[j]=make_pair('-',1);
                   else break;   
            	}
            	else break;
            	
            }
        }
        else{
        	int j = i+1;
            for(;j<n;j++){
            	if(map[j].first=='A')break;
            	if(map[j].first == '-'&& map[j].second==0){
            		map[j] = make_pair(str[i],j-i);
            	}else break;
            }
            i = j-1;
        }
	}
	int a = 0;
	int b = 0;
    for(int i=0;i<n;i++){
    	if (map[i].first=='A') a += 1;
    	else if(map[i].first=='B') b +=1;
    	// cout<<map[i].first<<map[i].second<<endl;;
    }
    if(a>b)cout<<'A';
    else if(a<b)cout<<'B';
    else cout<<"Coalition government";
}