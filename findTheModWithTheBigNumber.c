#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER 101

void findTheMod(char* number1, int len1, char* number2, int len2)
{
	if (len1<len2)
	{
		return ;
	}else{
		if (strcmp(number1,number2) <= 0)
		{
			return ;
		}

		char pnum[NUMBER];
		char temp[NUMBER];
		strncpy(pnum, number2, NUMBER);
		strncpy(temp, number2, NUMBER);
		
		while(1){
			int token=0;
			int i;
			for (i = NUMBER-2; i >= NUMBER-len1-1; --i)
			{
				int sum = (number2[i]-'0')+(pnum[i]-'0')+ token;
				if (sum>=10)
				{
					number2[i] = sum- 10 +'0';
					token=1;
				}else{
					number2[i]=sum+'0';
					token=0;
				}

				if (i <= NUMBER-len2-1 )
				{
					if (token==0)
					{
						break;
					}
				}	
			}
			if(strcmp(number1,number2) < 0)
				break;
			strncpy(temp, number2, NUMBER);
		}
		int i;
		int token=0;
		for (i = NUMBER-2; i >= NUMBER-len1-1; --i)
		{
			if(number1[i]-token < temp[i])
			{
  				
  				number1[i] = number1[i]-token+10-temp[i]+'0';
  				token=1;
			}else{
				number1[i] = number1[i]-token-temp[i]+'0';
				token = 0;
			}
		}

	}
	
}

void print(char* number)
{
	char *p=number;
	while(*p == '0')
		p++;
	printf("%s\n", p);
}

int main(int argc, char const *argv[])
{
	char number1[NUMBER];
	char number2[NUMBER];
	scanf("%100s", number1);
	scanf("%100s", number2);
	int len1 = strlen(number1);
	int len2 = strlen(number2);
	memmove(number1+(NUMBER-len1-1), number1, len1+1);
	memmove(number2+(NUMBER-len2-1), number2, len2+1);
	memset(number1, '0', NUMBER-len1-1);
	memset(number2, '0', NUMBER-len2-1);

	// printf("%s\n", number1);
	// printf("%d\n",strlen(number1));
	// printf(number2);
	findTheMod(number1, len1, number2, len2);
	print(number1);
	return 0;
}