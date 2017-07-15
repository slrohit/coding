#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
    TreeNode(int v, TreeNode* l, TreeNode* r){
        val=v;
        left=l;
        right=r;
    }
};

TreeNode* getLca(TreeNode* root, int node1, int node2){
    if(!root)
        return NULL;
    if(root->val == node1 || root->val == node2)
        return root;
    TreeNode* left = getLca(root->left, node1, node2);
    TreeNode* right = getLca(root->right, node1, node2);
    return (left && right ) ? root : (left ? left: right);
}
int main(){
    TreeNode* root = new TreeNode(5,
        new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), new TreeNode(7)), new TreeNode(4,new TreeNode(8),new TreeNode(9))
    );
    TreeNode* lcaNode = getLca(root,6,7);

    if(lcaNode)
        cout<<lcaNode->val<<endl;
    else
        cout<<"Not exist"<<endl;
}

