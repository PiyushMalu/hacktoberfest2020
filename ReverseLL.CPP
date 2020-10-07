#include <bits/stdc++.h>
using namespace std;
struct LL{
  int data;
  LL *next;  
};
void insertAtBeginning(struct LL**head,int dataToBeInserted)
{
  struct LL* curr=new LL;
    
    curr->data=dataToBeInserted;
    curr->next=NULL;
  
  if(*head==NULL)
      *head=curr; //if this is first node make this as head of list
    
  else
    {
      curr->next=*head; //else make the current (new) node's next point to head and make this new node a the head
      *head=curr;
    }
    
    //O(1) constant time
}
void reverseListRecursively(struct LL *root,struct LL**head)
{
  if(root->next==NULL) //if this is the only node make it head and return
    {
      *head=root;
      return;
    }
  
  else
    {
    reverseListRecursively(root->next,head); //traverse upto end first
    root->next->next=root;  //Make the next node to point itself , hence reversing the links
    root->next=NULL;
    }
  //O(2*number of nodes)
  
}
void display(struct LL**head)
{
  struct LL*temp=*head;
  while(temp!=NULL)
    {
      if(temp->next!=NULL)
      cout<<temp->data<<" ->";
      else
      cout<<temp->data;
      
      temp=temp->next; //move to next node
    }
    //O(number of nodes)
  cout<<endl;
}
int main()
{
  
  struct LL *head = NULL; //initial list has no elements
  insertAtBeginning(&head,6);
  insertAtBeginning(&head,16);
  insertAtBeginning(&head,15);
  insertAtBeginning(&head,50);
  insertAtBeginning(&head,1);
  insertAtBeginning(&head,23);
  
  cout<<"Initial List is :-\n";
  display(&head);
  
  reverseListRecursively(head,&head);
  
  cout<<"\nAfter the reverse function the list is :- \n";
  display(&head);
  
  
  return 0;
}
