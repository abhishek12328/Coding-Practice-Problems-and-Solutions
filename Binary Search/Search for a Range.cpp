/*Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].

-------------------------------------------------------------------------
-------------------------------------------------------------------------*/

vector<int> Solution::searchRange(const vector<int> &a, int b) {
    int n = a.size(),i,l=0,r = n-1,mid=-1,start,end;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid] == b && (mid == 0 || a[mid-1]!=b))
        break;
        else if(a[mid] < b)
        l = mid +1;
        else
        r = mid -1;
    }
    start = mid;
    if(l>r)
    start = -1;
    l = 0, r = n-1;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid] == b && (mid == n-1 || a[mid+1]!=b))
        break;
        else if(a[mid] <= b)
        l = mid +1;
        else
        r = mid -1;
    }
    end = mid;
    if(l>r)
    end = -1;
    return {start,end};
    
}
