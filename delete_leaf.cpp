#include <iostream> 
#include <queue> 
using namespace std; 
  

typedef struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}node; 


node* del_leaf(node* head, int v)
{

    if (head==NULL)
    {
       // cout<<"a"<<endl;
        return head;
    }
    
        //cout<<"b"<<endl;
        head->left=del_leaf(head->left,v);
        head->right=del_leaf(head->right,v);
        //cout<<head->data<<endl;
        if ((head->data==v) && (head->left==NULL) && (head->right==NULL))
        {
            
           // cout<<"c"<<endl;
            delete(head);
            head=NULL;
            return head;
    
    }

}

void inorder(node* head)
{
    if (head == NULL) 
        return; 
    //cout<<"a"<<endl;
    
        //cout<<"b"<<endl;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    
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
    head=create(head,3);
    head=create(head,5);
    head=create(head,6);
    inorder(head);
    cout<<endl;
    del_leaf(head,2);
   // cout<<head;
    inorder(head);

    //int sum;
    //sum=sum_tree()
    return 0; 
} 