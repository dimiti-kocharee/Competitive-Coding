class Solution {
    /*
    Remember:-
        1. Both empty strings are also anagram.
        2. You can't use Xor here. Case:- s = "aa" and t = "bb".
        3. So use hashTable. Time: O(n). Space: O(1).
    */
    
    bool ans;
    int m_HashTable[26], hashIndex , i;
    
public:
    bool isAnagram(string s, string t) {
        bool ans = false;
        if(s.length() == t.length()){
            for( i = 0 ; i <  26; i++ ) m_HashTable[i] =0; //resetting the hashtable
            for( i = 0 ; i < s.length() ; i++ ){    // setting hashTable with s string
                hashIndex = static_cast<int>(s[i]) - 'a';
                m_HashTable[hashIndex] += 1;
            }
            for( i = 0 ; i < t.length() ; i++ ){    // checking t string with s
                hashIndex = static_cast<int>(t[i]) - 'a';
                m_HashTable[hashIndex] -= 1;
            }
            for( i = 0 ; i <  26; i++ ) if(m_HashTable[i] != 0) return false;
            ans = true;
        }
        return ans;
    }
};
