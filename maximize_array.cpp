#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<string.h>
using namespace std;
typedef struct st
{
	int value;
	int array;
	int index; 
	struct st* next;
} node;


node* insert(node* head, int n,int ar,int in)
{
	node* temp;
	temp=head;
	if (head==NULL)
	{
		head->value=n;
		head->array=ar;
		head->index=in;
		head->next=NULL;

	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new node;
		temp=temp->next;
		temp->value=n;
		temp->array=ar;
		temp->index=in;
		temp->next=NULL;
	}

}
node* insert_beg(node* head,int n,int ar,int in)
{
	node* temp;
	temp=new node;
	//temp=temp->next;
	temp->value=n;
	temp->array=ar;
	temp->index=in;
	temp->next=head;
	head=temp;

	return head;


}

void insert_end(node* head,int n,int ar,int in)
{
	node* temp;
	temp=head;
	while(temp->next==NULL)
	{
		temp=temp->next;
	}
	temp->next=new node;
	temp=temp->next;
	temp->value=n;
	temp->array=ar;
	temp->index=in;
	temp->next=NULL;
	//head=temp;



}
void insert_before(node* head,int n,int ar,int in,int k)
{
	node* temp;
	node* prev;
	temp=head;
	prev=temp;
	while(temp->value==k)
	{
		prev=temp;
		temp=temp->next;
	}
	node* temp2;
	temp2=new node;
	temp2->value=n;
	temp2->array=ar;
	temp2->index=in;
	temp2->next=prev->next;
	prev->next=temp2;
	//head=temp;



}
node* down_sort(node * head)
{
	int count;
	count=0;
	node* temp;
	node* temp2;
	node* temp3;
	temp= head;
	node* head_now;	
	int n;
	head_now=insert(head_now,temp->value,temp->array,temp->index);
	temp2=head_now;
	temp3=head_now;
	temp=temp->next;
	while (temp!=NULL )
	{
		n=temp->value;
		if (temp2->value>n)
		{
			temp2=insert_beg(temp2,n,temp->array,temp->index);
		}
		else
		{
			while(temp2->value<=n)
			{
				temp2=temp2->next;

			}
			temp2=temp2->next;
			insert_before(temp3,n,temp->array,temp->index,temp2->value);

		}
		temp=temp->next;
		count++;
	}


	return head_now;

}

vector<int> exchange(node* head_now, int min)
{
	vector<map<int,int>> v;
	map<int,int> entry1;
	
	node* temp;
	node* temp2;
	temp=head_now;
	int i;
	i=0;
	while(i<min)
	{
		temp=temp->next;
		i++;
	}
	int c;
	c=0;
	temp->next=NULL;
	i=0;
	temp2=head_now;
	
		while(temp2!=NULL)
		{
			if(temp2->array==2)
			{
				entry1[temp2->index]=temp2->value;
				//map<temp2->index,temp2->value> entry1=numbers[i]
				//positions.push_back(temp2->index)
				c++;
				//i++;

			}


		}
		temp2=head_now;
		while(temp2!=NULL)
		{
			if(temp2->array==1)
			{
				entry1[temp2->index]=temp2->value;
				//positions.push_back(temp2->index)

			}
			

		}
		

		


}



