#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int val) {
        value = val;
        leftChild = rightChild = NULL;
    }
};

TreeNode* buildBinaryTree(vector<string>& nodes) {
    if (nodes.empty()) return NULL;
    if (nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

      
        if (i < nodes.size()) {
            if (nodes[i] != "null") {
                current->leftChild = new TreeNode(stoi(nodes[i]));
                q.push(current->leftChild);
            }
            i++;
        }

        
        if (i < nodes.size()) {
            if (nodes[i] != "null") {
                current->rightChild = new TreeNode(stoi(nodes[i]));
                q.push(current->rightChild);
            }
            i++;
        }
    }
    return root;
}

TreeNode* findLCA(TreeNode* root, int a, int b) {
    if (root == NULL) return NULL;

    if (root->value == a || root->value == b) return root;

    TreeNode* left = findLCA(root->leftChild, a, b);
    TreeNode* right = findLCA(root->rightChild, a, b);

    if (left && right) return root;
    return (left != NULL) ? left : right;
}

bool exists(TreeNode* root, int val) {
    if (!root) return false;
    if (root->value == val) return true;
    return exists(root->leftChild, val) || exists(root->rightChild, val);
}

int main() {
    string inputLine;
    cout << "Enter tree as array (use 'null' for empty nodes, space/comma separated):\n";
    getline(cin, inputLine);

    
    replace(inputLine.begin(), inputLine.end(), ',', ' ');

    vector<string> nodes;
    stringstream ss(inputLine);
    string word;
    while (ss >> word) {
        nodes.push_back(word);
    }

    TreeNode* root = buildBinaryTree(nodes);

    int firstValue, secondValue;
    cout << "Enter first node value: ";
    cin >> firstValue;
    cout << "Enter second node value: ";
    cin >> secondValue;

    if (!exists(root, firstValue) || !exists(root, secondValue)) {
        cout << "One or both nodes not found in tree." << endl;
        return 0;
    }

    TreeNode* lcaNode = findLCA(root, firstValue, secondValue);

    if (lcaNode == NULL) {
        cout << "LCA not found." << endl;
    } else {
        cout << "LCA of " << firstValue << " and " << secondValue
             << " is: " << lcaNode->value << endl;
    }

    return 0;
}
