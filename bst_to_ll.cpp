#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

typedef struct st
{
	int value;
	struct st* left;
	struct st* right;

} node;
typedef struct st2
{
	int value;
	struct st2* prev;
	struct st2* next;

} nodell;
vector<int> v;
node* create(node* head,int n)
{
	if (head==NULL)
	{
		head=new node;
		head->left=NULL;
		head->right=NULL;
		head->value=n;
		return head;
	}
	else if (head->value>n)
	{
		head->left=create(head->left,n);
	}
	else if (head->value<n)
	{
		head->right=create(head->right,n);
	}
	else
	{
		cout<<"THe number already exists"<<endl;
		return head;
	}
}

 void inorder(node* head)
{
	//cout<<"a"<<endl;
	if (head)
	{
		//cout<<"b"<<endl;
		inorder(head->left);
		v.push_back(head->value);
		inorder(head->right);
	}
}

nodell* makell(int n,nodell* &prev,nodell* &head)
{
	if(head==NULL)
	{
		head=new nodell;
		prev=head;
		head->value=n;
		head->prev=NULL;
		head->next=NULL;
		return head;
	}
	{

		nodell* temp;
		temp=prev;
		prev->next=new nodell;
		prev=prev->next;
		prev->value=n;
		prev->next=NULL;
		prev->prev=temp;
		return head;
	}

}

void display(nodell* head,nodell* prev)
{
	nodell* temp;
	temp=head;
	nodell* temp2;
	temp2=prev;

	while(temp!=NULL)
	{
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<endl;
	while(temp2!=head)
	{
		cout<<temp2->value<<" ";
		temp2=temp2->prev;
	}
	cout<<temp2->value;

}
int main()
{
	node* head;
	head=NULL;
	char ch;
	int n;
	nodell* prev;
	nodell* head2;
	head2=NULL;
	prev=NULL;
	while(true)
	{
		cout<<"Enter the value to be entered"<<endl;
		cin>>n;
		head=create(head,n);
		cout<<"Continue y or n"<<endl;
		cin>>ch;
		if (ch=='n')
		{
			break;
		}
	}
	inorder(head);
	int i;
	i=0;
	while(i<v.size())
	{
		cout<<v[i]<<" ";
		cout<<endl;
		makell(v[i],prev,head2);
		i++;
	}
	display(head2,prev);
}
