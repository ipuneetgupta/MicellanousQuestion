#include<bits/stdc++.h>
using namespace std;

bool checkPallindrome(string str){
    string res = str;
    reverse(res.begin(),res.end());
    if (res==str) return true;
    else return false;
}

int countPallindrom(string str){
    int count = 0;
    for(int i=0;i<str.size();i++){
        for(int j=1;j<=str.size()-i;j++){
          string sub = str.substr(i,j);
          if(checkPallindrome(sub)){
             count+=1;
          }
        }
    }
    return count;
}

int main(){
    string str;
    cin>>str;
    cout<<countPallindrom(str)<<endl;
}