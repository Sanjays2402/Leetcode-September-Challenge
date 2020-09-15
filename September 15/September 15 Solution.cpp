class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if(s.length()==0 || count(s.begin(), s.end(), ' ')==s.length())
            return 0;
        
        int count=0;
        while(s.back()==' ')
            s.pop_back();
        while(s.front()==' ')
            s.erase(s.begin());
        
        
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]==' ')
            {
                count=s.length()-i-1;
                break;
            }
        }
        if(s.length() && !count)
            return s.length();
        return count;
    }
};
