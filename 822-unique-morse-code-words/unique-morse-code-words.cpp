class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> abc = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};
        unordered_set<string>st;
        for(string s:words){
            string str="";
            for(char ch:s){
                  str+=abc[ch-97];
            }
            st.insert(str);
        }
        return st.size();
    }
};