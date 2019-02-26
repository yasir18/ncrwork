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
	
	void Insert_sort(int);
	void Travel_Forward();
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



void __List__::Insert_sort(int find){
		Node *temp=new Node;
		temp->data=find;
		temp->next=NULL;
		if(start!=NULL){
			Node *curr=start;
			
			if(start->data>=find){
				temp->next=start;
				start=temp;
			}
			else{
				while(curr->next!=NULL && curr->next->data<find){
					curr=curr->next;
				}
				if(curr->next!=NULL){//found element
					temp->next=curr->next;
					curr->next=temp;
				}
				else{// 
					curr->next=temp;

				}	
			}
			
		}
	else{
		start=temp;
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


int main(){
	__List__ l;
	while(1)
	{
		cout<<"enter the operation you want"<<endl;
		cout<<"1. Insert \n2. Display\n3. exit\n";
		int choice;
		cin>>choice;
		int ele,sele;
		switch(choice)
		{
			case 1:
				cin>>ele;
				l.Insert_sort(ele);
				break;
			case 2:
				l.Travel_Forward();
				break;
			case 3:
				return 0;
				break;
			
		}	
	}
	return 0;
}