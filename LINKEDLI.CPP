#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//node structure
struct node{
 int data;
 struct node* next;
};

//fucntion to insert a new node at the end
void insertEnd(struct node** head,int data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=data;
  new_node->next=NULL;

  if(*head==NULL){
   *head=new_node;
  }
  else{
   struct node* temp=*head;
   while(temp->next !=NULL){
      temp=temp->next;
      }
   temp->next=new_node;
  }
  printf("Element %d inserted at the end.\n",data);
}

//funtion to insert at the beginning
void insertBeginning(struct node** head,int data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=data;
  new_node->next=*head;
  *head=new_node;
  printf("Element %d inserted at the beginning.\n",data);
}

//funtion to insert at a specific position
void insertAtPosition(struct node** head,int data,int position){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=data;
  if(position==1){
    new_node->next=*head;
    *head=new_node;
    printf("Element %d inserted at position.\n",position);
    return;
  }
  struct node* temp=*head;
  for(int i=1;temp!=NULL && i<position-1;i++){
    temp=temp->next;
  }
  if(temp==NULL){
    printf("position out of range.Inserting element %d at the end.\n",data);
    insertEnd(head,data);
    }
  else{
    new_node->next = temp->next;
    temp->next = new_node;
    printf("Element %d inserted at position %d.\n",data,position);
    }
  }
//function to display the linked list
void display(struct node* head){
  if(head==NULL){
    printf("List is empty.\n");
    return;
  }
  struct node* temp=head;
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

void main()
{
  struct node* head=NULL;
  int choice,value,pos;
  clrscr();
  while(choice!=8){
  printf("\nMenu:\n");
  printf("1.Insert at the end\n");
  printf("2.Insert at the beginning\n");
  printf("3.Insert at a specific\n");
  printf("4.delete from the beginning\n");
  printf("5.delete from the end\n");
  printf("6.delete from a specific position\n");
  printf("7.display the list\n");
  printf("8.exit\n");
  printf("enter your choice:\n");
  scanf("%d",&choice);
   switch(choice)
   {
   case 1:
      printf("enter an element to insert at the end\n: ");
      scanf("%d",&value);
      insertEnd(&head,value);
      break;
   case 2:
      printf("enter an element to insert at the beginning: \n");
      scanf("%d",&value);
      insertBeginning(&head,value);
      break;
   case 3:
      printf("enter an element to insert at a specific position: \n");
      scanf("%d",&value);
      printf("enter the position of element to be inserted: \n");
      scanf("%d",&pos);
      insertAtPosition(&head,value,pos);
      break;
   case 7:
      printf("linked list:\n");
      display(head);
      break;
   case 8:
      printf("exiting the progran.\n");
      break;
   default:
      printf("Invalid choice! please try again.\n");
   }
  }
  getch();
}



