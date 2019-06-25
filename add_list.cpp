#include<bits/stdc++.h>

using namespace std;

typedef struct st 
{
	int value;
	struct st* next;

}node;


node* delete_any(node* curr,node* &prev)
{
	if (curr==prev)
	{
		//node* temp;
		curr=curr->next;
		delete(prev);
		prev=curr;
		return curr;
	}
	else
	{
		node* temp;
		temp=curr;
		prev->next=curr->next;
		curr=curr->next;
		delete temp;
		return curr;
	}
}

node* create(node* head,int n)
{
	if(head==NULL)
	{
		node* temp;
		temp=new node;
		temp->value=n;
		temp->next=NULL;
		return temp;;
	}
	else
	{
		node* temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new node;
		temp=temp->next;
		temp->value=n;

		temp->next=NULL;
	}
	return head;
}

node* find(node* head)
{
	node* temp;
	node* prev;
	temp=head;
	prev=temp;
	int sum;
	int flag;
	flag=0;
	sum=0;
	while(temp!=NULL)
	{
		if(temp->next->value==0)
		{	
			if ((temp->next->value==0) && (flag==0))
			{
				flag=1;
			}
			else
			{
				flag=11;
			}

			//cout<<temp->value<<" "<<"b"<<endl;
			temp->value=temp->value+sum;
			sum=0;
			if (flag==1)
			{
				head=temp;
			}
			prev=temp;
			temp=temp->next;

			temp=delete_any(temp,prev);
			
		}
		else
		{
			//cout<<temp->value<<" "<<"a"<<endl;
			sum=sum+temp->value;
			temp=delete_any(temp,prev);
			//prev=temp;
			//temp=temp->next;

		}
	}
	return head;
}
void disp_p( node* head)
{
	node* temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->value<<" ";
		temp=temp->next;
	}	
}

int main()
{
	node* head;
	head=create(head,1);
	head=create(head,2);
	head=create(head,3);
	head=create(head,0);
	head=create(head,5);
	head=create(head,4);
	head=create(head,0);
	head=create(head,3);
	head=create(head,2);
	head=create(head,0);
	//cout<<"A"<<endl;
	//disp_p(head);
	head=find(head);
	disp_p(head);
	//node* temp;
	//temp=head;
	
}