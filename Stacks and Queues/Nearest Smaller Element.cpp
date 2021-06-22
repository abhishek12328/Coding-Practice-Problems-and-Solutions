/*Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

----------------------------------------------------------
----------------------------------------------------------*/



vector<int> Solution::prevSmaller(vector<int> &a) {
    int n = a.size(),min = INT_MAX;
    vector<int> v(n,-1);
    map<int,int> m;
    v[0] = -1;
    m[a[0]] = -1;
    for(int i=1;i<n;i++){
        while(a[i-1]>=a[i]){
            a[i-1] = m[a[i-1]];
        }
        v[i] = a[i-1];
        m[a[i]] = a[i-1];
    }
    return v;
}
