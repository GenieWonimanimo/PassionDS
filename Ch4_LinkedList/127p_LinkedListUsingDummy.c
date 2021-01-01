#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
} Node;

int main(void)
{
    Node* head = (Node*)malloc(sizeof(Node)); // dummy node
    head->data = 0;
    head->next = NULL;
    Node* tail = head;
    Node* cur = NULL;

    Node* newNode = NULL;
    int readData;

    // input data
    while (1)
    {
        printf("Input natural number: "); scanf(" %d", &readData);
        if (readData < 1)
            break;

        // add node
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode; // make tail point end of the list
    }
    printf("\n");

    // print inputted data
    printf("print all data you inputted! \n");
    if (head == tail)
        printf("there is no natural number to print. \n");
    else
    {
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");

    // free memory
    if (head == tail)
        return 0; // there is no node to free
    else    
    {
        Node* delNode = NULL; // dummy
        Node* delNextNode = head->next; // first node
        while (delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;
            
            printf("delete %d. \n", delNode->data);
            free(delNode);
        }
    }
    return 0;
}