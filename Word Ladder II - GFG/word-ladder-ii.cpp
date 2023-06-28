//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        map<string,int> mp;
        for(int i = 0; i<wordList.size(); i++)
            mp[wordList[i]]++;
        
        unordered_set<string> used;
        queue<vector<string>> q;
        q.push({beginWord});
        mp.erase(beginWord);
        
        vector<vector<string>> ans;
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                auto curr_list = q.front();
                q.pop();
                
                string last = curr_list.back();
                
                for(int i = 0; i<last.size(); i++){
                    char original = last[i];
                    
                    for(int j = 97; j<122; j++){
                        if(j == original)   
                            continue;
                        last[i] = j;
                        if(mp.find(last) != mp.end()){
                            curr_list.push_back(last);
                            q.push({curr_list});
                            used.insert(last);
                            if(last == endWord){
                                ans.push_back(curr_list);
                            }
                            curr_list.pop_back();
                        }
                    }
                    
                    last[i] = original;
                }
            }
            
            for(auto &it: used){
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