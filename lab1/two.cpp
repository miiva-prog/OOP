#include <iostream>

using namespace std;

int** genRandMatrix(int size,int maxValue);

void print(int **arr);

int* genRandArray(int size,int maxValue);

int main()
{
    srand(time(NULL));

    int size = rand() % 10;
    int maxValue = 100;
    int **arr = genRandMatrix(size,maxValue);

    print(arr);
    delete [] arr;

    return 0;
}

int* genRandArray(int size,int maxValue)
{
    srand(time(NULL));

    int *arr = new int[size + 1];

    arr[0] = size;

    for(int n = 1;n < size + 1;n++)
        arr[n] = rand() % (maxValue + 1);
    
    return arr;
}

int size_global;

int** genRandMatrix(int size,int maxValue)
{
    size_global = size;

    srand(time(NULL));

    int **arr = (int**)malloc(size * sizeof(int*));
    
    for(int n = 0;n < size + 1;n++)    
        arr[n] =  genRandArray(rand() % (size + 1),rand() % (maxValue + 1));
    
    return arr;
}

void print(int **arr)
{
    printf("%d\n",size_global);

    for(int n = 0;n < size_global;n++){
        printf("%d: ",arr[n][0]);
        for(int i = 1;i < arr[n][0] + 1;i++){
            printf("%d ",arr[n][i]);
        }
        printf("%c",'\n');
    }
}