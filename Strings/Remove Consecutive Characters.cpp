/*Given a string A and integer B, remove all consecutive same characters that have length exactly B.

-----------------------------------
-----------------------------------
-----------------------------------
-----------------------------------*/


string Solution::solve(string a, int b) {
    if(b==1)
    return NULL;
    int i,n=a.size();
    vector<int> v;
    string s;
    int count=1;
    for(i=1;i<n;i++){
        if(a[i]==a[i-1]){
            count++;
            if(count == b){
                v.push_back(i);
                i++;
                count = 1;
            }
        }
        else
        count=1;
    }
    if(!v.size())
    return a;
    int j=0,flag=0;
    for(i=0;i<a.size();i++){
        while(v[j]-b+1<=i && i<v[j]){
        i++;
        flag =1;
        }
        if(flag==1){
        j++;
        flag=0;
        continue;
        }
        s.push_back(a[i]);
        
    }
    return s;
}
