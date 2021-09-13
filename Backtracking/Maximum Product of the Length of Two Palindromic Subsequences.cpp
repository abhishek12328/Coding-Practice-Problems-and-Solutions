/*Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.*/


class Solution {
public:
    bool ispalindrome(string s){
        int n = s.size();
        if(n==0)
            return 0;
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1])
                return 0;
        }
        return 1;
    }
    
    void fun(string& s, int n, int& ans,int ind,string t,string r){
        if(ispalindrome(t)&&ispalindrome(r)){
            if(ans<t.size()*r.size())
                ans = t.size()*r.size();
        }
        for(int i=ind;i<s.size();i++){
            if(n & (1<<i)){
                n = n ^ (1 << i);
                t.push_back(s[i]);
                fun(s,n,ans,i+1,t,r);
                t.erase(t.end()-1);
                r.push_back(s[i]);
                fun(s,n,ans,i+1,t,r);
                r.erase(r.end()-1);
                n = n ^ (1 << i);
            }
        }
        
    }
    
    
    int maxProduct(string s) {
       int n  = (1<<s.size())-1;
        int ans = 0;
        string t,r;
        fun(s,n,ans,0,t,r);
        return ans;
    }
};
