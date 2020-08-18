#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		string temp1(str.begin()+i,str.end());
		string temp2(str.begin(),str.begin()+i);
		string temp = temp1 + temp2;
		cout<<temp<<endl;
	}
}