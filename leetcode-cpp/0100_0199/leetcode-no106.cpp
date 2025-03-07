#include <set>
#include <span>
#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct MapNode {
    int _val;
    MapNode *left;
    MapNode *right;

    MapNode() : _val(0), left(nullptr), right(nullptr) {
    }

    MapNode(int x) : _val(x), left(nullptr), right(nullptr) {
    }

    MapNode(int x, MapNode *left, MapNode *right) : _val(x), left(left), right(right) {
    }
};

class Solution {
public:
    MapNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(span<int>(inorder), span<int>(postorder));
    }

    MapNode *build(span<int> inorder, span<int> postorder) {
        int root_val = postorder.back();
        int mid_index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root_val) {
                mid_index = i;
                break;
            }
        }
        auto root = new MapNode(root_val);

        int right_cnt = inorder.size() - mid_index - 1;
        int left_cnt = mid_index;

        if (right_cnt == 1) {
            root->right = new MapNode(inorder[mid_index + 1]);
        } else if (right_cnt != 0) {
            root->right = build(inorder.subspan(mid_index + 1, right_cnt),
                                postorder.subspan(postorder.size() - 1 - right_cnt, right_cnt));
        }
        if (left_cnt == 1) {
            root->left = new MapNode(inorder[0]);
        } else if (left_cnt != 0) {
            root->left = build(inorder.subspan(0, left_cnt), postorder.subspan(0, left_cnt));
        }
        return root;
    }
};

void dfs(MapNode *root) {
    cout << root->_val << endl;
    if (root->left) {
        dfs(root->left);
    }
    if (root->right) {
        dfs(root->right);
    }
}

int main() {
    Solution test;
    vector<int> in1 = {9, 3, 15, 20, 7};
    vector<int> po1 = {9, 15, 7, 20, 3};
    auto root = test.buildTree(in1, po1);
    dfs(root);
}


//
// Created by ASUS on 2025/2/5.
//
