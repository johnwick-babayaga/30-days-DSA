#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
void printMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
}

// BRUTE APPROACH- SET ZEROES
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    auto mRows = [&](int i)
    {
        for (int k = 0; k < m; k++)
        {
            if (matrix[i][k] != 0)
            {
                matrix[i][k] = -1;
            }
        }
    };
    auto mColumns = [&](int j)
    {
        for (int k = 0; k < n; k++)
        {
            if (matrix[k][j] != 0)
            {
                matrix[k][j] = -1;
            }
        }
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                mRows(i);
                mColumns(j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
// BETTER APPROACH
void setMatrixZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> row(n, 0); // matrix[..][0]
    vector<int> col(m, 0); // matrix[0][..]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                col[j] = 1;
                row[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}
// OPTIMAL APPROACH
void optimalSetZeores(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row as zero
                matrix[i][0] = 0;
                // mark j-th column as zero
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    printMatrix(matrix);
    cout << endl;
    // setZeroes(matrix);
    setMatrixZeroes(matrix);
    optimalSetZeores(matrix);
    printMatrix(matrix);
}