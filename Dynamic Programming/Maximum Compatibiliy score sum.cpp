/*There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).

Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.
You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

Given students and mentors, return the maximum compatibility score sum that can be achieved.

 -----------------------------------------------------------------------------------------------------
 -----------------------------------------------------------------------------------------------------*/



class Solution {
public:
    bool valid(int a,int i){
        return (a & (1<<i));
    }
    void makevalid(int &a,int j){
         a = (a ^ (1<<j));
    }
    void makeinvalid(int &a,int j){
         a = (a ^ (1<<j));
    }
    
    int solve(vector<vector<int>> &dp, int valstud,int valment,vector<vector<int>>& students,vector<vector<int>>& mentors){
        if(dp[valstud][valment] != -1)
            return dp[valstud][valment];
        
        
        int max_val = 0;
        for(int i=0;i<students.size();i++){
            if(valid(valstud,i)){
                makeinvalid(valstud,i);
                for(int j=0;j<mentors.size();j++){
                    if(valid(valment,j)){
                        makeinvalid(valment,j);
                        int temp=0;
                        for(int k=0;k<students[0].size();k++){
                            if(students[i][k]==mentors[j][k])
                                temp++;
                        }
                        max_val = max(max_val,temp+solve(dp,valstud,valment,students,mentors));
                        makevalid(valment,j);
                    }
                }
                makevalid(valstud,i);
            }
        }
        return dp[valstud][valment] = max_val ;
    }
        
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int valstud = pow(2,students.size())-1,valment = pow(2,mentors.size())-1;
        vector<vector<int>> dp(valstud+1,vector<int>(valment+1,-1));
        dp[0][0] = 0; 
        return solve(dp,valstud,valment,students,mentors);
    }
};
