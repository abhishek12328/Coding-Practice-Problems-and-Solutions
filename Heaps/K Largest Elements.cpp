vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int> q;
    for(int i=0;i<A.size();i++)
    q.push(A[i]);
    vector<int> ans;
    for(int i=0;i<B;i++){
    ans.push_back(q.top());
    q.pop();
        
    }
    return ans;
}
