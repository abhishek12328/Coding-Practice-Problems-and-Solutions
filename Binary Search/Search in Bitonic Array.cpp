/*Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

--------------------------------------------------------------------
--------------------------------------------------------------------*/


int Solution::solve(vector<int> &a, int b) {
    int n = a.size(),i,l=0,r=n-1,mid;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid] == b)
        return mid;
        else if((a[mid]<b && (mid == n-1 || a[mid]<a[mid+1]))||(a[mid]>b && (mid == n-1 || a[mid]>a[mid+1]))){
            l = mid+1;
        }
        else if((a[mid]>b && (mid == n-1 || a[mid]<a[mid+1]))||(a[mid]<b && (mid == n-1 || a[mid]>a[mid+1]))){
            r = mid-1;
        }
    }
    return -1;
}
