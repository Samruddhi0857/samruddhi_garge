#include <iostream>
#include <vector>
#include <queue>
  #include <string>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
     TreeNode* left;
     TreeNode* right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    bool helperfunc(TreeNode* node, long long low, long long high) {
           if (node == NULL) return true;
               if (node->val <= low || node->val >= high) return false;
                    return helperfunc(node->left, low, node->val) &&
                         helperfunc(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
           return helperfunc(root, LLONG_MIN, LLONG_MAX);
    }
};

TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(arr[0]));
       queue<TreeNode*> q;
         q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
          q.pop();

        if (i < arr.size() && arr[i] != "null") {
            curr->left = new TreeNode(stoi(arr[i]));
               q.push(curr->left);
        }
        i++;

        
        if (i < arr.size() && arr[i] != "null") {
              curr->right = new TreeNode(stoi(arr[i]));
                 q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
      cout << "Enter number of nodes ('null' for empty nodes): ";
        cin >> n;

    vector<string> arr(n);
       cout << "Enter nodes in level order: ";
    for (int i = 0; i < n; i++)
      {   
      cin >> arr[i];
    }

    TreeNode* root = buildTree(arr);
    Solution sol;

    if (sol.isValidBST(root))
         cout << "true\n";
      else
        cout << "false\n";

    return 0;
}
