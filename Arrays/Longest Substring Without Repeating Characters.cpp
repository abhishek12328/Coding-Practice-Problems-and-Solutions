/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int templen = 0, ans =0 ,start = 0;
        for(int i=0;i<s.length();i++){

            if(mp.count(s[i]) == 0 || (mp.count(s[i])>0 && mp[s[i]]<start) ){

                mp[s[i]] = i;
                templen++;
                if(templen > ans){
                    ans = templen;
                }
            }
            else{
                templen = i-mp[s[i]];
                start = mp[s[i]]+1;
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};

