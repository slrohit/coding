#include<iostream>
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


void inorder(TreeNode* root){
    if(!root)return;

    TreeNode *cur,*prev;

    cur = root;

    while(cur){
        if(cur->left){
            prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;

            if(prev->right == NULL){
                prev->right = cur;
                cur=cur->left;
            }else{
                prev->right = NULL;
                cout<<cur->val<<" ";
                cur=cur->right;
            }
        }else{
            cout<<cur->val<<" ";
            cur = cur->right;
        }
    }
    cout<<endl;
}

int main(){
    TreeNode* root = new TreeNode(5,
        new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), new TreeNode(7)), new TreeNode(4,new TreeNode(8),new TreeNode(9))
    );
    inorder(root);
}
