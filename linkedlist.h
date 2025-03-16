#ifndef LINKEDLIST_H
#define LINKEDLIST_H

enum ErrorCode{
    AllFine           = 0,
    ListAbscence      = 1,
    AllocationFault   = 2,
    OutOfRange        = 3,
    FileAbscence      = 4,
};

enum Constants{
    Uninitialized   = 0xAB0BA,
    MAXCapacity_lst = 0x0000F,
};


typedef double ListElem;

typedef struct Node_t{
    ListElem data;
    Node_t* Next;
}Node_t;

typedef struct List_t{
    Node_t* head;
    int length;
}List_t;


int ListCtor(List_t* lst);

int ListDtor(List_t* lst);

int ListVerificator(List_t* lst);//TODO -  //как работает конст для предохранения значений

int ListTailInsertion(List_t* lst, ListElem value);

Node_t* GetTailAddress(List_t* lst);

int ListInsertion(List_t* lst, int position, ListElem value);

int ListDump(List_t* lst);

Node_t* GetNthAddress(List_t* lst, int position);

#endif