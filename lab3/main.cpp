#include <iostream>
#define SIZE 5

using namespace std;

class matrix
{
    private:
        int sum_elements = 0;
        int row,col;

    public:
        int **arr;

        int get_sum_elements()
        {
            return sum_elements;
        }

        int get_rows()
        {
            return row;
        }

        int get_cols()
        {
            return col;
        }

        matrix init_matrix()
        {
            arr = (int **)malloc(sizeof(int*));
            row = 0; col = 0;
        }

        matrix init_single_matrix(int size)
        {
            row = col = size;
            arr = (int **)malloc(sizeof(int*) * size);

            for(int n = 0;n < size;n++)
                arr[n] = (int *)malloc(sizeof(int) * size);

            for(int n = 0;n < size;n++)
                for(int i = 0;i < size;i++)
                    arr[n][i] = 0;
                
            for(int i = 0;i < size;i++)
                arr[i][i] = 1;
        }

        matrix init_set_matrix(int rows,int cols)
        {
            row = rows;
            col = cols;

            arr = (int **)malloc(sizeof(int*) * row);

            for(int n = 0;n < row;n++)
                arr[n] = (int *)malloc(sizeof(int) * col);
        }

        int** write_matrix()
        {
            cout << "Write rows -> ";
            cin >> row;

            cout << "Write cols -> ";
            cin >> col;

            init_set_matrix(row,col);

            for(int n = 0;n < row;n++){
                for(int i = 0;i < col;i++){
                    cout << "arr[" << n << "]" << "[" << i << "] -> ";
                    cin >> arr[n][i];
                }
            }

            return arr;
        }

        int** random_matrix(int rows,int cols)
        {
            row = rows;
            col = cols;

            srand(time(nullptr));

            init_set_matrix(row,col);

            for(int n = 0;n < row;n++)
                for(int i = 0;i < col;i++)
                    arr[n][i] = rand() % 10; 
            
            return arr;
        }

        void print_matrix()
        {
            cout << "\n";
            for(int n = 0;n < row;n++){
                for(int i = 0;i < col;i++){
                    cout << arr[n][i] << " ";
                }
                cout << "\n";
            }
        }

        void sum_elements_matrix()
        {
            for(int n = 0;n < row;n++)
                for(int i = 0;i < col;i++)
                    sum_elements += arr[n][i]; 
        }

        void free_matrix()
        {
            for(int n = 0;n < row;n++)
                free(arr[n]);

            free(arr);
        }
};

int main()
{
    matrix M1,M2,M3,M4;

    M1.init_matrix();
    M2.init_single_matrix(SIZE);
    M3.init_set_matrix(3,4);
    M4.init_set_matrix(2,3);

    M2.print_matrix();
    M3.print_matrix();
    M4.print_matrix();

    for(int n = 0;n < M2.get_rows();n++)
        for(int i = 0;i < M2.get_cols();i++)
            M2.arr[n][i] = n * i;

    M3.random_matrix(3,4);

    cout << "\n";

    M4.write_matrix();
    M3.sum_elements_matrix();

    cout << "\nprint M2\n";

    M2.print_matrix();

    cout << "\nprint M3\n";

    M3.print_matrix();

    cout << "\nsum -> " << M3.get_sum_elements() << "\n";
    cout << "\nprint M4\n";

    M4.print_matrix();

    M1.free_matrix();
    M2.free_matrix();
    M3.free_matrix();
    M4.free_matrix();

    return 0;
}