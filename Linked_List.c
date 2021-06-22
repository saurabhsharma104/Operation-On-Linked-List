#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void insertAtEnd(int);
int deleteAtEnd();
void insertAtBegin(int);
int deleteAtBegin();
void insertAtMiddle(int);
int deleteAtMiddle(int);
float avg();
void reverse();
void display();
void sort();
int count();
void count_item_occurrences(int);


struct Student{
    int data;
    struct Student *ptr;
}*start=NULL,*head=NULL;

void main(){
    int ch;
    int item;
    do
    {
        printf("\n1.  InsertAtEnd operation...");
        printf("\n2.  Find the occurrences of a elements.....");
        printf("\n3.  Reverse operation...");
        printf("\n4.  Average operation...");
        printf("\n5.  Display....");
        printf("\n6.  DeleteAtEnd operation...");
        printf("\n7.  InsertAtBegin operation...");
        printf("\n8.  DeleteAtBegin operation...");
        printf("\n9.  InsertAtMiddle operation...");
        printf("\n10. DeleteAtMiddle operation...");
        printf("\n11. Sort Operation....");
        printf("\n12. Count Node Operation....");
        printf("\n13. Exit..");

        printf("\n\n Enter your choice.... ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("enter the data of the student which r u push in the link list  ....");
                scanf("%d",&item);
                insertAtEnd(item);
                break;
            case 2:
                printf("Enter the item...");
                scanf("%d ",&item);
                count_item_occurrences(item);
                break;
            case 3:
                reverse();
                break;
            case 4:
                printf("\n The Average of the list is : %f",avg());
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Poped item is : %d ",deleteAtEnd());
                break;
            case 7:
                printf("enter the data of the student which r u push in the link list  ....");
                scanf("%d",&item);
                insertAtBegin(item);
                break;
            case 8:
                printf("Poped item is : %d ",deleteAtBegin());
                break;
            case 9:
                printf("enter the data of the student which r u push in the link list  ....");
                scanf("%d",&item);
                insertAtMiddle(item);
                break;
            case 10:
                printf("Enter the item whatever you want to delete...");
                scanf("%d ",&item);
                printf("Poped item is : %d ",deleteAtMiddle(item));
                break;
            case 11:
                sort();
                break;
            case 12:
                printf("Total item is in linked list : %d ",count());
                break;
            case 13:
                exit(1);

            default:
                printf("Please enter correct choice....");
        }
    }while(1==1);

    return;
}

void insertAtEnd(int item){
    struct Student *next;
    next= (struct Student *)malloc(sizeof(struct Student));
    next->data = item;
    next->ptr = NULL;
    if(start==NULL)
    {
        start=head=next;
    }
    else
    {

        head->ptr=next;
        head = next;
    }

}
int deleteAtEnd(){
    struct Student *pre=start;
    int tmp;
    if(head==NULL)
    {
        printf("\n List is empty..");
        return -1;
    }
    if(start==head)
    {
        tmp=start->data;
        free(start);
        head=start=NULL;
        return tmp;
    }
    else
    {
        while(pre->ptr!=head)
        {
            pre=pre->ptr;
        }
        tmp = head->data;
        free(head);
        head=pre;
        head->ptr=NULL;
    }
    return tmp;
}


void insertAtBegin(int item){
    struct Student *next;
    next= (struct Student *)malloc(sizeof(struct Student));
    next->data = item;
    next->ptr = NULL;
    if(start==NULL)
    {
        start=head=next;
    }
    else
    {

        next->ptr=start;
        start = next;
    }

}


int deleteAtBegin(){
    struct Student *pre=start;
    int tmp;
    if(start==NULL)
    {
        printf("\n List is empty..");
        return -1;
    }
    if(start==head)
    {
        tmp=start->data;
        free(start);
        head=start=NULL;
        return tmp;
    }
    else
    {
        start = start->ptr;
        tmp = pre->data;
        free(pre);
    }
    return tmp;
}


void insertAtMiddle(int item){
    struct Student *next,*temp = start;
    int a;
    printf("Enter the previous item...");
    scanf("%d ",&a);
    next= (struct Student *)malloc(sizeof(struct Student));
    next->data = item;
    next->ptr = NULL;
    if(start==NULL)
    {
        start=head=next;
    }
    else
    {
        while(temp->data != a){
            temp = temp->ptr;
            if(!temp->ptr){
                printf("\n Destination not found...");
            }
        }
        next->ptr = temp->ptr;
        temp->ptr = next;
    }
}

int deleteAtMiddle(int item){
    struct Student *pre=start,*t =  NULL ;
    if(head==NULL){
        printf("\n List is empty..");
        return -1;
    }
    if(start==head || start->data == item){
        if(start->data == item){
            return deleteAtBegin();
        }
        else{
            printf("\n Destination not found...");
            return -1;
        }
    }
    else{
        while(pre->ptr->ptr)
        {
            if(pre->ptr->data == item){
                t=pre->ptr;
                pre->ptr = t->ptr;
                free(t);
                return item;
            }
            pre=pre->ptr;
        }
        if(head->data == item)
            return deleteAtEnd();
        else{
            printf("\n Destination not found...");
            return -1;
        }
    }
}


void reverse(){
    struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
    struct Student *pre = (struct Student *)malloc(sizeof(struct Student));
    struct Student *next = (struct Student *)malloc(sizeof(struct Student));
    pre=NULL;
    temp=start;
    if(start ==NULL)
    {
        printf("\n List is empty...");
    }
    else if(start == head)
    {

        printf("Reverse Operation Done... ");
    }
    else
    {
        head=start;
        while(temp!=NULL)
        {
            next = temp->ptr;
            temp->ptr=pre;

            pre=temp;
            temp=next;
        }
        start=pre;

    }

}


void display(){
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    p=start;
    printf("\n\n The Link list is :  ");
    while(p)
    {
        printf("\n\t\t  %d",p->data);
        p=p->ptr;
    }
}


float avg(){
    int sum=0;
    int count=0;
    struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
    temp=start;
    while(temp!=NULL)
    {
      sum+=temp->data;
      temp = temp->ptr;
      count+=1;
    }
    return sum/count;
}


void count_item_occurrences(int item){
    int count=0;
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    p=start;
    if(p==NULL)
        printf("\n\nList is empty........\n\n");
    while(p)
    {
        if(p->data==item)
            count+=1;
        p=p->ptr;
    }
    printf("The number of occurrences of %d element in the list is : %d ",item,count);
    return;
}


void sort(){
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    p=start;
    int t,temp;
    int arr[100];
    int i =0;
    while(p)
    {
        arr[i++] = p->data;
        p=p->ptr;
    }
    //sorting array...
    for(int j =0;j<i;j++){
        t = j;
        for(int k = j+1;k<i;k++){
            if(arr[t] > arr[k])
                t = k;
        }
        temp = arr[t];
        arr[t] = arr[j];
        arr[j] = temp;
    }

    printf("\nThe Sorting list is: \n");
    for(int j = 0;j<i;j++)
        printf("\t%d",arr[j]);
    printf("\n\n");
}


int count(){
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    p=start;
    int c = 0;
    while(p)
    {
        c++;
        p=p->ptr;
    }
    return c;
}






