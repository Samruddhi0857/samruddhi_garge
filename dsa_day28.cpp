#include <bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildTree(vector<string>& arr) 
{
    if (arr.empty() || arr[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
      {
        TreeNode* node = q.front();
        q.pop();

       
        if (i < arr.size() && arr[i] != "null")
        {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

       
        if (i < arr.size() && arr[i] != "null")
        {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}


bool isMirror(TreeNode* t1, TreeNode* t2) 
{
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root)
{
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main()
{
    cout << "Enter tree in array form (use 'null' for empty):\n";
    // Example input: 1 2 2 3 
    vector<string> arr;
    string s;
    while (cin >> s) 
    {
        arr.push_back(s);
        if (cin.peek() == '\n') break; // stop when line ends
    }

    TreeNode* root = buildTree(arr);

    if (isSymmetric(root))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
