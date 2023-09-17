#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

void print(int arr[N][N]);

int* task_A(int arr[N][N],int *arr2);

int* task_B(int arr[N][N],int *arr2);

int* task_C(int arr[N][N],int *arr2);

int* task_D(int arr[N][N],int *arr2);

int main()
{
    srand(time(NULL));

    int arr[N][N];
    int *arr2 = (int *)malloc(sizeof(int) * N * N);

    for(int n = 0;n < N;n++)
        for(int i = 0;i < N;i++)
            arr[n][i] = rand() % N;

    arr2 = task_A(arr,arr2);

    printf("\n\n");
    print(arr);
    free(arr2);

    return 0;
}

void print(int arr[N][N])
{
    for(int n = 0;n < N;n++){
        for(int i = 0;i < N;i++){
            printf("%d ",arr[n][i]);
        }
        printf("\n");
    }
}

int* task_A(int arr[N][N],int *arr2)
{
    int index = 0,cols = N - 1;
    int size = 0,rows = 0;

    while(size != N){
        while(cols != size - 1){
            arr2[index] = arr[rows][cols];
            index++;
            rows++;
            cols--;
        }
        size++;
        cols = N - 1;
        rows = size;
    }

    for(int i = 0;i < index;i++)
        printf("%d ",arr2[i]);

    return arr2;
}

int* task_B(int arr[N][N],int *arr2)
{
    int rows = 0,cols = 0;
    int size = 0,index = 0;

    while(size != N - 1){
        while(cols != N - 1 - (size - 1)){
            arr2[index] = arr[rows][cols];
            index++;
            rows++;
            cols++;
        }
        size++;
        rows = size;
        cols = 0;
    }

    arr2[index] = arr[N - 1][0];
    index++;

    for(int i = 0;i < index;i++)
        printf("%d ",arr2[i]);
    
    return arr2;
}

int* task_C(int arr[N][N],int *arr2)
{
    if(N == 1){
        printf("%d\n",arr[0][0]);
        return NULL;
    }

    int rows = N / 2,cols = N / 2;
    int size = 1,index = 0;

    while(index != N * N){
        if(size != 1){
            int size2 = size;

            arr2[index] = arr[rows][cols];
            index++;

            while(size != 0){
                if(index == N * N)
                    break;
                cols--;
                arr2[index] = arr[rows][cols];
                index++;
                size--;
            }

            size = size2 + 1;

            while(size != 0){
                if(index == N * N)
                    break;
                rows--;
                arr2[index] = arr[rows][cols];
                index++;
                size--;
            }

            size = size2 + 2;

            while(size != 0){
                if(index == N * N)
                    break;
                cols++;
                arr2[index] = arr[rows][cols];
                index++;
                size--;
            }

            size = size2 + 2;

            while(size != 0){
                if(index == N * N)
                    break;
                rows++;
                arr2[index] = arr[rows][cols];
                index++;
                size--;
            }

            size = size2 + 2;

            while(size != 0){
                if(index == N * N)
                    break;
                cols--;
                arr2[index] = arr[rows][cols];
                index++;
                size--;
            }
            size = size2;
        }else{
            arr2[index] = arr[rows][cols];
            index++;

            cols--;
            arr2[index] = arr[rows][cols];
            index++;

            rows--;
            arr2[index] = arr[rows][cols];
            index++;

            cols++;
            arr2[index] = arr[rows][cols];
            index++;

            cols++;
            arr2[index] = arr[rows][cols];
            index++;

            rows++;
            arr2[index] = arr[rows][cols];
            index++;

            rows++;
            arr2[index] = arr[rows][cols];
            index++;

            cols--;
        }
        size++;
    }

    for(int n = 0;n < index;n++)
        printf("%d ",arr2[n]);

    return arr2;
}

int* task_D(int arr[N][N],int *arr2)
{
    int rows = 0,cols = 0;
    int size = 1,index = 0;

    while(index != N * N){
        while(cols != N - size){
            if(index == N * N)
                    break;
            arr2[index] = arr[rows][cols];
            index++;
            cols++;
        }

        while(rows != N - size){
            if(index == N * N)
                    break;
            arr2[index] = arr[rows][cols];
            index++;
            rows++;
        }

        while(cols != size - 1){
            if(index == N * N)
                    break;
            arr2[index] = arr[rows][cols];
            index++;
            cols--;
        }

        while(rows != size){
            if(index == N * N)
                    break;
            arr2[index] = arr[rows][cols];
            index++;
            rows--;
        }
        size++;
    }

    for(int n = 0;n < index;n++)
        printf("%d ",arr2[n]);
    
    return arr2;
}