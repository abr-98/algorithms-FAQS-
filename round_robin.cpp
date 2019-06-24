#include<bits/stdc++.h>
#include<vector>
using namespace std;



typedef struct st
{	
	int id;
	vector<int> task_id;
	struct st* next;
}	job;


job* alloc(int &k)
{	
	int l;
	char ch;
	job* temp;
	temp=new job;
	cout<<"Enter the job id"<<endl;
	cin>>temp->id;
	int count;
	count=0;
	while(true)
	{
		cout<<"Enter the task id"<<endl;
		cin>>l;
		count++;
		temp->task_id.push_back(l);
		cout<<"Tasks left y or n"<<endl;
		cin>>ch;
		if(ch=='n')
		{
			break;
		}
	}
	if (count>k)
	{
		k=count;
	}
	temp->next=NULL;
	return temp;
}
void pr_job(job* head,int max)
{
	int control;
	control=0;
	job* temp;
	int max_t;
	max_t=max;
	//cout<<max<<endl;
	while(control<max_t)
	{
		//cout<<control<<endl;
		temp=head;
		while(temp!=NULL)
		{
				
			if (temp->task_id.size()>control)
			{//cout<<temp->task_id.size()<<endl;
				cout<<"Job id: "<<temp->id;
				cout<<"\t";

			
				cout<<"Task id: "<<temp->task_id[control];
			}
			cout<<endl;
			temp=temp->next;

		}
		cout<<endl;

		control++;
	}
}

int main()
{
	int max;
	max=0;
	char ch;
	job* head;
	job* temp_head;
	head=NULL;
	head=alloc(max);
	temp_head=head;
	while(true)
	{
		cout<<"Jobs left y or n"<<endl;
		cin>>ch;
		if (ch=='n')
			break;
		temp_head->next=alloc(max);
		temp_head=temp_head->next;
	}

	pr_job(head,max);


}