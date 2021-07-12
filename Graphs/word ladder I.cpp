/*Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


-----------------------------------------------------------
-----------------------------------------------------------*/

int Solution::solve(string a, string b, vector<string> &c) {
    unordered_map<string,vector<string>> m;
    int i=-1,k = c.size();
    while(i<=k){
        string temp = "";
        if(i == -1){ 
            temp = a;
        }
        else if(i==k) {
            temp = b;
        }
        else {
            temp = c[i];
        }
        for(int j=0; j<temp.size(); j++){
            string temp1 = temp;
            temp1[j] = '*';
            m[temp1].push_back(temp);
        }
        i++;
    }
    queue<string> q;
    unordered_map<string,int> visited;
    visited[a]  = 1;
    q.push(a);
    int dist=1;
    while(!q.empty()){
        int n = q.size();
        dist++;
        while(n--){
            string temp = q.front();
            q.pop();
            for(i=0;i<temp.size();i++){
                string temp1 = temp;
                temp1[i] = '*';
                for(int j=0;j<m[temp1].size();j++){
                if(visited[m[temp1][j]] == 0){
                if(m[temp1][j] == b)
                return dist;
                else{
                    visited[m[temp1][j]] = 1;
                    q.push(m[temp1][j]);
                }
                }
                }
            }
        }
    }
    return 0;
}
