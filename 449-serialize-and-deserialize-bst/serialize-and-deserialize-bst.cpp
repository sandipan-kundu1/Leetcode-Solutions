/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Serialize using preorder traversal
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    void preorder(TreeNode* root, string &s) {
        if (!root) return;
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Deserialize using preorder + BST properties
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        vector<int> vals;
        int val;
        while (ss >> val) vals.push_back(val);

        int idx = 0;
        return build(vals, idx, INT_MIN, INT_MAX);
    }

    TreeNode* build(vector<int>& vals, int &idx, int low, int high) {
        if (idx == vals.size() || vals[idx] < low || vals[idx] > high)
            return NULL;

        int rootVal = vals[idx++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(vals, idx, low, rootVal);
        root->right = build(vals, idx, rootVal, high);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;