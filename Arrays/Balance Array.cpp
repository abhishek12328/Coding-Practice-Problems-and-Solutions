int Solution::solve(vector<int> &a) {

    int n=a.size(),i,j,evensum,oddsum,evenb,oddb,count =0;
        if(n==1)
    return 1;
    vector<long long int> even(n,0);
    vector<long long int> odd(n,0);
    even[0] = a[0];
    if(n>1)
    odd[1] = a[1];
    for(i=2;i<n;i++){
        if(i%2 == 0){
        even[i] = even[i-2]+a[i];
        evensum = even[i];
        // cout << even[i];
        }
        if(i%2 == 1){
        odd[i] = odd[i-2]+a[i];
        oddsum = odd[i];
        //cout << odd[i];
        }
    }
    for(i=0;i<n;i++){
        if(i==0){
        evenb = oddsum;
        oddb = evensum - even[i];
        if(evenb == oddb)
        count++;            
        }
        else if(i==1){
        evenb = even[i-1]+oddsum - odd[i];
        oddb = evensum - even[i-1];
        if(evenb == oddb)
        count++;
        }
        else if(i%2==1){
        evenb = even[i-1]+oddsum - odd[i];
        oddb = odd[i-2] + evensum - even[i-1];
        if(evenb == oddb)
        count++;
        }
        else if(i%2==0){
        evenb = even[i-2] + oddsum - odd[i-1];
        oddb = odd[i-1] + evensum - even[i];
        if(evenb == oddb)
        count++;
        }
    }
    return count;
}
