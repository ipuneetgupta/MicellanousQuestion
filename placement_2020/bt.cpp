#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	Node *left;
	Node *right;
	int data;
	Node(int d){
		this->left = NULL;
		this->right = NULL;
		this->data = d;
	}
};

class BinaryTree{
    Node *root;
    BinaryTree(){
    	this->root = NULL;
    }
    Node* add(Node *node,int d){
    	if(this->root==NULL)return new Node(d);

    	else if(node->data>d){
             node->left = add(node->left,d);
    	}else{
             node->right = add(node->right,d);
    	} 
    	return node;
    }

    bool* search(Node *root,int d){
         if(root->data==d) return true;
         else if(root->data>d)
         	return search(root->left,d);
         else return search(root->right,d);
         return false;
    }
    Node *remove(Node *root,int d){
     if(root==NULL) return NULL;
     if(root->data>d){
         root->left = remove(root->left,d);
         return root;
     }
     else if(root->data<d){
     	root->rigth = remove(root->right,d);
     	return root;
     }
     else{
     	if(root->data==val){
     		if(root->left==NULL&&root->rigth==NULL){
     			delete root;
     			return NULL;
     		}
     		else if(root->left!=NULL&&root->right==NULL){
                   Node *temp = root->left;
                   delete root;
                   return temp;
     		}
     		else if(root->left==NULL&&root->right!=NULL){
                   Node *temp = root->right;
                   delete root;
                   return temp;
     		}else{
               Node *temp = root->right;
               while(temp->left!=NULL){
               	temp = temp->left;
               }
               root->data = temp->data;
               root->right = remove(node->right,temp->data);
               return node;
     		}
     	}
     }
    }
    Node *buildArray(int *arr,int s ,int e){
    	if(s>=e)return NULL:
    		int mid = (s+e)/2;
    	Node *node = new Node(arr[mid]);
    	node->left = buildArray(arr,s,mid-1);
        node->right = buildArray(arr,mid+1,e);
    	    return node;
    	    }
};

int main(){

}