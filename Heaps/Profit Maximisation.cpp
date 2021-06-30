/*Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.

------------------------------------------------
------------------------------------------------*/


int Solution::solve(vector<int> &A, int B) {
    int n = A.size(),i;
    priority_queue<int> q;
    for(i=0;i<n;i++){
        q.push(A[i]);
    }
    int ans=0;
    for(i=0;i<B;i++){
        ans = ans + q.top();
        q.push(q.top()-1);
        q.pop();
    }
    return ans;
}
