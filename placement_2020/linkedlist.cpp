#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int d){
		this->data=d;
		this->next = NULL;
	}

};

class LinkedList{
public:
	Node *head;
	LinkedList(){
		this->head = NULL;
	}

	void addFirst(int d){
	  Node *newNode = new Node(d);
      if(this->head==NULL){
      	this->head = newNode;
      }
      else{
      	Node *temp = this->head;
      	this->head = newNode;
      	newNode->next = temp;
      }
	}

	void addLast(int d){
      Node *newNode = new Node(d);
      
      if(this->head == NULL){
      	this->head = newNode;
      	return;
      }

      Node *temp = this->head;
      while(temp->next!=NULL){
          temp = temp->next;	
      }
      temp->next = newNode;
	}

	void addAt(int idx,int d){
		Node *prev = this->head;
        if(idx==1){
        	addFirst(d);
        	return;
        }
        while(idx>2 && prev!=NULL){
        	idx--;
            prev = prev->next;
        }
        Node *newNode = new Node(d);
        Node *temp = prev->next;
        prev->next = newNode;
        newNode->next = temp;
	}

	void removeFirst(){
      if(this->head->next==NULL){
      	this->head = NULL;
      }else{
      	this->head = this->head->next;
      }
	}

	void removeAt(int idx){
	 Node *prev = this->head;
      if(idx==1){
      	removeFirst();
      }else{
      	while(idx>2&&prev!=NULL){
      		idx--;
      		prev = prev->next;
      	}
      	if(prev!=NULL)
      		prev->next = prev->next->next;
      }
	}


	void reversePI(){
	   if (this->head==NULL&&
	   	this->head->next==NULL
	   	) return;

       Node *prev = NULL;
       Node *curr = this->head;
       while(curr!=NULL){
       	Node *nCurr = curr->next;
       	Node *nPrev = curr;
       	curr->next = prev;
       	prev = nPrev;
       	curr = nCurr;
       }
       this->head = prev;
	}

	void reversePR(){
		reverseHelperPR(this->head);
	}

	Node* reverseHelperPR(Node *node){
		if(node==NULL) return NULL;
        if(node->next==NULL)this->head = node;return node;
        Node *returnNode = reverseHelperPR(node->next);
        returnNode->next = node;
        node->next = NULL;
        return returnNode;
	}
    

    int midNode(){
    	if(this->head==NULL) return -1;
    	Node *slow = this->head;
    	Node *fast = this->head;
    	while(fast->next!=NULL&&fast->next->next!=NULL){
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	return slow->data;
    }

    int kthNodeFromEnd(int k){
      Node *slow = this->head;
      while(k>1&&slow->next!=NULL){
      	slow = slow->next;
      	k--;
      }
      if(k>1) return -1;
      Node *fast = this->head;
      while(slow->next!=NULL){
      	fast = fast->next;
      	slow = slow->next;
      }
      return fast->data;
    }

	void display(){
		Node *temp = this->head;
		while(temp!=NULL){
			cout<<temp->data<<" -> ";
			temp = temp->next;
		}
		cout<<"END"<<endl;
	}

};

int main(){

	LinkedList list;
	list.addLast(2);
	list.addFirst(4);
	list.addFirst(5);
	list.addLast(6);
	list.addAt(3,9);
	list.display();
	list.addAt(5,10);
	list.display();
	list.removeFirst();
	list.addFirst(1);
	list.display();
	list.removeAt(6);
	list.display();
	list.removeAt(5);
	list.display();
	list.addAt(5,8);
	list.removeAt(9);
	list.display();
	cout<<list.midNode()<<endl;;
	cout<<list.kthNodeFromEnd(1)<<endl;
	cout<<list.kthNodeFromEnd(3)<<endl;
    cout<<list.kthNodeFromEnd(5)<<endl;
    cout<<list.kthNodeFromEnd(8)<<endl;
	list.display();
    list.reversePI();
    list.display();
    list.reversePR();
    list.display();

}