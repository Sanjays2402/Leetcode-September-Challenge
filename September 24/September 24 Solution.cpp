class Solution {
public:
    char findTheDifference(string s, string t) {

        map<char, int> hash;
        for(char i: s)
            hash[i]++;
        
        for(char i: t)
            hash[i]--;
        
        for(auto i: hash)
            if(i.second == -1)
                return i.first;
        
        return 'a';
    }
};
