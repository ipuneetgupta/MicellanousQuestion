#include<bits/stdc++.h>
using namespace std;

void bubblesort(int *arr,int n){
	bool flag = true;
    for(int i=0;i<n-1;i++){
    	for(int j=0;j<=n-i-1;j++){
            if(arr[j]>arr[j+1]){
              swap(arr[j+1],arr[j]);
              flag=false;
            }
    	}
    	if(flag==true)break;
    }
    return;
}

void selectionsort(int *arr,int n){
	for(int i=0;i<n-1;i++){
		int min_idx = i;
		int j;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min_idx]){
				min_idx = j;
			}
		}
		swap(arr[min_idx],arr[i]);
	}
}


void insertionsort(int *arr,int n){
	for(int i=1;i<n;i++){
		int curr = arr[i];
		int j = i-1;
		for(;j>=0;j--){
			if(arr[j]>curr)arr[j+1]=arr[j];
			else break;
		}
		arr[j+1] = curr;
	}
}

int partitionindex(int *arr,int l,int r){
	int j = l-1;
	int pivot = arr[r];
    for(int i=l;i<r;i++){
    	if(arr[i]<pivot){
    		j++;
    		swap(arr[j],arr[i]);
    	}
    }
    j++;
    swap(arr[j],arr[r]);
    return j;
}

void quicksort(int *arr,int l,int r){
	if(l<r){
		int partitionIdx = partitionindex(arr,l,r);
		quicksort(arr,l,partitionIdx-1);
		quicksort(arr,partitionIdx+1,r);
	}
	return;
}

void merge(int *arr,int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1]; int right[n2];
    for(int i=0;i<n1;i++)left[i] = arr[l+i];
    for(int j=0;j<n2;j++)right[j] = arr[m+1+j];
    int i = 0,j = 0,k = l;
    while(i<n1&&j<n2){
       if(left[i]<right[j]){
	       	arr[k] = left[i];
	       	i++;
       }else{
	       	arr[k] = right[j];
	       	j++;
       }
			k++;}
	while(i<n1){
       arr[k]=left[i];
       k++;i++;
	}
	while(j<n2){
		arr[k] = right[j];
		j++;k++;
	}

}

void mergesort(int *arr,int l,int r){
  if(l<r){
  	int mid = (l+r)/2;
  	mergesort(arr,l,mid);
  	mergesort(arr,mid+1,r);
  	merge(arr,l,mid,r);
  }
  return;
}




int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   // bubblesort(arr,n);
   	// selectionsort(arr,n);
   	// insertionsort(arr,n);
   	// quicksort(arr,0,n-1);
   	mergesort(arr,0,n-1);
   for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}