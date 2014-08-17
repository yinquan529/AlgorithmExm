#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct List{
    int number;
    char name[MAX];
    struct List *next;
} *LinkedList, Node;

LinkedList CreateList(LinkedList head);
void FreeList(LinkedList head);
void PrintList(LinkedList head);
int ListSearch(char* key, LinkedList head);
LinkedList InsertList(LinkedList head, LinkedList new, char* key);
LinkedList DeleteList(LinkedList head, char* key);
LinkedList InvertLink(LinkedList head);

int main() {
    LinkedList head;
    head = CreateList(head);

    if ( head != NULL ) {
        PrintList(head);

        ListSearch("Jan", head);

        printf("Please input the new item:\n");
        LinkedList new = (LinkedList)malloc(sizeof(Node));
        char data_name[MAX];
        int i;
        scanf("%s",data_name);
        for ( i = 0; i <= MAX; i++ ) {
            new->name[i] = data_name[i];
        }

        InsertList(head,new,"Jan");
        PrintList(head);

        PrintList(DeleteList(head, "Sun"));
        PrintList(InvertLink(head));

        FreeList(head);
    }
}

LinkedList CreateList(LinkedList head) {
    int data_num = 0;
    char data_name[MAX];
    LinkedList new;
    LinkedList pointer;
    int i;

    // Create header node
    head = (LinkedList)malloc(sizeof(Node));

    if ( head == NULL ) {
        printf("Memory allocate Failure!!\n");
        return NULL;
    }

    // Set operation pointer to head
    pointer = head;

    while (1) {
        data_num++;

        // Create a new node
        new = (LinkedList)malloc(sizeof(Node));
        scanf("%s", data_name);

        // Set the content of new node
        if ( data_name[0] == '0' ) {
            break;
        }

        new->number = data_num;
        for ( i = 0; i <= MAX; i++ ) {
            new->name[i] = data_name[i];
        }

        new->next = NULL;

        // Put the new node to list
        pointer->next = new;
        pointer = new;
    }

    return head;
}

void PrintList(LinkedList head) {
    LinkedList pointer;
    pointer = head;

    // traverse the list
    while ( pointer != NULL ) {
        if ( pointer->number > 0 ) {
            printf("##Input Data##\n");
            printf("Data Number : %d\n", pointer->number);
            printf("Data Name : %s\n", pointer->name);
        }
        pointer = pointer->next;
    }
}

void FreeList(LinkedList head) {
    LinkedList pointer;
    while ( head != NULL ) {

        // move forward head
        pointer = head;
        head = head->next;
        free(pointer);
    }
}

int ListSearch(char* key, LinkedList head) {
    LinkedList pointer = head;
    
    if ( key == NULL ||  key[0] == 0 ) {
        return -1;
    }

    while ( pointer != NULL ) {
        if ( !strcmp( pointer->name, key) ) {
            printf("##Search Key##\n");
            printf("Data Number is %d\n", pointer->number);
            printf("Data Name is %s\n", pointer->name);
            return 1;
        }

        pointer = pointer->next;
    }

    return 0;
}

LinkedList InsertList(LinkedList head, LinkedList new, char* key) {
    LinkedList pointer = head;
    while (1) {

        if ( key == NULL || key[0] == 0 ) {
            return NULL;
        }

        if ( pointer->next == NULL ) {
            new->next = NULL;
            head->next = new;
            break;
        }

        if ( !strcmp(pointer->name, key) ) {
            new->number = pointer->number+1;
            LinkedList numberpointer = pointer->next;
            while ( numberpointer != NULL ) {
                numberpointer->number++;
                numberpointer = numberpointer->next;
            }

            // Insert the new node
            new->next = pointer->next;
            pointer->next = new;
            break;
        }

        pointer = pointer->next;
    }

    return head;
}

LinkedList DeleteList(LinkedList head, char* key) {
    LinkedList pointer = head->next;
    LinkedList back;

    while (1) {
        if ( pointer == NULL ) {
            printf("Not Found !!\n");
            return NULL;
        }

        if ( key == NULL && key[0] == 0 ) {
            return NULL;
        }

        if ( !strcmp(pointer->name, key) ) {
            head->next = pointer->next;
            free(pointer);
            LinkedList newnumberp = head->next;
            while ( newnumberp != NULL ) {
                newnumberp->number--;
                newnumberp = newnumberp->next;
            }
            break;
        }

        back = pointer;
        pointer = pointer->next;

        if ( !strcmp(pointer->name, key) ) {
            back->next = pointer->next;
            free(pointer);
            LinkedList newnumberp = back->next;
            while ( newnumberp != NULL ) {
                newnumberp->number--;
                newnumberp = newnumberp->next;
            }
            break;
        }
    }

    return head;
}

LinkedList InvertLink(LinkedList head) {
    if ( head->next == NULL) {
        printf(" List is empty");
        return NULL;
    }

    LinkedList back = head->next;
    LinkedList pointer = back->next;
    LinkedList next;

    back->next = NULL;
    while ( pointer != NULL ) {
        next = pointer->next;
        pointer->next = back;
        back = pointer;
        pointer = next;
    }

    head->next = back;
    return head;
}
#endif //__LINKEDLIST__
