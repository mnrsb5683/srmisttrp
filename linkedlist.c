#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *create(int data){
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp->data=data;
   temp->next=NULL;
   return temp;
}
struct node *insertatbeginning(struct node *head,int data){
  struct node *temp=create(data);
  if(head==NULL){
     head=temp;
  }
  else{
     temp->next=head;
     head=temp;
  }
  return head;
}
struct node *insertatend(struct node *head,int data){
   struct node *temp=create(data),*x=head;
   if(head==NULL){
      head=temp;
   }
   else{
      while(x->next!=NULL){
          x=x->next;
      }
      x->next=temp;
  }
  return head;
}
struct node *insertatposition(struct node *head,int data,int pos){
   struct node *temp=create(data),*x=head,*y;
   if(head==NULL){
       head=temp;
   }
   else if(pos==1){
       temp->next=head;
       head=temp;
   }
  else{
     while(--pos){
         y=x;
         x=x->next;
         if(x==NULL) break;
    }
    y->next=temp;
    temp->next=x;
  }
  return head;
}
struct node *deleteatbeginning(struct node *head){
   struct node *temp=head;
   if(head==NULL){
      return NULL;
   }
   else{
       head=head->next;
       temp->next=NULL;
       free(temp);
  }
  return head;
}
struct node *deleteatend(struct node *head){
   struct node *temp=head,*x;
   if(head==NULL) return NULL;
   else if(head->next==NULL){
       head=NULL;
       free(temp);
   }
   else{
      while(temp->next!=NULL){
          x=temp;
          temp=temp->next;
     }
     x->next=NULL;
     free(temp);
  }
  return head;
}
struct node *deleteatposition(struct node *head,int pos){
   struct node *temp=head,*x;
   if(head==NULL) return NULL;
   else if(pos==1){
      head=head->next;
      temp->next=NULL;
      free(temp);
  }
  else{
      while(--pos){
         x=temp;
         temp=temp->next;
     }
     x->next=temp->next;
     temp->next=NULL;
     free(temp);
  }
  return head;
}
struct node *reverse(struct node *head){
   struct node *cur=head,*fwd,*newList=NULL;
   while(cur!=NULL){
      fwd = cur->next;
      cur->next=newList;
      newList=cur;
      cur=fwd;
   }
   head=newList;
   return head;
}

void display(struct node *head){
    if(head!=NULL){
       printf("%d ",head->data);
       display(head->next);
   }
}
