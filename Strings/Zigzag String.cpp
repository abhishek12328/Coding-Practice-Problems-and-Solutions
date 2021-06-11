/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR

--------------------------------------
--------------------------------------
--------------------------------------
--------------------------------------*/



string Solution::convert(string a, int b) {
    map<int,string> m;
    int n =a.size(),start = 0,i=0;
    while( i<n){
        start = 0;
        while(start<b && i<n){
            m[start++] += a[i];
            i++;
        }
        start = b-1;
        while(start>1 && i<n){
            m[--start] += a[i];
            i++;
        }
    }
    string ans;
    for(int i=0;i<b;i++){
        for(int j=0;j<m[i].size();j++){
            ans = ans + m[i][j];
        }
    }
    return ans;
}
