#include <iostream> 
#include <queue> 
using namespace std; 
  

typedef struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}node; 

int sum_tree(node * head)
{
    if(head==NULL)
        return 0;

    int temp;
    temp=head->data;

    head->data=sum_tree(head->left)+sum_tree(head->right);
    int k;
    k=head->data+temp;

    return k;

}


  
node* create(node* head,int n)
{
    if (head==NULL)
    {
        head=new node;
        head->left=NULL;
        head->right=NULL;
        head->data=n;
        return head;
    }
    else if (head->data>n)
    {
        head->left=create(head->left,n);
    }
    else if (head->data<n)
    {
        head->right=create(head->right,n);
    }
    else
    {
        cout<<"THe number already exists"<<endl;
        return head;
    }
}
  

int main() 
{ 
    node* head;
    head=create(head,10);
    head=create(head,8);
    head=create(head,2);
    //head=create(head,3);
    //head=create(head,5);
    //head=create(head,6);
    int sum;
    sum=sum_tree()
    return 0; 
} 