/*Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------*/


vector<string> Solution::fullJustify(vector<string> &a, int b){
    int n = a.size(),words,chars,i,temp,k=0,j;
    string s;
    map<int , string> m;
    vector<string> v,ans;
    while(i<n){
        s = "";        
        words = 0;
        chars = 0;
        while(i<n && chars + a[i].size() <= b){
            chars += a[i].size()+1;
            v.push_back(a[i]);
            words++;
            i++;
        }
        if(i==n){
            for(j=0;j<v.size()-1;j++){
                s = s+ v[j];
                s.push_back(' ');
            }
            s = s+ v[j];
            while(s.size() < b) s.push_back(' ');
        }
        else if(words == 1){
            s= s+v[0];
            while(s.size() < b) s.push_back(' ');
        }
        else{

            temp = (b-chars+words)/(words-1);
            int temp1 = (b-chars+words)%(words-1);
            for(j=1;j<v.size();j++){
                s = s + v[j-1];
                for(int l=0;l<temp;l++){
                    s.push_back(' ');
                }
                if(j<=temp1)
                s.push_back(' ');
            }
            s = s + v[j-1];
        }
        v.clear();
        ans.push_back(s);
    }
    return ans;
    
}
