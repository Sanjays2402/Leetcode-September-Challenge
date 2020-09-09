class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        std::replace(version1.begin(), version1.end(), '.', ' '); 
        std::replace(version2.begin(), version2.end(), '.', ' '); 
        istringstream ss1(version1);
        istringstream ss2(version2);
        
        while (true) 
        {
            string str1, str2;
            int tmp1, tmp2;
            
			ss1 >> str1;
            ss2 >> str2;
             
            tmp1 = str1.empty() ? 0 : stoi(str1);
            tmp2 = str2.empty() ? 0 : stoi(str2);
            
            if (str1.empty() && str2.empty())
                return 0;
				
            if (tmp1 < tmp2)
                return -1;
            
            if (tmp1 > tmp2)
                return 1;
			
        }
       
        return 0;
    }
};
