class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> res;
        unordered_map<char, int> hash;
        for(int i=0; i<S.length(); i++)
            hash[S[i]]=i;
        
        int j=0, k=0;
        for(int i=0; i<S.length(); i++)
        {
            j=max(j,hash[S[i]]);
            if(i == j)
            {
                res.push_back(i-k+1);
                k=i+1;
            }
        }
        return res;
    }
};
