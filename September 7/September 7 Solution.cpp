class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        int k=0;
        map<char, string> hash;
        map<string, char> hash1;
        vector<string> a;
        for(int i=0; i<str.length();)
        {
            string s="";
            while(str[i]!=' ' && i<str.length())
                s.push_back(str[i++]);
            hash[pattern[k]]=s;
            hash1[s]=pattern[k];
            a.push_back(s);
            i++,k++;
        }
        if(pattern.size() != a.size())
            return false;
        for(int k=0; k<pattern.size(); k++)
        {
            if(hash[pattern[k]] != a[k] || hash1[a[k]] != pattern[k])
                return false;
        }
        return true;
    }
};
