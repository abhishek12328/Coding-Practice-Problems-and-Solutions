/*Given a matrix of integers A of size N x M and an integer B.

Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.


-----------------------------------------------------------------------
------------------------------------------------------------------------*/


int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m = A.size(),n=A[0].size(),i,j,start = 0,end = m-1;
    int mid;
    while(start<=end){
         mid = (start+end)/2;
        if(A[mid][0]==B){
            return 1;
        }
        else if(A[mid][0]<B){
            if(mid == A.size()-1)
            break;
            else if(A[mid+1][0]>B)
            break;
            else
            start = mid+1;
        }
        else
        end = mid -1;
    }
    start = 0;
    end = n-1;
    while(start<=end){
        int mid1 = (start+end)/2;
        if(A[mid][mid1] == B)
        return 1;
        else if(A[mid][mid1]<B)
        start = mid1+1;
        else
        end = mid1 -1;
    }
    return 0;
}
