class Solution {
public:
    bool check(Node* root, long long low, long long high) {
        if (root == nullptr)
            return true;

        if (root->data <= low || root->data >= high)
            return false;

        return check(root->left, low, root->data) &&
               check(root->right, root->data, high);
    }

    bool isBST(Node* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
