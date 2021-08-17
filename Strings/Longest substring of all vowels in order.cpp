/*A string is considered beautiful if it satisfies the following conditions:

Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.

A substring is a contiguous sequence of characters in a string.*/




class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int m=0,ta = 0;
        int i=0;
        while(i<n){
            if(word[i]=='a'){
                int t = 0;
                ta =0;
                while(i<n && word[i]=='a'){
                    t = t | 1; 
                    ta++;
                    i++;
                }
                while(i<n && word[i]=='e'){
                    t = t | (1<<1); 
                    ta++;
                    i++;
                }
                while(i<n && word[i]=='i'){
                    t = t | (1<<2);
                    ta++;
                    i++;
                }
                while(i<n && word[i]=='o'){
                    t = t | (1<<3);
                    ta++;
                    i++;
                }
                while(i<n && word[i]=='u'){
                    t = t | (1<<4);
                    ta++;
                    i++;
                }
                if(t == 31 && ta>m)
                    m = ta;
            }
            else
                i++;
        }
        return m;
    }
};
