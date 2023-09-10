// singli linklist insert Delete

#include <stdio.h>
#include<stdlib.h>

 struct abc
    {
     int data;
     struct abc *next;
    };

 struct abc *InsertB(struct abc *head,int d)
   {   struct abc *t;
       t=(struct abc *)malloc(sizeof(struct abc));
       t->data=d;
       t->next=NULL;
       
       t->next=head;
       head=t;
       return head;
    } 
 
 struct abc *InsertM(struct abc *head,int d,int n)
   {   struct abc *t,*p;
       t=(struct abc *)malloc(sizeof(struct abc));
       t->data=d;
       t->next=NULL;
       
       p=head;
     while(head->data!=n)
      {
        head=head->next;
       }
      t->next=head->next;
      head->next=t;
      head=p;
      return head;
    }    
     
 struct abc *InsertE(struct abc *head,int d)
   {   struct abc *t,*p;
       t=(struct abc *)malloc(sizeof(struct abc));
       t->data=d;
       t->next=NULL;
       
       p=head;
     while(head->next!=NULL)
      {
        head=head->next;
       }
      head->next=t;
      head=p;
      return head;
    }
       
 void Display(struct abc*head)
   {  struct abc *p;
      p=head;
     while(head!=NULL)
      {
        printf("%d\t",head->data);
        head=head->next;
       }
      head=p;
    }
    
 struct abc *DeleteB(struct abc *head) 
   {  struct abc *p;
      p=head;
      head=head->next;
      free(p);
      return head;
    }
 
 struct abc *DeleteM(struct abc *head,int n) 
   {  struct abc *p,*q;
      p=head;
     while(p->data!=n)
      {
        q=p;
        p=p->next;
       }
      q->next=p->next;
      p->next=NULL;
      free(p);
      return head;
    }     
      
 struct abc *DeleteE(struct abc *head) 
   {  struct abc *p,*q;
      p=head;
     while(p->next!=NULL)
      { 
       q=p;
       p=p->next;
        }
      q->next=NULL;
      free(p);
      return head;
    }     
    
int main()
{   struct abc *head,*temp,*p;
    int a,b,i,e,ch,c,d,n;
    
    printf("Enter The Number Of Nodes: ");
    scanf("%d",&b);
    
    head=(struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter Data Of 1 Node: ");
    scanf("%d",&a);
    head->data=a;
    head->next=NULL;
    
    p=head;
    for(i=1;i<b;i++)
    {
       temp=(struct abc *)malloc(sizeof(struct abc));
       printf("\nEnter Data Of %d Node: ",i+1);
       scanf("%d",&a);
       temp->data=a;
       temp->next=NULL;
       
       head->next=temp;
       head=head->next;
       
     }
     
       head=p;
       printf("\n\tLINKLIST: ");
       Display(head);
    
  do
    {
         printf("\n\n1.Insert Node At Begin\n");
         printf("2.Insert Node At Middle\n");
         printf("3.Insert Node At End\n");
         printf("4.Delete Node From Begin\n");
         printf("5.Delete Node From Middle\n");
         printf("6.Delete Node From End\n");
         
         printf("\nEnter Your Choice: ");
         scanf("%d",&ch);
         
      switch(ch)
        {
 
              case 1:printf("\nEnter The New Data To Be Insert: ");
                     scanf("%d",&d);
                     
                     head=InsertB(head,d);
                     printf("\nAfter Process: ");
                     printf("\n\tLINKLIST: ");
                     Display(head);
                     
                     break;
              
              case 2:printf("\nEnter The Data After Which New Data To Be Insert: ");
                     scanf("%d",&n);
                     printf("\nEnter The New Data To Be Insert: ");
                     scanf("%d",&d);
                     
                     
                     head=InsertM(head,d,n);
                     printf("\nAfter Process: ");
                     printf("\n\tLINKLIST: ");
                     Display(head);
                     
                     break;
                     
              case 3:printf("\nEnter The New Data To Be Insert: ");
                     scanf("%d",&d);
                     
                     head=InsertE(head,d);
                     printf("\nAfter Process: ");
                     printf("\n\tLINKLIST: ");
                     Display(head);
                     
                     break ;
                     
              case 4:head=DeleteB(head);
                     printf("\nAfter Process: ");
                     printf("\n\tLINKLIST: ");
                     Display(head);
                     break ;
                     
              case 5:printf("\nEnter The Data Of Which You Want Delete: ");
                     scanf("%d",&n);
                     
                     head=DeleteM(head,n);
                     printf("\nAfter Process: ");
                     printf("\n\tLINKLIST: ");
                     Display(head);
                     break ;
                     
              case 6:head=DeleteE(head);
                     printf("\nAfter Process: ");
                     printf("\n\tLINKLIST: ");
                     Display(head);
                     break ;
                     
            }
       
         head=p;
         
         printf("\n\nDo You Want To Continue[Y==1||N==0]: ");
         scanf("%d",&e);
        
        
        
       }
         while(e==1);
     
    return 0;
}