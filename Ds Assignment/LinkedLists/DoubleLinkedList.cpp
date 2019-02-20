#include<iostream>
using namespace std;
typedef struct n 
{
	int data;
	struct n *next;
	struct n *prev;
}Node;
void print(Node *);
class DLL
{
	Node *start;
	public:
	DLL()
	{
		start=NULL;
	}
	void traverse()
	{
		Node *curr;
		for(curr=start;curr!=NULL;curr=curr->next)
		{
			cout<<curr->data<<" ";
		}
		cout<<endl;
	}
	void insert_begin(int n)
	{
		Node *curr=start,*temp;
		temp=new Node;
		temp->data=n;
		if(start!=NULL)
		{
			temp->next=curr;
			curr->prev=temp;
			temp->prev=NULL;
		}
		else
		{ 
			temp->next=NULL;
			temp->prev=NULL;
		}
		start=temp;
	}	
	void insert_last(int n)
	{
		Node *curr,*temp;
		temp=new Node;
		temp->data=n;
		temp->next=NULL;
		if(start!=NULL)
		{
			curr=start;	   
			while(curr->next!=NULL)
			{
				curr=curr->next;	
			}
			curr->next=temp;
			temp->prev=curr;
		}
		else
		{
			temp->prev=NULL;
			start=temp;	   
		}
		
	}
	void insert_after(int sele,int ele)
	{
		Node *curr=start,*temp;
		if(curr!=NULL)
		{
			while(curr!=NULL && curr->data!=sele)
			{
				curr=curr->next;
			}
			if(curr!=NULL)
			{
				temp=new Node;
				temp->data=ele;
				temp->next=curr->next;
				curr->next->prev=temp;
				temp->prev=curr;
				curr->next=temp;	
			}
			else
			{
				cout<<sele<<" not found\n";
			}
		}
		else
		{
			cout<<"no list\n";
		}
	}
	void insert_before(int sele,int ele)
	{
		Node *curr=start,*temp;
		if(curr!=NULL)
		{
			if(curr->data==sele)
			{
				temp=new Node;
				temp->data=ele;
				temp->next=start;
				temp->prev=NULL;
				curr->prev=temp;
				start=temp;
				return;
			}	 
			while(curr->next!=NULL && curr->next->data!=sele)
			{
				curr=curr->next;
			}	 
			if(curr->next!=NULL)
			{
				temp=new Node;
				temp->data=ele;
				temp->next=curr->next;
				temp->prev=curr;
				temp->next->prev=temp;
				curr->next=temp;
						
			}
			else
			{
				cout<<sele<<" not found\n";
			}
		}
		else
		{
			cout<<"no list\n";
		}
	}
	
	void traverse_back()
	{
		Node *curr;
		for(curr=start;curr->next!=NULL;curr=curr->next)
		{
			;
		}
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->prev;
		}
		cout<<endl;
	}
    
	int delete_begin()
	{
		int x=-1;
		Node *curr,*temp;
		if(curr!=NULL)
		{
			temp=start;
			x=temp->data;
			start=start->next;
			curr=start;
			if(start!=NULL)				
				curr->prev=NULL;
			delete temp;	
		}
		return x;
	}
	int delete_last()
	{
		int x=-1;
		Node *curr=start,*temp;
		if(curr!=NULL)
		{
			if(curr->next==NULL)
			{
				x=curr->data;
				start=NULL;
				delete curr;
				return x;
			}
			while(curr->next!=NULL)
			{
				curr=curr->next;	
			}	 
			curr->prev->next=NULL;
			x=curr->data;
			delete curr;
		}
		return x;
	}
	void delete_spec(int ele)
	{
		Node *curr=start,*temp;
		if(curr!=NULL)
		{
			if(curr->data==ele)
			{
				temp=curr;
				start=temp->next;
				curr=start;
				curr->prev=NULL;
				delete temp;
				return;
			}
			while(curr!=NULL && curr->data!=ele)
			{
				curr=curr->next;
			}
			if(curr!=NULL)
			{
				if(curr->next!=NULL)
				{
					temp=curr;
					curr->prev->next=curr->next;
					curr->next->prev=curr->prev;
					delete temp;
				}
				else
				{
					curr->prev->next=NULL;
					temp=curr;
					delete temp;
				}
			}
			else
			{
				cout<<ele<<" no found\n";
			}
		}
		else
		{
			cout<<"no list\n";
		}
	}
	~DLL()
	{
		Node *temp,*curr=start;
		while(start!=NULL)
		{
			temp=start;
			start=start->next;
			delete temp;
		}
	} 
};
int main()
{
	DLL node;
	node.insert_begin(11);
	node.insert_last(6);
	node.traverse();
	node.insert_begin(4);
	node.traverse();
	node.insert_begin(9);
	node.traverse();
	node.insert_last(14);
	node.insert_after(4,12);
	node.traverse();
	node.insert_before(9,23);
	node.traverse_back();
	node.delete_begin();
	node.traverse();
	node.delete_last();
	node.traverse();
	node.delete_spec(4);
	node.traverse_back();
	return 0;
}