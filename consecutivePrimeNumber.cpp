//consecutivePrimeNumber[codevita-2019].cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define limit 12000000000
vector<ll> prime;

void precompute(ll n){
	prime.push_back(2);
	for(ll i = 3;i<=n;i+=2){
		bool flag = true;
		ll stp = sqrt(i) + 1;
		for(vector<ll> :: iterator it = prime.begin();it!=prime.end();it++){
			if(*it>=stp) break;
            if (i%(*it)==0){
            	flag=false;
            	break;
            }
		}

		if (flag==true) prime.push_back(i);
	}
}

int main(){
  ll n;
  cin>>n;
  precompute(n);
  ll cnt = 0;
  ll sum = 0;
  for(vector<ll> :: iterator it = prime.begin();it!=prime.end();it++){
    	sum += (*it);
      if(find(prime.begin(),prime.end(),sum)!=prime.end() && sum != 2) cnt++;
  }
  cout<<cnt<<endl;
}