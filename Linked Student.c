#include<stdio.h>
#include<stdlib.h>

struct student
{
    int rno;
    char name[20];
    float marks;
    struct student *link;
};

typedef struct student *NODE;
NODE create_node();
NODE insert_front(NODE head);
void display(NODE head);

void max_marks(NODE head);
void name_compare(NODE head);

void display(NODE head);

int main()
{
    NODE head=NULL;
    int choice;
    while(1)
    {
        printf("Enter the choice\n");
        printf(" 1.Insert front\n 2.Display\n 3.max marks\n 4.name_compare\n 5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : head = insert_front(head);
            break;
            case 2 : display(head);
            break;
            case 3 : max_marks(head);
            break;
            case 4 : name_compare(head);
            break;
            case 5 : exit(0);
            break;
            default :printf("Invalid choice\n");
            break;
        }
    }

    return 0;

}
NODE create_node()
{
    NODE n1;
    n1=(struct student*)malloc(sizeof(struct student));
    if(n1==NULL)
    {
        printf("Couldn't allocate Memory\n");
        exit(0);
    }
    printf("Enter number \n");
    scanf("%d%s%f",&n1->rno,n1->name,&n1->marks);
    n1->link=NULL;
    return n1;
}
NODE insert_front(NODE head)
{
    NODE newNode;
    newNode = create_node();
    if(head==NULL)
       {
           head=newNode;
       }
    else
    {
        newNode-> link = head;
        head=newNode;
    }
    return head;

}
void display(NODE head)
{
    NODE temp;
    temp = head;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t%s\t%f\t",temp->rno,temp->name,temp->marks);
            temp=temp->link;
        }
        printf("\n");
    }
}
void max_marks(NODE head)
{
    int max=0;
    NODE cur;
    cur=head;
    while(cur!=NULL)
    {
    if(cur->marks>max)
    {
        max=cur->marks;
    }
     cur=cur->link;
    }
    printf("The student who scored max marks=%d ",max);
}
void name_compare(NODE head)
{
    int count=0;
    NODE cur;
    cur=head;
    char sname[20];
    printf("enter the name");
    scanf("%s",sname);
    while(cur!=NULL)
    {
    if(strcmp(cur->name,sname)==0)
    {
        count++;
    }
    cur=cur->link;
    }
    printf("number of students with similar name = %d",count);
}
