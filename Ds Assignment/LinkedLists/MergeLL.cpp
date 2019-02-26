#include<iostream>
using namespace std;
typedef struct node 
{
	int data;
	
	struct node *next;
} Node;
class Merge
{
	Node *start;
public:
	Merge()
	{
		start=NULL;
	}
	void createLL();
	void addToList(int x);
	void merge(Merge &p1,Merge &p2);
	void display();
	void Free_space(Node *start){
		if(start==NULL)
			return;
		Free_space(start->next);
		delete(start);
	}
	~Merge()
	{
		// struct node* temp=start;
		// while(temp->next!=NULL)
		// {
		// 	temp=temp->next;
		// }

		Free_space(start);

	}
};
void Merge::display()
{
	if(start!=NULL)
	{
		Node *temp=start;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	else
	{
		cout<<"Nothing to display\n";
	}
}
void Merge::merge(Merge &p1,Merge &p2)
{
	Node *first=new Node;
	Node *dummy=first;
	while(p1.start!=NULL && p2.start!=NULL){
		Node *temp=new Node;
		temp->next=NULL;
		if(p1.start->data<p2.start->data){	
		cout<<"In first ";		
			temp->data=p1.start->data;
			dummy->next=temp;
			p1.start=p1.start->next;
		}
		else{
			//cout<<"In Second";
			temp->data=p2.start->data;
			dummy->next=temp;
			p2.start=p2.start->next;

		}
		dummy=dummy->next;
	}
	if(p1.start!=NULL){
		//cout<<"In 1st if";
		cout<<p1.start->data;
		// Node *temp=new Node;
		// temp->next=NULL;
		// temp->data=p1.start->data;
		dummy->next=p1.start;
		cout<<dummy->next->data;
	}
	else{
	//	cout<<"In 2nd if";
		dummy->next=p2.start;	
	}
	//dummy->next=NULL;
	
	this->start=first->next;	
	delete (first);

}
void Merge::addToList(int x)
{
	Node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		Node *curr=start;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=temp;
	}
}
void Merge::createLL()
{
	cout<<"enter the number of terms :"<<endl;
	int numInputs;
	cin>>numInputs;
	while(numInputs--)
	{
		cout<<"enter  polynomial dataicient  : ";
		int data;
		cin>>data;
		addToList(data);
	}
}
int main()
{
	Merge p1,p2,p3;
	p1.createLL();
	p1.display();
	p2.createLL();
	p2.display();
	p3.merge(p1,p2);
	cout<<"The result of of merging is:\n ";
	p3.display();
	system("pause");
	return 0;
}