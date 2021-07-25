/*solve sudoku*/

bool valid(int r,int c,char ch,vector<vector<char> > &A)
{
    for(int i=0;i<9;i++)
       if(A[i][c]==ch)
         return false;
    for(int i=0;i<9;i++)
       if(A[r][i]==ch)
         return false;
    int x=3*(r/3),y=3*(c/3);
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
          if(A[i][j]==ch)
            return false;
    }
    return true;
}
bool sudoku(vector<vector<char> > &A)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j]=='.')
            {
                for(char c='1';c<='9';c++)
                {
                    if(valid(i,j,c,A))
                    {
                        A[i][j]=c;
                        if(sudoku(A))
                          return true;
                        A[i][j]='.';  
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void Solution::solveSudoku(vector<vector<char> > &A) 
{
    sudoku(A);
}
