/*Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

*/


int Solution::search(const vector<int> &a, int b) {
    int n = a.size(),i,l=0,r=n-1,mid;
    int ans;
    while(l<=r){
        mid = (l+r)/2;
        if((mid == 0 || a[mid]>a[mid-1]) && (mid == n-1 || a[mid]>a[mid+1])){
            break;
        }
        else if(((a[mid]>a[mid-1])||(mid==0))&&(a[0]<a[mid])){
            l = mid+1;
        }
        else
        r = mid-1;
    }
    l=0,r=mid;
    while(l<=r){
        int mid1 = (l+r)/2;
        if(a[mid1] == b)
        return mid1;
        else if(a[mid1]<b){
            l = mid1+1;
        }
        else{
            r = mid1-1;
        }
    }
    l= mid + 1, r =n-1;
    while(l<=r){
        int mid1 = (l+r)/2;
        if(a[mid1] == b)
        return mid1;
        else if(a[mid1]<b){
            l = mid1+1;
        }
        else{
            r = mid1-1;
        }
    }
    return -1;
}
