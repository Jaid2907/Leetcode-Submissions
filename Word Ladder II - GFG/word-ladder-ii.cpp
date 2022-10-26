//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        queue<pair<string, vector<string>>> q;
        vector<vector<string>> ans;
        q.push({beginWord, {beginWord}});
        unordered_map<string, int> mp;
        for(auto it: wordList){
            mp[it]++;
        }
        
        
        while(!q.empty()){
            int size = q.size();
             vector<string> del;
            
            while(size--){
                auto it = q.front();
                q.pop();
                string word = it.first;
                vector<string> vec = it.second;
               
                
                for(int i = 0; i<word.size(); i++){
                    string temp = word;
                    for(int j = 0; j<26; j++){
                        temp[i] = j+97;
                        if(temp != word && mp.find(temp) != mp.end()){
                            
                            del.push_back(temp);
                            vec.push_back(temp);
                            if(temp == endWord){
                                ans.push_back(vec);
                            }
                            else{
                            q.push({temp,vec});
                            }
                            vec.pop_back();
                        }
                        
                    
                    }
                }
            }
            
            for(auto it: del){
                mp.erase(it);
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends