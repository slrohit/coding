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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* node){
    if(node->right){
        TreeNode* temp = node->right;
        while(temp->left)temp=temp->left;
        return temp;
    }
    TreeNode* succ = NULL;
    while(root){
        if(node->val < root->val){
            succ = root;
            root = root->left;
        }else if(node->val > root->val){
            root = root->right;
        }else{
            break;
        }
    }
    return succ;
}

int nextGreaterElement(TreeNode* root, int ele){
    TreeNode* temp = root;
    while(temp->right)
        temp = temp->right;
    if(ele >= temp->val )return -1;
    TreeNode* succ = NULL;
    while(root){
        if(ele < root->val){
            succ = root;
            root = root->left;
        }else if(ele > root->val){
            root = root->right;
        }else{
            if(root->right){
                succ = root->right;
                while(succ->left)succ=succ->left;
            }
            break;
        }
    }
    return succ->val;
}

int main(){
    TreeNode* root = new TreeNode(7,
        new TreeNode(3,
            new TreeNode(1,
                NULL,
                new TreeNode(2)
            ),
            new TreeNode(5,
                NULL,
                new TreeNode(6)
            )
        ),
        new TreeNode(9,
            new TreeNode(8),
            NULL
        )
    );

    TreeNode* testNode1 = root->left->right->right;
    cout<<inorderSuccessor(root,testNode1)->val<<endl;
    TreeNode* testNode2 = root;
    cout<<inorderSuccessor(root,testNode2)->val<<endl;
    TreeNode* testNode3 = root->left;
    cout<<inorderSuccessor(root,testNode3)->val<<endl;


    cout<<nextGreaterElement(root,4)<<endl;
    cout<<nextGreaterElement(root,2)<<endl;
    cout<<nextGreaterElement(root,5)<<endl;
    cout<<nextGreaterElement(root,6)<<endl;
    cout<<nextGreaterElement(root,8)<<endl;
    cout<<nextGreaterElement(root,10)<<endl;

}
