#include<bits/stdc++.h>
using namespace std;

int findCeil(string &str,char first,int l,int h)
{//smallest char just large from first char
	int idx = l;
	int i = l+1;
 	for(:i<=h;i++){
	if(first<str[i]&&str[i]<str[idx]){
	      idx = i;
 	}
 return idx;
}

void sortedPermutation(string str){
  sort(str.begin(),str.end());
  bool isEnd = false;
  while(!isEnd){
   
   cout<<str<<endl;
   int i;
   for(i=str.size()-2;i>=0;i--) if(str[i]<str[i+1]) break;
   if(i==-1) isEnd=True;
   else{
     ceilidx = findCeil(str,str[i],i+1,str.size()-1);
     swap(str[i],str[ceilidx]);
     sort(str.begin()+1,str.end());
   }
  }
}

int main(){
	string str;
	cin>>str;
	sortedPermutation(str);
}