/*You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int min = INT_MAX;
        int count = 0,n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(matrix[i][j]) < min)
                    min = abs(matrix[i][j]);
                if(matrix[i][j]<0)
                    count++;
                ans += abs(matrix[i][j]);
            }
        }
        if(count % 2 == 0)
            return ans;
        
            return ans - 2*min;
        
    }
};
