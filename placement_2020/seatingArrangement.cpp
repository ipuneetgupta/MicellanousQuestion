#include<bits/stdc++.h>
using namespace std;

pair<int,int> availableRow(int *arr,int n,int k,map<int,int> &mp,int idx){
  int cnt =0;
  if(mp[arr[idx]]<k){
      return make_pair(arr[idx],cnt);
  }else{
      while(mp[arr[idx]]>=k){
          idx++;
      }
      if(idx<n){
      cnt+=1;
      return make_pair(arr[idx],cnt);
      }
      else{
        return make_pair(-1,0);

      }
  }
  return make_pair(-1,0);
}


int seatingNotPrefered(int n,int m,int k,int *preferedRow){
  map<int,int> mp;
  int cnt = 0;
  for(int i=0;i<m;i++)mp[i]=0;
  int i=0;
  for(;i<n;i++){
      pair<int,int> rowAndcnt = availableRow(preferedRow,n,k,mp,i);
      if(rowAndcnt.first!=-1){
        cnt+=rowAndcnt.second;
        mp[rowAndcnt.first]++;
      }else{break;}
  }
   return cnt + (n-i);
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int preferedRow[n];
    for(int i=0;i<n;i++){
        cin>>preferedRow[i];
    }
    cout<<seatingNotPrefered(n,m,k,preferedRow)<<endl;
}   