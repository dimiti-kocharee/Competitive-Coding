class Solution {
/*
Max Number the function returns is 9*9*9: because the max number of input n is less than a size of an unsigned int.
so make a hash table of size 9*9*10;
*/
    int temp,t,m_HashTable[811],i;
    bool ans;
    int sumOfSquareOfItsDigits(int x){
        temp =0;
        while(x>0){
            temp += (x%10)*(x%10);
            x /= 10;
        }
        return temp;
    }
public:
    bool isHappy(int n) {
        for(i = 0 ; i< 811 ;i++) m_HashTable[i] = 0;
        t = n;
        while(1){
            t = sumOfSquareOfItsDigits(t);
            if(t == 1) {
                ans = true;
                break;
            }
            if(m_HashTable[t] == 1 ){
                ans = false;
                break;
            }else{
                m_HashTable[t] = 1;
            }
        }
        return ans;   
    }
};
