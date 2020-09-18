class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi=0, mini=INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            if(mini>prices[i])
                mini=prices[i];
            else if(maxi<(prices[i]-mini))
                maxi=prices[i]-mini;
        }
        return maxi;
    }
};
