 #include<iostream>
using namespace std;

 typedef struct n{
	int data;
	struct n *next;
} Node ;

class QueueLL{
	Node *start;
public:
	QueueLL(){
		start=NULL;
	}
	void Insert_Last(int);//We can also do Insert_last and delete first, but that would be expensive
	int Delete_First();
	void Travel_Forward();
	
	~QueueLL(){	
		Node *temp;
		while(start!=NULL)
		{
			temp=start;
			start=start->next;
			delete temp;
		}
	
	}
};


void QueueLL::Insert_Last(int ele){
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

int QueueLL::Delete_First(){

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


void QueueLL::Travel_Forward(){
	Node *curr;
		for(curr=start;curr!=NULL;curr=curr->next)
		{
			cout<<curr->data<<" ";
		}
		cout<<endl;
}



int main(){
	QueueLL st;
	while(1)
	{
		cout<<"enter the operation you want"<<endl;
		cout<<"1. Push \n2. Pop \n3. Display\n4. Exit\n";
		int choice;
		cin>>choice;
		int ele,sele;
		switch(choice)
		{
			case 1:
				cin>>ele;
				st.Insert_Last(ele);
				break;
			case 2:
				ele=st.Delete_First();
				if(ele!=-1)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;	
				break;
			case 3:
				st.Travel_Forward();
				break;
			case 4:
				return 0;
			default:
			 break;
		}	
	}
	return 0;
}