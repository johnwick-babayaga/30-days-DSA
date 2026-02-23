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
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> newM(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            newM[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = newM;
}
void rotateMatrix2(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

vector<int> spiralMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
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
    // rotateMatrix2(matrix);
    // printMatrix(matrix);

    vector<int> result = spiralMatrix(matrix);
    printVector(result);
}