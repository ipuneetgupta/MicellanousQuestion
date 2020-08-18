#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	string temp(str);
	temp+=str;
	int ans = 0;
	for(int i=1;i<=str.size();i++){
     string t = temp.substr(i,str.size());
     ans+=1;
     if(t==str){
     	break;
     }
	}
	cout<<ans<<endl;
}