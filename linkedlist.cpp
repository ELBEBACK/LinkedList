#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedlist.h"

int ListCtor(List_t* lst) {
    assert(lst);

    lst->head = (Node_t*) calloc(1, sizeof(Node_t));
    if (!lst->head) return AllocationFault;

    lst->head->Next = NULL;
    lst->head->data = Uninitialized;

    lst->length = 0;

    return AllFine;
}


int ListDtor(List_t* lst) {
    if (!lst) return ListAbscence;

    Node_t* current = lst->head;
    Node_t* temp = NULL;

    while (current) {
        temp = current;
        current = temp->Next;
        free(temp);
    }

    lst->head = NULL;
    lst->length = 0;

    return AllFine; 
}


int ListTailInsertion(List_t* lst, ListElem value) {
    if (!lst) return ListAbscence;

    lst->length++;

    if ( (int) lst->head->data == Uninitialized) {
        lst->head->data = value;
        return AllFine;
    }

    Node_t* current = GetTailAddress(lst);

    current->Next = (Node_t*) calloc(1, sizeof(Node_t));
    if (!current->Next) return AllocationFault;

    current->Next->Next = NULL;
    current->Next->data = value;

    return AllFine;
}


Node_t* GetTailAddress(List_t* lst) {
    if (!lst) return NULL;

    Node_t* current = NULL;
    for (current = lst->head; current->Next != NULL; current = current->Next) {}
       
    return current; //FIXME - //return ListVerificator //printf("%b\n", ElemLimitExceeded); 
}


int ListVerificator(List_t* lst) {
    if (!lst) return ListAbscence;

    //if
    
    return AllFine;
}


int ListInsertion(List_t* lst, int position, ListElem value) {
    if (!lst) return ListAbscence;
    if (position > lst->length) return OutOfRange;

    Node_t* current = lst->head;
    for (int counter = 0; counter < position - 1; current = current->Next);

    Node_t* temp = current->Next;
    current->Next = (Node_t*) calloc(1, sizeof(List_t));
    current->Next->data = value;
    current->Next->Next = temp;
    
    lst->length++;
    
    return AllFine;
}


int ListDump(List_t* lst) {
    FILE* f = fopen("dumpling.dot", "w");
    if (!f) {
        fprintf(stderr, "FILE's missing!\n");
        return FileAbscence;
    }
    
    fprintf(f, "digraph G{\n\t");

    Node_t* current = lst->head;

    while(current->Next) {
        fprintf(f, "Node%.0lf -> Node%.0lf;\n\t", current->data, current->Next->data);
        current = current->Next;
    }

    fprintf(f, "}");
    
    fclose(f);
    system("dot -T png -o dumpling.png dumpling.dot");
    system("rm dumpling.dot");

    return AllFine;
}

Node_t* GetNthAddress(List_t* lst, int position) {
    if (!lst) return NULL;
    if (position > lst->length) return NULL;
    
    Node_t* current = lst->head;
    for (int counter = 0; counter < position; counter++, current = current->Next);

    return current;
}