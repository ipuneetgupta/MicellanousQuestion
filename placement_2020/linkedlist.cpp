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
    
    int midNode(){
    	Node *slow = this->head;
    	Node *fast = this->head;
    	while(fast->next!=NULL&&fast->next->next!=NULL){
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	return slow->data;
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
}