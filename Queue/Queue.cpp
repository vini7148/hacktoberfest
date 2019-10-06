#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;
};

class Queue{
private:
	node *front,*rear;
public:
	Queue():front(NULL),rear(NULL){}
	~Queue(){}

	void Display();
	void Enqueue(int x);
	int Dequeue();
};

void Queue::Enqueue(int x){
	node *t=new node;
	t->data = x;t->next=NULL;
	if(t==NULL) cout<<"Queue Overflow!!\n";
	else{
		if(front==NULL){
			front=rear=t;
		}
		else{
			rear->next = t;
			rear = t;
		}
	}
}

int Queue::Dequeue(){
	int x=-1;
	if(front==NULL) cout<<" Queue Underflow!!\n";
	else{
		node *p=front;
		x=front->data;
		front=front->next;
		delete p;
	}
	return x;	
}

void Queue::Display(){
	node*p=front;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main(){
	Queue Q;
	Q.Enqueue(2);
	Q.Enqueue(45);
	Q.Enqueue(6);
	Q.Enqueue(1);
	Q.Enqueue(89);

	Q.Dequeue();

	Q.Display();
}
