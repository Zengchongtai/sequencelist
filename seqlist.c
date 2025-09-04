#include <stdio.h>
#define MAX_DE 100
typedef int elementType;

typedef struct{
    elementType data[MAX_DE];
    int length;
}seqlist;


void initialise_seqlist(seqlist *L)
{
    L -> length = 0;
}

int add_seqlist(seqlist *L, elementType add_text)
{   
    if (L -> length >= MAX_DE)
    {
        printf("the list is full");
        return 0;
    }
    L -> data[L -> length] = add_text;
    L -> length++;
    return 1;
    
}

void cite_seqlist(seqlist *L)
{
    for (int i=0;i<L->length;i++)
    {
        printf("the %d one is: %d\n", i+1, L -> data[i]);
    }
}

void insert_seqlist(seqlist *L, int position ,int insert_text)
{   
    position--;//用户的位置和数组里的位置需要换算 用户输入-1=数组里的位置
    if (position > L -> length || position < 0){
        printf("failed\n");
        return;
    }
    int amount = L -> length - position;
    for (int i=0;i<=amount;i++)
    {
        L -> data[L -> length - i + 1] = L -> data[L -> length - i];
    }
    L -> length++;
    L -> data[position] = insert_text;

}


void delete_seqlist(seqlist *L, int position )
{
    position--;
    if (position > L -> length - 1 || position < 0)
    {
        printf("failed");
        return;
    }
    int amount = L -> length - position;
    for(int i=0;i<amount;i++)
    {
        L -> data[position+i] = L -> data[position + i + 1];
    }
    L -> length--;
}

int main()
{
    seqlist list;
    initialise_seqlist(&list);
    add_seqlist(&list, 100);
    add_seqlist(&list, 101);
    add_seqlist(&list, 102);
    add_seqlist(&list, 103);
    add_seqlist(&list, 104);
    add_seqlist(&list, 105);
    cite_seqlist(&list);
    printf("\n\n=============\n\n");
    insert_seqlist(&list,3,114514);
    printf("====have been inserted====\n\n");
    cite_seqlist(&list);
    printf("\n\n=============\n\n");
    delete_seqlist(&list,4);
    printf("====have been deleted====\n\n");
    cite_seqlist(&list);


    return 0;
}