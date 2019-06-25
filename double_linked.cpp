#include<bits/stdc++.h>

using namespace std;

typedef struct st2
{
	int value;
	struct st2* prev;
	struct st2* next;

} nodell;

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
int length(nodell * head, nodell* prev)
{
	int count;
	count=0;
	nodell* temp;
	temp=head;
	while(temp!=prev)
	{
		temp=temp->next;
		count++;
	}
	count++;
	return count;

}
nodell* delete_beg(nodell *head)
{
	nodell* temp;
	temp=head;
	temp=head->next;
	temp->prev=NULL;

	delete(head);
	head=temp;
	return head;
}

void delete_a(nodell* prev, nodell* next)
{
	nodell* temp;
	temp=prev;
	temp=prev->next;
	prev->next=temp->next;
	next->prev=temp->prev;
	delete(temp);

}
nodell* delete_last(nodell* prev)
{
	nodell* temp;
	temp=prev;
	temp=temp->prev;
	temp->next=NULL;
	delete(prev);
	return temp;
}
nodell* alternate(nodell* head,nodell* prev)
{
	int l;
	l=length(head,prev);
	nodell* temp;
	nodell* temp2;

	temp=head;
	temp2=prev;

	while(temp2->prev!=NULL)
	{
		temp2=temp2->prev;
	}

	if (l%2==0)
	{
		while(temp!=NULL)
		{
			if (temp==head)
			{
				head=delete_beg(temp);
				temp=(temp->next)->next;

				
			}
			//temp=temp->next;

			delete_a(temp2,temp);
			temp=(temp->next)->next;
			temp2=temp2->next;
			

		}

	}
	else
	{
		while(temp2->next!=NULL)
		{
			if (temp==head)
			{
				head=delete_beg(temp);
				temp=(temp->next)->next;

				
			}
			//temp=temp->next;

			delete_a(temp2,temp);
			temp=(temp->next)->next;
			temp2=temp2->next;
		}
		delete_last(head->prev);
	}
}

