class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp = "";
        int i = 0;
        while (i < n) {
            // Skip leading spaces
            while (i < n && s[i] == ' ') i++;

            // Read word
            if (i >= n) break;
            if (!temp.empty()) temp += ' ';  // add single space between words
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }
            temp += word;
        }
        i=0;
        int j=0;
        n=temp.size();
        while(j<=n)
        {
            if(j==n || temp[j]==' ')
            {
              reverse(temp.begin()+i,temp.begin()+j);
              i=j+1;
            }
            j++;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};