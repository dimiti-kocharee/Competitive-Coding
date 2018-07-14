class Solution {
    int m_HashTable[200001],ans, temp;
    
    void addItemsToTheHashTable(vector<int>& candies){
        for(int i = 0 ; i < candies.size() ; i++ ){
            if( candies[i] < 0 ) temp = candies[i] * -1 + 100000;
            else temp = candies[i];
            m_HashTable[temp] += 1;
        }
    }
public:
    int distributeCandies(vector<int>& candies) {
        ans = 0;
        for(int i = 0; i<200001 ; i++) m_HashTable[i] = 0;
        addItemsToTheHashTable(candies);
        for(int j = 0 ; j<200001 ; j++ ) if(m_HashTable[j] != 0) ans += 1;
        if( candies.size() < 2*ans) ans = candies.size()/2;
        return ans;
    }
};