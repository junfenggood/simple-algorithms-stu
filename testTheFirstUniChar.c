#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findTheUni(char* p)
{
	char theUni;
	char* ptr1=p;
	char* ptr2=p;
	theUni = *p;
	if (p==NULL)
	{
		return '\0';
	}
    if (strlen(p)==1)
    {
    	return *p;
    }

	while(*ptr1 != '\0'){
		
        if (*ptr1==theUni && ptr1 != ptr2)
        {
        	theUni = *(++ptr2);
        	ptr1=p;
        }else{
        	ptr1++;
        }
	}
	return theUni;

}
struct list
{
	char* value;
	struct list * next;
};

void insertdata(struct list ** head, char* p)
{
	struct list * tmp;
	struct list * he;
	tmp = (struct list *)malloc(sizeof(struct list));
	char *data = strdup(p);
	tmp->value = data;
	tmp->next=NULL;
	if (*head==NULL)
	{
		*head = tmp;
	}
	else{
		he = *head;
        while(he->next);
        he->next = tmp;
	}
}

int main()
{
	int line;
	int i;
	struct list *head=NULL;
	
	scanf("%d",&line);
	// char* array = (char*)malloc(sizeof(char)*line);
	printf("hellolo\n");
	for (i = 0; i < line; ++i)
	{
        char buf[254];
		scanf("%s", buf);
		insertdata(&head, buf);
	}
    struct list *phead;
	while(head)
	{
		printf("%s\n", head->value);
		char df = findTheUni(head->value);
		printf("%c\n", df);
		phead=head->next;
		free(head->value);
		free(head);
		head = phead;
	}		

    return 0;

}