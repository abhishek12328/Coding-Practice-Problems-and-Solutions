/*The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

-----------------------------
-----------------------------
-----------------------------
-----------------------------*/




vector<int> f(int a, vector<int> v){
    if(a==1)
    return v;
    int n=v.size(),i,count=1;
    vector<int> r;
    if(n==1){
        r.push_back(1);
        r.push_back(1);
    }
    else{
    for(i=1;i<n;i++){
        if(v[i-1] == v[i])
        count++;
        else{
        r.push_back(count);
        r.push_back(v[i-1]);
        count = 1;
        }
    }
    r.push_back(count);
    r.push_back(v[n-1]);
    }
    return f(a-1,r);
}

string Solution::countAndSay(int a) {
    vector<int> v = f(a,{1});
    string s;
    for(int i=0;i<v.size();i++)
    s.push_back(v[i]+'0');
    return s;
    
}
