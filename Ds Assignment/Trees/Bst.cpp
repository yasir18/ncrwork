#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}Node;

class BST{
	
public:
	Node *root;
	BST(){
		root=NULL;
	}
	Node* Insert(Node*,int);
	Node* Delete(Node*,int);
	void Inorder(Node*);
	void Preorder();
	void Postorder();
//	~BST();
	int findmax();
	int findmin();
	int height();
	int noOfNodes();
	int noOfNonLeafNodes();
};

Node* BST::Insert(Node* root,int ele){
	if(root==NULL){
		Node *temp=new Node;
		temp->data=ele;
		temp->left=temp->right=NULL;
		return temp;
	}
	else if(ele<root->data){
		root->left=Insert(root->left,ele);
	}
	else{
		root->right=Insert(root->right,ele);
	}
	return root;

}

void BST::Inorder(Node* root){
	if(root==NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

Node* BST:: Delete(Node* root,int ele){
	if(root->data==ele){ //No children
		if(root->left==NULL && root->right==NULL){
			delete(root);
			return NULL;
		}
		else if(root->left==NULL || root->right==NULL){ //Only a single child
			Node *temp=root;
			Node* temp2;
			if(root->left)
				temp=root->left;
			else
				temp=root->right;

			delete(root);
			return (temp);

		}
		else{  //Two childs; Logic is to delete max in left sub tree and replace that data in root
			int tempData;
			Node *curr=root->left;
			Node *prev=root;
			if(curr->right!=NULL) {	//if there is somethiing towards right of root in left sub tree		
				
				while( curr->right->right!=NULL ){
					curr=curr->right;
					// if(curr->right->right==NULL)
					// {
					// 	prev=curr;
					// 	curr=curr->right;
					// 	break;
					// }
				}

				tempData=curr->right->data;	
				root->data=tempData;
				if(curr->right->left!=NULL) //if there exist left nodes to the right most node in left sub tree
				{
					Node *temp=curr->right;
					curr->right=curr->right->left;
					delete(temp);
				}
				else{
					Node *temp=curr->right;
					delete(temp);
					curr->right=NULL;
				}
				
				
				return root;
			}
			else{ //if there is nothing towards right of root in left sub tree
				tempData=curr->data;
				root->data=tempData;
				root->left= (Delete(curr,tempData));
				return root;
			}
			
		}
	}
	else if(ele<root->data){
		root->left=Delete(root->left,ele);
	}
	else{
		root->right=Delete(root->right,ele);
	}
	return root;
}

int main(){
	BST tree;
	tree.root=tree.Insert(tree.root,15);
	tree.root=tree.Insert(tree.root,10);
	tree.root=tree.Insert(tree.root,5);
	tree.root=tree.Insert(tree.root,12);
	tree.root=tree.Insert(tree.root,17);
	tree.root=tree.Insert(tree.root,13);
	tree.root=tree.Insert(tree.root,11);
	tree.Inorder(tree.root);
	cout<<"After deletion \n";
	tree.Delete(tree.root,15);
	tree.Inorder(tree.root);
	return 0;
}

