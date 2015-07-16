#include<stdio.h>

void insert_sort(int* a, int n)
{
    int i, j, key;
    for(i=1; i<n; i++){
        j=i-1;
        key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int a[10];
    int i;
    for(i=0; i<10;i++){
        scanf("%d",&a[i]);
    }
    puts("Before sort:\n");
    for(i=0; i<10;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    puts("After sort:\n");
    insert_sort(a, 10);
    for(i=0; i<10;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
