#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create (int A[],int n){
    int i;//scanning through the array
    struct Node *temp,*last;//last will help to add new node at the last
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;

    }

}
void display(struct Node*p){
    while(p!=NULL){
        printf("%d\n ",p->data);
        p=p->next;
    }
}
int count(struct Node*p){
    int count=0;
    while(p!=0){
        count++;
        p=p->next;
    }
    return count;
}
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index<0||index>count(p))
    return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++)
           p=p->next;
           t->next=p->next;
           p->next=t;
    }
    
}
int main()
{
   
   Insert(first,0,10);
   Insert(first,1,20);
   Insert(first,2,20);
   display(first);

}