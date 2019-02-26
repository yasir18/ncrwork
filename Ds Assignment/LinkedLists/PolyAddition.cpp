#include<iostream>
using namespace std;
typedef struct node 
{
	int coeff;
	int expo;
	struct node *next;
} Node;
class poly
{
	Node *start;
public:
	poly()
	{
		start=NULL;
	}
	void createPoly();
	void addToList(int x,int y);
	void add(poly p1,poly p2);
	void display();
	~poly()
	{
		struct node* temp=start;
		while(temp!=NULL)
		{
			struct node *x=temp;
			temp=temp->next;
			delete x;
		}
	}
};
void poly::display()
{
	if(start!=NULL)
	{
		Node *temp=start;
		while(temp!=NULL)
		{
			if(temp->coeff<0)
				cout<<temp->coeff<<"x^"<<temp->expo<<" ";
			else if(temp->coeff>0)
			{
				cout<<"+"<<temp->coeff<<"x^"<<temp->expo<<" ";
			}
			temp=temp->next;
		}
		cout<<endl;
	}
	else
	{
		cout<<"Nothing to display\n";
	}
}
void poly::add(poly p1,poly p2)
{
	int x,y;
	Node *x1=p1.start,*x2=p2.start;
	while(x1!=NULL&&x2!=NULL)
	{
		if(x1->expo==x2->expo)
		{
			x=x1->coeff+x2->coeff;
			addToList(x,x1->expo);
			x1=x1->next;
			x2=x2->next;
		}
		else if(x1->expo<x2->expo)
		{
			addToList(x2->coeff,x2->expo);
			x2=x2->next;
		}
		else 
		{
			addToList(x1->coeff,x1->expo);
			x1=x1->next;
		}
	}
	while(x1!=NULL)
	{
		addToList(x1->coeff,x1->expo);
		x1=x1->next;
	}
	while(x2!=NULL)
	{
		addToList(x2->coeff,x2->expo);
		x2=x2->next;
	}
	return ;
}
void poly::addToList(int x,int y)
{
	Node *temp=new node;
	temp->coeff=x;
	temp->expo=y;
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
void poly::createPoly()
{
	cout<<"enter the number of terms :"<<endl;
	int numInputs;
	cin>>numInputs;
	while(numInputs--)
	{
		cout<<"enter  polynomial coefficient followed by exponents : ";
		int coeff,expo;
		cin>>coeff>>expo;
		addToList(coeff,expo);
	}
}
int main()
{
	poly p1,p2,p3;
	p1.createPoly();
	p1.display();
	p2.createPoly();
	p2.display();
	p3.add(p1,p2);
	cout<<"The result of of polynomial addition is:\n ";
	p3.display();
	system("pause");
	return 0;
}