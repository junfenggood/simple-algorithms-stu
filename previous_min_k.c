#include<stdio.h>

int divide(int* a, int left, int right)
{
	int i=left+1,j=right,tem;
	while(i<j){
		for(;a[i]<a[left] && i<right;i++);
		for(;a[j]>a[left] && j>left;j--);
		if(i<j){
			tem = a[j];
			a[j]=a[i];
			a[i]=tem;
		}		
	}
	tem = a[j]; a[j]=a[left]; a[left]=tem;
	for (i=0; i<10;i++)
		printf("%d\t", a[i]);
	printf("\n");
	return j;
}

void quick(int* a, int left, int right, int k)
{
	int mid = divide(a, left, right);
	if(mid != k)
	{
		if(mid>k)
			quick(a, left, mid-1,k);
		if(mid<k)
			quick(a, mid+1, right, k);
	}	
}

int main()
{
	int a[10] = {7,14,16,21,18,39,13,28,6,2};
	int i;
	quick(a, 0,9, 4);
	for (i=0; i<5;i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
