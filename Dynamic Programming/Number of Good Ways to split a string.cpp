/*You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.


-------------------------------------------------------
-------------------------------------------------------*/



class Solution {
public:
    int numSplits(string s) {
        map<char,int> m1,m2;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
        }
               int count=0;
        for(int i=s.size()-1;i>0;i--){
            m1[s[i]]--;
            m2[s[i]]++;
            int count1=0,count2=0;
            for(char j='a';j<='z';j++){
                if(m1[j]) count1++;
                if(m2[j]) count2++;
            }
            if(count1 == count2)
                count++;
        }
               return count;
    }
};
