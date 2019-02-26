 #include<iostream>
using namespace std;

 typedef struct n{
	int data;
	struct n *next;
} Node ;

class StackLL{
	Node *start;
public:
	StackLL(){
		start=NULL;
	}
	void Insert_First(int);//We can also do Insert_last and delete first, but that would be expensive
	int Delete_First();
	void Travel_Forward();
	
	~StackLL(){	
		Node *temp;
		while(start!=NULL)
		{
			temp=start;
			start=start->next;
			delete temp;
		}
	
	}
};


void StackLL::Insert_First(int ele){
	Node *temp=new Node;
	temp->data=ele;
		temp->next=start;
		start=temp;	
}

int StackLL::Delete_First(){

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


void StackLL::Travel_Forward(){
	Node *curr;
		for(curr=start;curr!=NULL;curr=curr->next)
		{
			cout<<curr->data<<" ";
		}
		cout<<endl;
}



int main(){
	StackLL st;
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
				st.Insert_First(ele);
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