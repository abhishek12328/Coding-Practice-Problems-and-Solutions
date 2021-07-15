/*Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 ----------------------------------------------------------
 ----------------------------------------------------------*/


class Solution {
public: 
    
    string removeOccurrences(string s, string part) {
        int n = part.size();
        auto itr = s.find(part);
        while(itr!=string::npos){
            s.erase(itr,n);
            itr = s.find(part);
        }
        return s;
    }
};
