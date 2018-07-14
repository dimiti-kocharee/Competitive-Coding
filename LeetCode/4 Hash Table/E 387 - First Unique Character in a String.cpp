class Solution {
    int m_HashTable[26], i,m_HashIndex;
public:
    int firstUniqChar(string s) {
        for( i = 0;  i< 26 ; i++) m_HashTable[i] = 0;
        for( i = 0 ; i < s.length() ; i++ ){
            m_HashIndex = static_cast<int>(s[i])-'a';
            m_HashTable[m_HashIndex] += 1;
        }
        for( i =0 ; i < s.length() ; i++){
            m_HashIndex = static_cast<int>(s[i])-'a';
            if( m_HashTable[m_HashIndex] == 1 ) return i;
        }
        return -1;
    }
};
