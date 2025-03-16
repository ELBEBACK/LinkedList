#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedlist.h"


int main() {
    List_t lst = {};

    ListCtor(&lst);

    ListTailInsertion(&lst, 10);
    ListTailInsertion(&lst, 20);
    ListTailInsertion(&lst, 30);
    ListTailInsertion(&lst, 40);

    printf("Here is the first elem of list: %lf\n", lst.head->data);
    Node_t* adr = GetTailAddress(&lst);
    printf("%p  %p\n", lst.head->Next, adr);
    Node_t* adr1 = GetNthAddress(&lst, 2);
    printf("Here is the 2nd elem of list:  %lf\n", adr1->data);
    ListInsertion(&lst, 1, 35);
    printf("The current length: %d\n", lst.length);
    
    ListDump(&lst);

    ListDtor(&lst);
    
    return 0;
}



