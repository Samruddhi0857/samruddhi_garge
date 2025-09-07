#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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

    if (root->value == a) return root;
    else if (root->value == b) return root;

    TreeNode* left = findLCA(root->leftChild, a, b);
    TreeNode* right = findLCA(root->rightChild, a, b);

    if (left != NULL && right != NULL) return root;
    else if (left != NULL) return left;
    else return right;
}

int main() {
    string inputLine;
    cout << "Enter tree as array{ null for empty}:\n";
          getline(cin, inputLine);

  
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

    TreeNode* lcaNode = findLCA(root, firstValue, secondValue);

    if (lcaNode == NULL) {
        cout << "One or both nodes not found in tree." << endl;
    } else {
        cout << "LCA of " << firstValue << " and " << secondValue << " is: " << lcaNode->value << endl;
    }

    return 0;
}
