//Counting sort with one pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        
        for(auto &x: nums)
        {
            if(x==0)
                zero++;
            if(x==1)
                one++;
            if(x==2)
                two++;
        }
        int i=0;
        
        while(zero>0)
        {
            nums[i++]=0;
            zero--;
        }
        while(one>0)
        {
            nums[i++]=1;
            one--;
        }
        while(two>0)
        {
            nums[i++]=2;
            two--;
        }
        
    }
};
