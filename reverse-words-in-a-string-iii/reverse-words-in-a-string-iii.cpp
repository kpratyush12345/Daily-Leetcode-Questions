class Solution {
public:
    string reverseWords(string s) {
        int l=0,r,i=0;
        int n=s.length();
        while(i<n){ 
            while(s[i]!=' ' && i<n) i++;
            r=i-1;
            while(l<r) swap(s[l++],s[r--]);
            i++;    
            l=i;
        }
        return s;
    }
};