bool mycomp(const string a,const string b){
    string temp = a ,temp1 = a;
    string temp2 = b,temp3 = b;
    return temp.append(temp2) < temp3.append(temp1);
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    int i;
    int count =0 ;
    for(i=0;i<A.size();i++){
        if(A[i]==0)
        count++;
    }
    if(count == A.size())
    return "0";
    
    for(i=0;i<A.size();i++){
        v.push_back(to_string(A[i]));
    }
    sort(v.begin(), v.end(), mycomp);
    string ans = "";
    for(i=v.size()-1;i>=0;i--){
        ans.append(v[i]);
    }
    return ans;
}
