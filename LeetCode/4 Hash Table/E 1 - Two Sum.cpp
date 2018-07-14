class Solution {
    int i, index;
    vector<int> ans;
    bool temp;
    
    struct item{
        int m_num;
        int m_times;
        item* next;
    };
    
    item* m_hashTable[1000],*ptr,*cur;
    
    int hash(int temp){
        if(temp<0) return (temp*-1)%1000;
        else return temp%1000;
    }
    void insertToHashTable(int num){
        index = hash(num);
        ptr = m_hashTable[index];
        if(!ptr){
            m_hashTable[index] = new item;
            m_hashTable[index]->m_num = num;
            m_hashTable[index]->m_times = 1;
            m_hashTable[index]->next = NULL;
        }else{
            while(ptr->next && ( ptr->m_num != num) ) ptr = ptr->next;
            if(ptr->m_num == num) ptr->m_times += 1;
            else{
                cur = new item;
                cur->m_num = num;
                cur->m_times = 1;
                cur->next = NULL;
                ptr->next = cur;
            }
        }
    }
    bool confirmIfNum(int num,vector<int>& nums, int j){
        index = hash(num);
        ptr = m_hashTable[index];
        while(ptr && ptr->next && ptr->m_num != num) ptr = ptr->next;
        if(ptr && ptr->m_num == num){
            if(nums[i] == num && ptr->m_times == 1) return false;
            else return true;
        }
        return false;
    }
    int searchIndex(vector<int>& nums, int target, int excludei){
        for(int j = 0; j< nums.size() ; j++) if( j!= excludei && nums[j] == target) return j;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        while( !ans.empty() ) ans.pop_back();
        for( i = 0 ; i< nums.size() ; i++) insertToHashTable(nums[i]);
        for( i = 0 ; i< nums.size() ; i++){
            temp = confirmIfNum(target - nums[i], nums, i);
            if(temp){
                ans.push_back(i);
                i = searchIndex(nums,target - nums[i],i);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
