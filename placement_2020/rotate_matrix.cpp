#include <iostream>
using namespace std;

void rotatematrix(int **arr,int m,int n){
 int left=0,right=n-1,top=0,bottom=m-1;
 while(left<=right&&top<=bottom){
 	int prev = arr[top+1][left];
 	for(int i=left;i<=right;i++){
         int temp = arr[top][i];
         arr[top][i] = prev;
         prev = temp;
 	}
 	top++;
 	for(int i=top;i<=bottom;i++){
      int temp = arr[i][bottom];
      arr[i][right] = prev;
      prev = temp;
 	}
 	right--;
 	if(bottom>=0){
 	for(int i=right;i>=left;i--){
      int temp = arr[bottom][i];
      arr[bottom][i] = prev;
      prev = temp;
 	}}
	bottom--;
	if(left<n){
 	for(int i=bottom;i>=top;i--){
 		int temp = arr[i][left];
 		arr[i][left] = prev;
 		prev = temp;
 	}}
 	left++;
 }

}

void display(int **arr,int m,int n){
	for(int i =0;i<m;i++){
		for(int j = 0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int m,n;
	cin>>m>>n;
	int **matrix = new int*[m];
	for(int i=0;i<m;i++){
		matrix[i] = new int[n];
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
   
   //rotate
   display(matrix,m,n);
   rotatematrix(matrix,m,n);
   display(matrix,m,n);
		
}