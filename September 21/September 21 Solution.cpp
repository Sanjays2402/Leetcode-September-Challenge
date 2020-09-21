class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        map<int, int> car;
        for(int i=0; i<trips.size(); i++)
        {
            car[trips[i][1]] += trips[i][0];
            car[trips[i][2]] += -trips[i][0];
        }
        
        int count=0;
        for(auto i: car)
        {
            count += i.second;
            if(count > capacity)
                return false;
        }
        return true;
    }
};
