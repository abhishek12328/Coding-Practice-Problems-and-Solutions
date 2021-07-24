/*The letter value of a letter is its position in the alphabet starting from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).

The numerical value of some string of lowercase English letters s is the concatenation of the letter values of each letter in s, which is then converted into an integer.

For example, if s = "acb", we concatenate each letter's letter value, resulting in "021". After converting it, we get 21.
You are given three strings firstWord, secondWord, and targetWord, each consisting of lowercase English letters 'a' through 'j' inclusive.

Return true if the summation of the numerical values of firstWord and secondWord equals the numerical value of targetWord, or false otherwise.


------------------------------------------------------------------------------
------------------------------------------------------------------------------*/


class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a=0,b=0,c=0;
        string f,s,t;
        
        for(int i=0;i<firstWord.size();i++)
            a = a*10+(firstWord[i]-'a');
        
        
        for(int i=0;i<secondWord.size();i++)
            b = b*10+(secondWord[i]-'a');
        
        for(int i=0;i<targetWord.size();i++)
            c = c*10+(targetWord[i]-'a');
        
        if(a+b==c)
            return true;
        return false;
    }
};
