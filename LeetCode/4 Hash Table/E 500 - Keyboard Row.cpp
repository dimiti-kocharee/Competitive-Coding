class Solution {
    int m_HashTable[26];
    vector<string> ans;
    
    int getRowNum(char temp){
        int t = static_cast<int>(temp);
        t -= (t<='Z')?('A'):('a');
        return m_HashTable[t];
    }
    
    void checkAndAdd(string word){
        if(word.length() <2 ) ans.push_back(word);
        else{
            int flag = getRowNum(word[0]), t = 0;
            for(int i = 1; i<word.length() ; i++) if(flag != getRowNum(word[i])) t = 1;
            if(t==0)ans.push_back(word);
        }
    }
    
public:
    Solution(){ //this will create an hashTable array which contains the row of the 
        //index which corresponds to the alphabets ie., a-z or A-Z corresponds to 0-25.
        for(int i = 0; i < 26 ; i++ ) m_HashTable[i] = 2;
        for(int j = 0; j < 12 ; j++ ) m_HashTable[j] = 1;
        for(int k =14; k < 25 ; k++ ) m_HashTable[k] = 0;
        m_HashTable[4]  = 0;
        m_HashTable[8]  = 0;
        m_HashTable[18] = 1;
        m_HashTable[1]  = 2;
        m_HashTable[2]  = 2;
        m_HashTable[21] = 2;
        m_HashTable[23] = 2;
    }
    
    vector<string> findWords(vector<string>& words) {
        while( !ans.empty() ) ans.pop_back();
        for(int i = 0; i<words.size() ; i++) checkAndAdd(words[i]);
        return ans;
    }
};
