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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* build(stringstream &ss) {
        string s;
        getline(ss, s, ',');

        if (s == "#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(s));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};