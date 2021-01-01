#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
} Node;

int main(void)
{
    Node* head = NULL;
    Node* tail = NULL;
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

        if (head == NULL) // newNode is first node
            head = newNode;
        else // newNode is not first node
            tail->next = newNode;

        tail = newNode; // make tail point end of the list
    }
    printf("\n");

    // print inputted data
    printf("print all data you inputted! \n");
    if (head == NULL)
        printf("there is no natural number to print. \n");
    else
    {
        cur = head; // cur is first node
        printf("%d ", cur->data); // print first data

        while (cur->next != NULL) // is there linked node?
        {
            cur = cur->next; // make cur point next node
            printf("%d ", cur->data); // print node pointed by cur
        }
    }
    printf("\n\n");

    // free memory
    if (head == NULL)
        return 0; // there is no node to free
    else
    {
        Node* delNode = head;
        Node* delNextNode = head->next;

        printf("delete %d. \n", delNode->data);
        free(delNode); // delete first node

        while (delNextNode != NULL) // delete after first
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;
            
            printf("delete %d. \n", delNode->data);
            free(delNode);
        }
    }
    return 0;
}