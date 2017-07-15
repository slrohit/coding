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

int getDiameterUtil(TreeNode* root, int* diameter){
    if(!root)return 0;
    int lh = getDiameterUtil(root->left,diameter);
    int rh = getDiameterUtil(root->right,diameter);
    if(lh+rh+1 > *diameter)
        *diameter = lh+rh+1;
    return 1 + max(lh,rh);
}

int getDiameter(TreeNode* root){
    int diameter = 0;
    getDiameterUtil(root,&diameter);
    return diameter;
}

int main(){
    TreeNode* root = new TreeNode(5,
        new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), new TreeNode(7)), new TreeNode(4,new TreeNode(8),new TreeNode(9))
    );
    cout<<getDiameter(root)<<endl;
}

