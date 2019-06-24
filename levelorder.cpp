#include <iostream> 
#include <queue> 
using namespace std; 
  

typedef struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}node; 
  

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
    head=create(head,2);
    head=create(head,3);
    head=create(head,4);
    head=create(head,5);
    head=create(head,6);
  
    cout << "Level Order "<<endl; 
    levelOrder(head); 
    return 0; 
} 