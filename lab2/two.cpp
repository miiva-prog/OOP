#include <iostream>

using namespace std;

int* genRandArray(int size,int maxValue);

int** genRandMatrix(int size,int maxValue);

int main()
{
    srand(time(NULL));

    int size = rand() % 10;
    int maxValue = 100;
    int **arr = (int **)malloc(sizeof(int*) * size);

    arr = genRandMatrix(size,maxValue);

    delete [] arr;

    return 0;
}

int* genRandArray(int size,int maxValue)
{
    srand(time(NULL));

    int *arr = new int[size];

    for(int n = 0;n < size;n++)
        arr[n] = rand() % (maxValue + 1);
    
    return arr;
}

int** genRandMatrix(int size,int maxValue)
{
    srand(time(NULL));

    int **arr = (int**)malloc(size * sizeof(int*));
    
    for(int n = 0;n < size;n++){        
        int randSize = rand() % (size + 1);
        int randMaxValue = rand() % (maxValue + 1);   
        arr[n] =  genRandArray(randSize,randMaxValue);

        for(int i = 0;i < randSize;i++)
            cout << arr[n][i] << " ";

        if(randSize == 0)
            cout << "0";
        
        cout << "\n";
    }
    
    return arr;
}