/*The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.


----------------------------------------------------------------------------------
----------------------------------------------------------------------------------*/


void solve(vector<vector<string>>& ans,vector<string> v,vector<int> col, int a, int presentrow){
    
    if(presentrow == a+1){
    ans.push_back(v);
    return;
    }
    
    vector<int> temp(a+1,0);
    for(int i=1;i<=a;i++){
        if(col[i]!=0){
            temp[i] = 1;
            if(i-(presentrow-col[i])>=1){
                temp[i-(presentrow-col[i])] = 1; 
            }
            if(i+(presentrow-col[i])<=a){
            temp[i+(presentrow-col[i])] = 1;
            }
        }
    }
    for(int i=1;i<=a;i++){
        string tryrow(a,'.');
        if(temp[i]==0){
            tryrow[i-1] = 'Q';
            v.push_back(tryrow);
            col[i] = presentrow;
            solve(ans,v,col,a,presentrow+1);
            col[i] = 0;
            v.pop_back();
        }
        
    }
}
 
 
vector<vector<string>> Solution::solveNQueens(int a) {
    
    vector<vector<string>> ans;
    vector<int> col(a+1,0);
    vector<string> v;
    solve(ans,v,col,a,1);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
