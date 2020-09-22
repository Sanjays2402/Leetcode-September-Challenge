class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> res;
        int m=nums.size()/3;
        map<int, int> hash;
        for(int i: nums)
            hash[i]++;
        
        for(auto i: hash)
            if(i.second>m)
                res.push_back(i.first);
        
        return res;
    }
};
