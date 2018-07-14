class Solution {
    static const int hashTableSize = 52; //total of uppercase and lowercase
    int m_hashTable[hashTableSize], ans; //creating hash table
    
    int hash(char temp){	//this will create a unique index for a unique character.
    	//this function will just return 0 through 25 correstonding to A through Z and 26 through 51 corresponding to a through z respectively
        int t = static_cast<int>(temp);
        if(t <= 'Z') return t - 'A';
        else return t - 'a' + 26 ;
    }
    
    void addItem(char temp){	//this function will create a unique place on the hash table for each unique character contained in the string J
    	//and toggle from 0 to 1 at that index on the hash table which would be later used while searching.
        int index = hash(temp);
        m_hashTable[index] = 1;
    }
    
    void search(char temp){		//this function will search whether the character of string S is there at the string J by using hash Table that
    	//we had created.
        int index = hash(temp);
        if(m_hashTable[index] == 1 ) ans+=1;
    }
    
public:
    int numJewelsInStones(string J, string S) {
        for(int k = 0 ; k < 52; k++ ) m_hashTable[k] = 0;	//this will initialize the hashTable by resetting every place with integer 0;
        ans = 0;
        for(int i = 0; i<J.length() ; i++) addItem(J[i]);	//for each character in the string J, a unique place in the hashtable would by created 
        	//and would be set to 1 and rest all other will be set to 0.
        
        for(int j =  0; j<S.length(); j++) search(S[j]);	//from the hashtable corresponding to J we'll search whether each character in the string S
        	//is located in the hashtable or not, finding which would increament the count ( ie, ans);
        
        return ans;
    }
};