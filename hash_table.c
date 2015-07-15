#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define NUMBER 10

typedef struct _NODE{
   int data;
   struct _NODE *next;
}Node;

typedef struct _HASH_TABLE{
    Node* value[NUMBER];
}HASH_TABLE;

typedef int STATUS;

HASH_TABLE* create_hashtable()
{
    HASH_TABLE* htable=(HASH_TABLE*)malloc(sizeof(HASH_TABLE));
    memset(htable, 0, sizeof(HASH_TABLE));
    return htable;
}

STATUS insert_data(HASH_TABLE *hash_tab, int data)
{
    Node* pnode=NULL;

    if(NULL == hash_tab)
        return FALSE;

    if(NULL == (hash_tab->value[data%10]))
    {
        pnode = (Node*)malloc(sizeof(Node));
        memset(pnode, 0, sizeof(Node));
        pnode->data = data;
        hash_tab->value[data%10] = pnode;
        return TRUE;
    }

    pnode = hash_tab->value[data%10];
    while(pnode->next)
        pnode=pnode->next;

    pnode->next = (Node*)malloc(sizeof(Node));
    memset(pnode->next, 0, sizeof(Node));
    pnode->next->data = data;

    return TRUE;
}

STATUS delete_data(HASH_TABLE* hash_tab, int data)
{
    Node* pnode;
    Node* phead;
    if(NULL == hash_tab ){
        puts("Hash table is empty!!");
        return FALSE;
    }
    if(NULL == (pnode=hash_tab->value[data%10])){
        puts("Data is not exits");
        return FALSE;
    }

    if(pnode->data == data)
    {
        hash_tab->value[data%10] = pnode->next;
        free(pnode);
        return TRUE;
    }

    phead=hash_tab->value[data%10];
    while(phead->next)
    {
        if(phead->next->data == data)
        {
            pnode=phead->next;
            phead->next=pnode->next;
            free(pnode);
            return TRUE;
        }
        phead=phead->next;
    }

    puts("Data is not exits");
    return FALSE;
}

STATUS delete_all_data(HASH_TABLE* hash_tab)
{
    int i;
    Node* pnode;
    Node* pnext;

    if(NULL == hash_tab)
        return TRUE;

    for(i=0; i<NUMBER; i++)
    {
        if(hash_tab->value[i] != NULL)
        {
            pnode = hash_tab->value[i];
            hash_tab->value[i]=NULL;
            while(pnode){
                pnext=pnode->next;
                free(pnode);
                pnode=pnext;
            }
        }
    }
    free(hash_tab);
    return TRUE;

}

void print_hash_data(HASH_TABLE* hash_tab)
{
    int i;
    int flag=0;
    Node* pnode;
    if(NULL == hash_tab)
        printf("Hash table is not exits!\n");
    for(i=0; i<NUMBER; i++)
    {
        if(hash_tab->value[i] != NULL)
        {
            flag++;
            pnode = hash_tab->value[i];
            while(pnode)
            {
                printf("%d\t", pnode->data);
                pnode = pnode->next;
            }
        }
    }
    if(flag==0)
        printf("hash table is empty!\n");
    printf("\n");
}

void use_guide()
{
    printf("User Guide:\n0.Quit\n1.Insert data\n2.Delete data\n3.Print data\nPlease enter number:");
}

int main()
{
    HASH_TABLE* hash=NULL;
    int x,data;
    STATUS status;
    hash = create_hashtable();

    do{
        use_guide();
        scanf("%d",&x);
        switch(x)
        {
        case 0:
            delete_all_data(hash);
            break;
        case 1:
            printf("Please enter a number to insert, end with -1:");
            scanf("%d", &data);
            while(data != -1)
            {
                insert_data(hash, data);
                scanf("%d", &data);
            }

            break;
        case 2:
            printf("Please enter a number to delete:");
            scanf("%d", &data);
            status=delete_data(hash, data);
            break;
        case 3:
            printf("Print data:\n");
            print_hash_data(hash);
            break;
        default:
            puts("Please select the right number!\n");
            break;
        }
    }while(x != 0);

     return 0;
}
