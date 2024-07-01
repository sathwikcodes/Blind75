class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns
        
        // Create a copy of the original matrix
        vector<vector<int>> visited = matrix;
        
        // First pass: Identify rows that should be set to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) { // If an element is zero
                    // Set all elements in the current row to zero in the copy
                    for (int k = 0; k < m; k++) {
                        visited[i][k] = 0;
                    }
                }
            }
        }
        
        // Second pass: Identify columns that should be set to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) { // If an element is zero
                    // Set all elements in the current column to zero in the copy
                    for (int k = 0; k < n; k++) {
                        visited[k][j] = 0;
                    }
                }
            }
        }
        
        // Update the original matrix with the zeroed values from the copy
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = visited[i][j];
            }
        }
    }
};

// better approach using two arrays
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns

        vector<int> row(n, 0);    // Vector to mark rows to be zeroed
        vector<int> column(m, 0); // Vector to mark columns to be zeroed

        // First pass: mark the rows and columns that need to be zeroed
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }

        // Second pass: set matrix elements to zero based on the marks
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] == 1 || column[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


 // optimal approach using 1 array

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // step 3: Finally mark the 1st col & then 1st row:
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

    return matrix;
}