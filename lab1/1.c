#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* genRandArray(int size,int maxValue);

void print(int *arr);

int main()
{
    srand(time(NULL));

    int size = rand() % 10;
    int maxValue = 100;
    int *arr = genRandArray(size,maxValue);

    print(arr);
    free(arr);

    return 0;
}

int* genRandArray(int size,int maxValue)
{
    srand(time(NULL));

    int *arr = (int *)malloc(sizeof(int) * (size + 1));

    arr[0] = size;

    for(int n = 1;n < size + 1;n++)
        arr[n] = rand() % (maxValue + 1);
    
    return arr;
}

void print(int *arr)
{
    printf("%d: ",arr[0]);

    for(int n = 1;n < arr[0] + 1;n++)
        printf("%d ",arr[n]);

    printf("%c",'\n');
}