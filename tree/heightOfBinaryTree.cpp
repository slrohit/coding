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

int getHeight(TreeNode* root){
    return root == NULL ? 0 : 1+max(getHeight(root->left),getHeight(root->right));
}
int main(){
    TreeNode* root = new TreeNode(5,
        new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), new TreeNode(7)), new TreeNode(4,new TreeNode(8),new TreeNode(9))
    );
    cout<<getHeight(root)<<endl;
}
