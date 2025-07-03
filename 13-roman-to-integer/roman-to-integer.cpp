class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash;
        hash['I']=1;
        hash['V']=5;
        hash['X']=10;
        hash['L']=50;
        hash['C']=100;
        hash['D']=500;
        hash['M']=1000;
        int n=s.size(),num=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i>0 && s[i-1]=='I' && (s[i]=='V' || s[i]=='X'))
            {
                num+=hash[s[i]]-hash[s[i-1]];
                i--;              
            }
            else if(i>0 && s[i-1]=='X' && (s[i]=='L' || s[i]=='C'))
            {
                num+=hash[s[i]]-hash[s[i-1]];
                i--;             
            }
            else if(i>0 && s[i-1]=='C' && (s[i]=='D' || s[i]=='M'))
            {
                num+=hash[s[i]]-hash[s[i-1]];
                i--;         
            }
            else
            num+=hash[s[i]];
        }
        return num;
    }
};