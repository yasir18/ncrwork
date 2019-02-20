 #include<iostream>
using namespace std;

 typedef struct n{
	int data;
	struct n *next;
} Node ;

class __List__{
	Node *start;
public:
	__List__(){
		start=NULL;
	}
	void Insert_First(int);
	void Insert_Last(int);
	void Insert_After(int,int);
	void Insert_Before(int,int);
	void Delete_specific(int);
	int Delete_First();
	int Delete_Last();
	void Travel_Forward();
	void Travel_Backward();
	void Reverse();
	void print(Node *start)
	{
		if(start==NULL)
			return;
		print(start->next);
		cout<<start->data<<" ";
	}
	~__List__(){	
		Node *temp;
		while(start!=NULL)
		{
			temp=start;
			start=start->next;
			delete temp;
		}
	
	}
};

void __List__::Insert_First(int ele){
	Node *temp=new Node;
	temp->data=ele;
		temp->next=start;
		start=temp;	
}

void __List__::Insert_Last(int ele){
	Node *temp=new Node;
	Node *curr;
	temp->data=ele;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		curr=start;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=temp;
	}
}

void __List__::Insert_After(int find,int ele){
	if(start!=NULL){
		Node *curr=start;
		Node *temp=new Node;
		temp->data=ele;
		temp->next=NULL;
		while(curr!=NULL && curr->data!=find){
			curr=curr->next;
		}
		if(curr!=NULL){//found element
			temp->next=curr->next;
			curr->next=temp;
		}
		else{//Not found
			cout<<"Not found\n";
		}
	}
	else{
		cout<<"Not Found\n";
	}
}

void __List__::Insert_Before(int find,int ele){
	if(start!=NULL){
		Node *curr=start;
		Node *temp=new Node;
		temp->data=ele;
		temp->next=NULL;
		if(start->data==find){
			temp->next=start;
			start=temp;
		}
		else{
			while(curr->next!=NULL && curr->next->data!=find){
				curr=curr->next;
			}
			if(curr->next!=NULL){//found element
				temp->next=curr->next;
				curr->next=temp;
			}
			else{//Not found
				cout<<"Not found\n";
			}	
		}
		
	}
	else{
		cout<<"Not Found\n";
	}
}

int __List__::Delete_First(){

		int x=-1;
		Node *temp;
		if(start!=NULL)
		{
			temp=start;
			x=temp->data;
			start=start->next;
			delete temp;	
		}
		return x;
}

int __List__::Delete_Last(){
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
			while(curr->next->next!=NULL)
			{
				curr=curr->next;	
			}	 
			temp=curr->next;
			x=temp->data;
			curr->next=NULL;
			delete temp;
		}
		return x;
}

void __List__::Delete_specific(int ele){

		Node *curr=start,*temp;
		if(curr!=NULL)
		{
			if(curr->data==ele)
			{
				temp=curr;
				start=NULL;
				delete temp;
				return;
			}
			while(curr->next!=NULL && curr->next->data!=ele)
			{
				curr=curr->next;
			}
			if(curr->next!=NULL)
			{
				temp=curr->next;
				curr->next=temp->next;
				delete temp;
				cout<<"deleted\n";
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
void __List__::Travel_Forward(){
	Node *curr;
		for(curr=start;curr!=NULL;curr=curr->next)
		{
			cout<<curr->data<<" ";
		}
		cout<<endl;
}

void __List__::Travel_Backward(){
	print(start);
	cout<<endl;
}


void __List__::Reverse(){
	Node *rev=NULL;
		Node *temp,*curr=start;
		while(curr!=NULL)
		{
			temp=curr;
			curr=curr->next;			
			temp->next=rev;
			rev=temp;

		}
		start=rev;
}


int main(){
	__List__ l;
	while(1)
	{
		cout<<"enter the operation you want"<<endl;
		cout<<"1. Insert at beginning \n2. insert at end\n3. insert before an element\n4. insert after an element\n";
		cout<<"5. delete at beginning \n6. delete at end\n7. delete specific element\n";
		cout<<"9. Display\n10.Reverse\n11.exit\n";
		int choice;
		cin>>choice;
		int ele,sele;
		switch(choice)
		{
			case 1:
				cin>>ele;
				l.Insert_First(ele);
				break;
			case 2:cin>>ele;
				l.Insert_Last(ele);
				break;
			case 3:
				cout<<"\n entert ele to enter and element to find: ";
				cin>>ele>>sele;
				l.Insert_Before(sele,ele);
				break;
			case 4:
			cout<<"\n entert ele to enter and element to find: ";
				cin>>ele>>sele;
				l.Insert_After(sele,ele);
				break;
			case 5:
				ele=l.Delete_First();
				if(ele!=-1)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 6:
				ele=l.Delete_Last();
				if(ele!=-1)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 7:
				cout<<"enter element";
				cin>>sele;
				l.Delete_specific(sele);
				// if(ele!=-1)
				// 	cout<<"deleted element is "<<ele<<endl;
				// else
				// 	cout<<"element not found to delete "<<endl;
				break;
			
			case 9:
				cout<<"enter the choice\n";
				cout<<"\t1.DisplayForward\n\t2.DisplayBackward\n";
				int x;
				cin>>x;
				if(x==1)
				{
					l.Travel_Forward();
				}
				else
					l.Travel_Backward();
				break;
			case 10:
				l.Reverse();
				cout<<"reversed list is"<<endl;
				l.Travel_Forward();
				break;
			case 11:
				exit(0);
		}	
	}
	return 0;
}