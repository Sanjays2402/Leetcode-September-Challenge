class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,0);
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--){
            string str="";
            for(int j=i;j<n;j++){
                str+=s[j];
				
                if(dict.find(str)!=dict.end() && dp[j+1]){
                    dp[i]=1;   
                    break;
                }
            }
        }
        return dp[0];
    }
};
