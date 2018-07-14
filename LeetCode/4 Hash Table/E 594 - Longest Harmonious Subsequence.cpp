class Solution {
    int ans, min, max, i,index;
    struct item{
        int m_num;
        int m_times;
        item* next;
    };
    item* ptr,*m_HashTable[1000],*cur;
    
    int hash(int i){
        if( i<0) return (i*-1)%1000;
        return i%1000;}
    
    void storeInHashTable(int i){
        index = hash(i);
        ptr = m_HashTable[index];
        if( !ptr ){
            m_HashTable[index] = new item;
            m_HashTable[index]->m_num = i;
            m_HashTable[index]->m_times = 1;
            m_HashTable[index]->next = NULL;
        }else{
            while(ptr->next && ptr->m_num != i) ptr = ptr->next;
            if(ptr->m_num == i) ptr->m_times+=1;
            else{
                cur = new item;
                cur->m_num = i;
                cur->m_times = 1;
                cur->next = NULL;
                ptr->next = cur;
            }
        }
    }
    
    void searchAndAdd(int i){
        index = hash(i);
        ptr = m_HashTable[index];
        while(ptr->m_num != i) ptr = ptr->next;
        if(ptr->m_times != -1){
            index = hash(i+1);
            cur = m_HashTable[index];
            while(cur && cur->next && cur->m_num != i+1) cur = cur->next;
            if(cur && cur->m_num == i+1 && ans < (cur->m_times)+(ptr->m_times)) ans = (cur->m_times)+(ptr->m_times);
        }
    }
    
public:
    int findLHS(vector<int>& nums) {
        ans = 0;
        if(!nums.empty()){
            min = nums[0];
            max = nums[0];
            for(i = 1; i<nums.size() ; i++ ){
                min = (min < nums[i])? nums[i] :min;
                max = (max > nums[i])? nums[i] :max;
            }
            if(max - min == 1 ) return nums.size();
            else if(max == min) return 0;
            for( i = 0; i< nums.size() ; i++) storeInHashTable(nums[i]);
            for( i = 0 ; i<nums.size() ; i++) searchAndAdd(nums[i]);
        }
        return ans;
    }
};
