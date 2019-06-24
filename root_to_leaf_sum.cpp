#include <iostream> 
#include <queue> 
using namespace std; 
  

typedef struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}node; 

int root_to_leaf(node* head,int sum)
{
    int flag;
    flag=0;
   // cout<<head<<" "<<sum;
    if (head==NULL)
    {
    //    cout<<"path not found "<<endl;
        return 0;
    }
    else
    {

        int sum2;
        sum2=sum-head->data;

        if(sum2==0 && head->left==NULL && head->right==NULL)
        {
            return 1;
        }

        if (head->left)
            flag=root_to_leaf(head->left,sum2);

         if (head->right)
            flag=root_to_leaf(head->right,sum2);
          
        return flag;
     }

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
    int k;
    k=root_to_leaf(head,20);
    if(k==1)
    {
        cout<<"Found";

    }
    else
    {
        cout<<"Not found";
    }
    
    return 0; 
} 