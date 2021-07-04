/*Given an sorted array A of size N. Find number of elements which are less than or equal to B.

NOTE: Expected Time Complexity O(log N)

-------------------------------------------------------
-------------------------------------------------------*/

int Solution::solve(vector<int> &A, int B) {
    int l = 0,r=A.size()-1;
    
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(A[mid]>B){
        r = mid-1;
        }
        else if (A[mid] == B && (mid==A.size()-1 || A[mid+1]!=B)){
            return mid+1;
        }
        else if(A[mid]<=B){
            ans = mid +1 ;
        l = mid+1;
        }
        
    }
    return ans;
}
