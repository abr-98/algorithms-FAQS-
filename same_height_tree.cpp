#include <iostream> 
#include <queue> 
using namespace std; 
  

typedef struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}node; 

node* same_height(node * head,int level)
{
    if (head == NULL)  
        return head;  

    if(level==1)
    {
        cout<<head->data<<"  ";
        return head;

    }


    if (level>1)
    {
        same_height(head->left,level-1);
        same_height(head->right,level-1);
        return head;
    }

}

void levelOrder(node *root) 
{ 
    
    if (root == NULL)  return; 
  
 
    queue<node *> q; 
  
    
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        node *temp = q.front(); 
        cout << temp->data << " "; 
        q.pop();      
     
        
        if (temp->left != NULL) 
            q.push(temp->left); 
  
        
        if (temp->right != NULL) 
            q.push(temp->right); 
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
    head=create(head,1);
    head=create(head,3);
    head=create(head,2);
    head=create(head,6);
    head=create(head,5);
    head=create(head,4);
  
    //cout << "Level Order "<<endl; 
    //levelOrder(head); 
    //inorder(head);
    same_height(head,3);
    return 0; 
} 