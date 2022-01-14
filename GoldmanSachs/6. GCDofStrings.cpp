class Solution {
public:
    int gcd(int a, int b)
    {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a == b) return a;
        
        if(a > b) return gcd(a - b, b);
        return gcd(a, b - a);
    }
    
    string gcdOfStrings(string str1, string str2) {
        
        int len1 = str1.length(), len2 = str2.length();
        
        if(len1 < len2) return gcdOfStrings(str2, str1);
        
        int lngcd = gcd(len1, len2);
        
        string common = str2.substr(0, lngcd);
        
        for(int j = 0; j < len2; j += lngcd)
        {
            int i = 0;
            while(i < lngcd)
            {
                if(common[i] != str2[i + j] || common[i] != str1[i + j])
                {
                    return "";
                }
                i++;
            }
        }
        
        for(int j = len2; j < len1; j += lngcd)
        {
            int i = 0;
            while(i < lngcd)
            {
                if(common[i] != str1[i + j])
                {
                    return "";
                }
                i++;
            }
        }
        return common;
    }
};
