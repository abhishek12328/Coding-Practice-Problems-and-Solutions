/*Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.

------------------------------------------------------
------------------------------------------------------*/



string Solution::solve(string a) {
    queue<char> q;
    map<char,int> m;
    string ans;
    for(int i=0;i<a.size();i++){
        if(q.empty()){
            if(!m[a[i]]){
            ans.push_back(a[i]);
            q.push(a[i]);
            m[a[i]]++;
            }
            else
            ans.push_back('#');

        }
        else if(q.front() == a[i]){
            m[a[i]]++;
            while(!q.empty() && m[q.front()]>1)
            q.pop();
            if(!q.empty())
            ans.push_back(q.front());
            else
            ans.push_back('#');
        }
        else{
            ans.push_back(q.front());
            if(!m[a[i]])
            q.push(a[i]);
            m[a[i]]++;

        }
    }
    return ans;
}
