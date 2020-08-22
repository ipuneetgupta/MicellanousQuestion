#include<bits/stdc++.h>
using namespace std;

void fibopatter(int n){
	int a = 0 , b = 1 , c = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=i;j++){
			if(i==0&&j==0)cout<<b<<' ';
			else
			{c = a + b;
			a = b;
			b = c;
			cout<<c<<" ";
           }
		}
		cout<<endl;
	}
}

int binomialCoef(int n,int k){
	int res = 1;
	for(int i=0;i<min(k,n-k);i++){
		res*= (n-i);
		res/= (i+1);
	}
	return res;
}


void pascalTriangle(int n){
  for(int i = 0;i < n;i++){
  	for(int j=0;j<=i;j++){
  		cout<<binomialCoef(i,j)<<" ";
  	}
  	cout<<endl;
  }
}


int main(){
	int n;
	cin>>n;
	pascalTriangle(n);
}