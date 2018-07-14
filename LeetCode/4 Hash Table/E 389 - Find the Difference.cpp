class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0,i;
        for(i = 0 ; i < s.length() ; i++ ){
            ans ^= ((int)s[i]) ^ ((int)t[i]);
        }
        ans^= (int)t[i];
        return static_cast<char>(ans);
    }
};