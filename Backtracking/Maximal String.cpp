/*Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.


-------------------------------------------------------------------------
-------------------------------------------------------------------------*/


void sol(string a,int b,string & ma){
    if(b==0)
    return;
    
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            
            sol(a,b-1,ma);
            if(ma < a)
            ma = a;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

string Solution::solve(string a, int b) {
    // string so = a;
    // sort(so.begin(),so.end());
    // if(so == a)
    //     return so;
    // int start = 0;
    // for(int i=0;i<b;i++){
    //     char max = '0';
    //     int ind = -1;
    //     for(int j=start;j<a.size();j++){
    //         if(a[j]>max){
    //         max = a[j];
    //         ind = j;
    //         }
    //     }
    //     if(ind == start){
    //         i--;
    //         start++;
    //     }
    //     else{
    //     char temp = a[ind];
    //     a[ind] = a[start];
    //     a[start] = temp;
    //     }
    //     if(so == a)
    //     return so;
    // }
    // return a;
    
    // if(a.size()==1 || b==0)
    // return a;
    // string max = a;
    // for(int i=1;i<a.size();i++){
    //     string t = a;
    //     string s="";
    //     s.push_back(t[i]);
    //     char temp = t[0];
    //     t[0] = t[i];
    //     t[i] = temp;
    //     string k = solve(t.substr(1,t.size()-1),b-1);
    //     s+=k;
    //     // cout << s<<" ";
    //     if(max<s)
    //     max = s;
        
    // }
    // return max;
    string ma = a;
    sol(a,b,ma);
    return ma;
    
}
