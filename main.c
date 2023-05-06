#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void){    
    node *list = NULL;

    // (1) Add a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL){
        return 0;
    }    
    n->number = 1; // (*n).number = 1;
    n->next = NULL;    
    list = n; // Update list to point to new node

    // (2) Add a number to list
    n = malloc(sizeof(node));
    if(n == NULL){
        free(list);
        return 0;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // (3) Add a number to list
    n = malloc(sizeof(node));
    if(n == NULL){        
        free(list->next);
        free(list);
        return 0;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Print list
    for(node *tmp = list; tmp!=NULL; tmp = tmp->next){
        printf("%i\n", tmp->number);
    }
    
    // Free list
    while (list != NULL){
        node *tmp = list->next;
        free(list);
        list = tmp;
    }    

    return 0;
}