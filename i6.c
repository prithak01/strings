#include <stdio.h>
#include <stdlib.h>

int ll[256];

typedef struct Node
{
    int x;
    struct Node* next;
}Node;

int main (int argc, char *argv[])
{
    Node root, elem2;
    root.x = 15;
    root.next = malloc(sizeof(Node));
    root.next -> x = -2;
    root.next -> next = NULL;

    Node* curr = &root;
    while(curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

    printf("First: %d\n", root.x);
    printf("Second: %d\n", root.next -> x);

    free(root.next);

    return 0;
}