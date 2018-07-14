class Solution {
    vector<string> ans;
    int i, min,index;
    struct items{
        string m_restaurants;
        int m_index;
        items* next;
    };
    items* m_HashTable[100];
    items* cur;
    
    int Hash(string temp){
        int t = 0;
        for(int j = 0; j<temp.length();j++) t+=temp[j];
        return t%100;
    }
    
    void addToHashTable(string temp,int i){
        index = Hash(temp);
        if(m_HashTable[index]->m_restaurants == "empty"){
            m_HashTable[index]->m_restaurants = temp;
            m_HashTable[index]->m_index = i;
        }else{
            items* ptr = new items;
            ptr->m_restaurants = temp;
            ptr->m_index = i;
            ptr->next = NULL;
            cur = m_HashTable[index];
            while(cur->next) cur = cur->next;
            cur->next = ptr;
        }
    }
    
    void check(string temp,int i){
        index = Hash(temp);
        cur = m_HashTable[index];
        while(cur){
            if(cur->m_restaurants == temp && min>= (i + (cur->m_index))){
                if(min > (i + (cur->m_index)) ) while( !ans.empty() ) ans.pop_back();
                ans.push_back(temp);
                min = i + (cur->m_index);
            }
            cur = cur->next;
        }
        
    }
public:    
    Solution(){
        for(i = 0; i<100 ; i++) m_HashTable[i] = new items;
    }
    
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        min = 3000;
        while(!ans.empty()) ans.pop_back();
        if( !list1.empty() && !list2.empty() ){
            for(i = 0; i< 100 ; i++){
                m_HashTable[i]->m_restaurants = "empty";
                m_HashTable[i]->m_index = 10000;
                m_HashTable[i]->next = NULL;
            }
            for(i = 0; i<list1.size() ; i++) addToHashTable(list1[i], i);
            for(i = 0; i<list2.size() ; i++) check(list2[i], i);            
        }
        return ans;
    }
};