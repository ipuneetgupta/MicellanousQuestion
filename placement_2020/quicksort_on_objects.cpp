// Given an array of red, blue and yellow objects, the task is to use an in-place sorting algorithm to sort the array in such a way that all the blue objects appear before all the red objects and all the red objects appear before all the yellow objects.

#include<bits/stdc++.h>
using namespace std;
#define ff(i,n) for(int i=0;i<n;i++)
#define o_p(i,op) for(auto i : op)


int partition(
	vector<string> &strs,
	unordered_map<string,int> &objOrder,
	int l,
	int r
){
  int j = l-1;
  int lastelement = objOrder[strs[r]];
  for(int i=l;i<r;i++){
  	if(objOrder[strs[i]]<=lastelement){
  		j++;
  		swap(strs[i],strs[j]);
  	}
  }
  j++;
  swap(strs[j],strs[r]);
  return j;
}

void quicksort(
	vector<string> &strs,
	unordered_map<string,int> &objOrder,
	int l,
	int r
	)
{
   if (l<r)
   {
      int partitionIdx = partition(strs,objOrder,l,r);
      quicksort(strs,objOrder,l,partitionIdx-1);
      quicksort(strs,objOrder,partitionIdx+1,r);
   }
   return;
}


int main(){
  int n;
  cin>>n;
  string str;
  int order;
  vector<string> strs;
  ff(i,n){
  	cin>>str;
  	strs.push_back(str);
  }
  
  //find unique element
  vector<string> unique_strs;
  ff(i,n){
   if (find(unique_strs.begin(),
   	        unique_strs.end(),strs[i]
   	   )==unique_strs.end()){
       unique_strs.push_back(strs[i]);

   }
  }
  //map the color with res order
  unordered_map<string,int> objOrder;
  ff(i,unique_strs.size()){
  	printf("enter the order of %s\n",unique_strs[i].c_str());
  	cin>>order;
  	objOrder.insert({unique_strs[i],order});
  }

  quicksort(strs,objOrder,0,n-1);
  o_p(i,strs)cout<<i<<" , ";
}