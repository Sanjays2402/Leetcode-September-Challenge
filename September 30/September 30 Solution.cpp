class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if(nums.size()==0)
            return 1;

        map<int, int> hash;
        for(int i: nums)
            hash[i]=1;
        
        int k=1;
        for(auto it: hash)
        {
            cout<<it.first<<" ";
            if(it.first >= 1)
            {
                if(it.first != k)
                    return k;
                k++;
                
            }
        }
        return k;
    }
};
