class Solution {
public:
    int appendCharacters(string s, string t) {
        int chara=0;
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                chara++;
                i++;
                j++;
            }
            else
            i++;
        }
        return t.length()-chara;
    }
};