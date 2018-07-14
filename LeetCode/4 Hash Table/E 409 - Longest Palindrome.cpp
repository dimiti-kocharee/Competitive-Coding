class Solution {
    int m_HashTable[52],i,ans,index,noOfOdds;
    
    int hash(char t){
        if((int)t > 'Z') return (int)t - 'a';
        else return (int)t - 'A'+26;
    }
public:
    int longestPalindrome(string s) {
        ans =0;
        if(s.length()>0){
            noOfOdds = 0;
            for(i = 0; i<52 ; i++) m_HashTable[i] = 0;
            for(i = 0; i<s.length() ; i++){
                index = hash(s[i]);
                m_HashTable[index]+=1;
            }
            for(i = 0; i<52 ; i++){
                ans += m_HashTable[i];
                if(m_HashTable[i]%2 != 0) noOfOdds +=1;
            }
            if(noOfOdds > 1)ans -= noOfOdds-1;
        }
        return ans;
    }
};

