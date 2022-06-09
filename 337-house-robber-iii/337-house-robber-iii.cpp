/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int robHouse(TreeNode* root, int flag, unordered_map<TreeNode*,pair<int,int>>& mp)
    {
        if(root == NULL)
            return 0;
       
        
        if(mp.find(root) != mp.end())
        {
            if(flag && mp[root].first != -1)
                return mp[root].first;
            if(!flag && mp[root].second != -1)
            return mp[root].second;
        }
        
        mp[root].first = -1;
        mp[root].second = -1;
        
        int pick = -1, notPick = -1;
        //Pick
        if(flag == 0)
        pick = root->val + robHouse(root->left,1,mp) + robHouse(root->right,1,mp);
        
        //Not Pick
        notPick = robHouse(root->left,0,mp) + robHouse(root->right,0,mp);
        
        int ans = max(pick, notPick);
        
        if(flag == 1)
            mp[root].first = ans;
        else
            mp[root].second = ans;
        
        
        return ans;
        
        
        
    }
    int rob(TreeNode* root) {
        
       unordered_map <TreeNode*,pair<int,int>> mp;
        
       int case1 = robHouse(root,0,mp);
        mp.clear();
       int case2 = robHouse(root,1,mp);
        
        
        return max(case1,case2);
        
        
        
      
        
        
    }
};