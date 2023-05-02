#include <bits/stdc++.h>
using namespace std;
#define N 999999

int given_matrix[] = {1, 2, 3, 0, 5, 6, 4, 7, 8};
// int given_matrix[] = {1, 2, 3, 4, 8, 6, 7, 5, 0};
// int given_matrix[] = {1, 2, 3, 4, 5, 6, 7, 0,8};
int target_matrix[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
// int target_matrix[] = {1, 2,3, 8, 0, 4,7, 6, 5};

// int input_array[];

int find_zero_index(int matrix[])
{

    for (int i = 0; i < 9; i++)
    {
        if (matrix[i] == 0)
        {
            return i;
        }
    }
}

void print_matrix(int matrix[])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << endl;
        }
        cout << matrix[i] << " ";
    }
    cout << endl;
}

int Count(int s[])
{
    int c = 0;
    for (int i = 0; i < 9; i++)
    {
        if (s[i] != 0 && s[i] != target_matrix[i])
        {
            c++;
        }
    }

    return c;
}

int DFS(int arr[], int pos, int given_matrix[], int n)
{
    int val = N;
    int given_matrix_copy[9];
    for (int i = 0; i < 9; i++)
    {
        given_matrix_copy[i] = given_matrix[i];
    }

    for (int i = 0; i < n; i++)
    {
        int duplicate[9];
        for (int i = 0; i < 9; i++)
        {
            duplicate[i] = given_matrix[i];
        }

        int temp = duplicate[pos];
        duplicate[pos] = duplicate[arr[i]];
        duplicate[arr[i]] = temp;

        int temp_val = Count(duplicate);

        if (temp_val < val)
        {
            val = temp_val;
            // int given_matrix_copy[9];
            for (int i = 0; i < 9; i++)
            {
                given_matrix_copy[i] = duplicate[i];
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        given_matrix[i] = given_matrix_copy[i];
    }

    return val;
}

int main()
{

    int solveable = Count(given_matrix);

    int level = 1;

    cout << "matrix number : " << level << endl;
    print_matrix(given_matrix);

    while (solveable > 0)
    {
        int pos = find_zero_index(given_matrix);
        level++;

        if (pos == 0)
        {
            int neighbours[] = {1, 3};
            solveable = DFS(neighbours, pos, given_matrix, 2);
        }
        else if (pos == 1)
        {
            int neighbours[] = {0, 2, 4};
            solveable = DFS(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 2)
        {
            int neighbours[] = {1, 5};
            solveable = DFS(neighbours, pos, given_matrix, 2);
        }
        else if (pos == 3)
        {
            int neighbours[] = {0, 4, 6};
            solveable = DFS(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 4)
        {
            int neighbours[] = {3, 5, 7};
            solveable = DFS(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 5)
        {
            int neighbours[] = {2, 4, 8};
            solveable = DFS(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 6)
        {
            int neighbours[] = {3, 7};
            solveable = DFS(neighbours, pos, given_matrix, 2);
        }
        else if (pos == 7)
        {
            int neighbours[] = {4, 6, 8};
            solveable = DFS(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 8)
        {
            int neighbours[] = {5, 7};
            solveable = DFS(neighbours, pos, given_matrix, 2);
        }

        cout << "matrix number : " << level << endl;
        print_matrix(given_matrix);
        
    }

    return 0;
}