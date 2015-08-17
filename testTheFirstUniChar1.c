#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findTheUni(char* p)
{
	char* ptr1=p;
	char* ptr2=p;
	if (p==NULL)
	{
		return '\0';
	}
    if (strlen(p)==1)
    {
    	return *p;
    }

	while(*ptr1 != '\0'){
		
        if (*ptr1==*ptr2 && ptr1 != ptr2)
        {
        	ptr2++;
        	ptr1=p;
        }else{
        	ptr1++;
        }
	}
	return *ptr2;

}

int main()
{
	int line;
	int i;
	scanf("%d",&line);
	char** array = (char**)malloc(sizeof(char*)*line);
	char buf[255];
	for (i = 0; i < line; ++i)
	{
		scanf("%s", buf);
		array[i]=strdup(buf);
	}
	for (i = 0; i < line; ++i)
	{
		char df=findTheUni(array[i]);
		printf("%c\n", df);
		free(array[i]);
	}
	free(array);		

    return 0;

}