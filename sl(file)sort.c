#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void writeToFile(NODE head);
NODE readFromFile();
void sort_by_roll(NODE head);

int main()
{
    NODE head = NULL;
    int choice;
    head = readFromFile(); // Read data from the file at the beginning

    while (1)
    {
        printf("Enter the choice\n");
        printf(" 1.Insert front\n 2.Display\n 3.Max marks\n 4.Name compare\n 5.Write to file and exit\n 6.Sort by roll number\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = insert_front(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            max_marks(head);
            break;
        case 4:
            name_compare(head);
            break;
        case 5:
            writeToFile(head); // Write data to file
            exit(0);          // Exit the program
        case 6:
            sort_by_roll(head);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

NODE create_node()
{
    NODE n1;
    n1 = (struct student *)malloc(sizeof(struct student));
    if (n1 == NULL)
    {
        printf("Couldn't allocate Memory\n");
        exit(0);
    }
    printf("Enter number \n");
    scanf("%d%s%f", &n1->rno, n1->name, &n1->marks);
    n1->link = NULL;
    return n1;
}

NODE insert_front(NODE head)
{
    NODE newNode;
    newNode = create_node();
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->link = head;
        head = newNode;
    }
    return head;
}

void display(NODE head)
{
    NODE temp;
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\t%s\t%f\n", temp->rno, temp->name, temp->marks);
            temp = temp->link;
        }
    }
}

void max_marks(NODE head)
{
    float max = 0;
    NODE cur;
    cur = head;
    while (cur != NULL)
    {
        if (cur->marks > max)
        {
            max = cur->marks;
        }
        cur = cur->link;
    }
    printf("The student who scored max marks = %f\n", max);
}

void name_compare(NODE head)
{
    int count = 0;
    NODE cur;
    cur = head;
    char sname[20];
    printf("Enter the name: ");
    scanf("%s", sname);
    while (cur != NULL)
    {
        if (strcmp(cur->name, sname) == 0)
        {
            count++;
        }
        cur = cur->link;
    }
    printf("Number of students with similar name = %d\n", count);
}

void writeToFile(NODE head)
{
    FILE *file;
    NODE temp;
    temp = head;

    file = fopen("student_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (temp != NULL)
    {
        fprintf(file, "%d %s %f\n", temp->rno, temp->name, temp->marks);
        temp = temp->link;
    }

    fclose(file);
    printf("Data written to file successfully\n");
}

NODE readFromFile()
{
    FILE *file;
    NODE head = NULL;
    NODE newNode, temp;

    file = fopen("student_data.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }

    while (!feof(file))
    {
        newNode = (NODE)malloc(sizeof(struct student));
        if (newNode == NULL)
        {
            printf("Couldn't allocate Memory\n");
            exit(0);
        }

        fscanf(file, "%d %s %f\n", &(newNode->rno), newNode->name, &(newNode->marks));
        newNode->link = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->link = newNode;
            temp = temp->link;
        }
    }

    fclose(file);
    printf("Data read from file successfully\n");
    return head;
}

void sort_by_roll(NODE head)
{
    NODE cur, prev;
    int swapped;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        swapped = 0;
        cur = head;
        while (cur->link != NULL)
        {
            prev = cur;
            cur = cur->link;
            if (cur->rno < prev->rno)
            {
                // Swap the nodes
                prev->link = cur->link;
                cur->link = prev;
                if (prev == head)
                {
                    head = cur;
                }
                else
                {
                    NODE temp = head;
                    while (temp->link != prev)
                    {
                        temp = temp->link;
                    }
                    temp->link = cur;
                }
                swapped = 1;
            }
        }
    } while (swapped);

    printf("List sorted by roll number\n");
}
