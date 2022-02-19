class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string s = "";
        string v[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> set_uniques;
        for(int i=0; i<words.size(); i++)
        {
            for(int j=0; j<words[i].size(); j++)
                s += v[words[i][j]-97];
            set_uniques.insert(s);
            s.clear();
        }
        
        return set_uniques.size();
    }
};