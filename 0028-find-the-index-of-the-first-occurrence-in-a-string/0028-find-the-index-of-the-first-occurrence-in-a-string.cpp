class Solution {
public:
    int strStr(string haystack, string needle) {
        int occ=haystack.find(needle);
        if(occ!=string::npos)
        return occ;
        else
        return -1;
    }
};