#include<iostream>
#include<stack>
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
void preorder(TreeNode* root){
    stack<TreeNode*> stk;
    while(1){
        while(root){
            cout<<root->val<<" ";
            stk.push(root);
            root = root->left;
        }
        if(stk.empty())break;
        root = stk.top();stk.pop();
        root = root->right;
    }
    cout<<endl;
}
void inorder(TreeNode* root){
    stack<TreeNode*> stk;
    while(1){
        while(root){
            stk.push(root);
            root = root->left;
        }
        if(stk.empty())break;
        root = stk.top();stk.pop();
        cout<<root->val<<" ";
        root = root->right;
    }
    cout<<endl;
}
void postorder(TreeNode* root){
    stack<TreeNode*> stk;
    TreeNode* prev = NULL;
    while(1){
        while(root){
            stk.push(root);
            root = root->left;
        }
        if(stk.empty())break;
        while(root == NULL && !stk.empty()){
            root = stk.top();
            if(root->right == NULL || root->right == prev){
                cout<<root->val<<" ";
                stk.pop();
                prev = root;
                root = NULL;
            }else{
                root = root->right;
            }
        }
    }
    cout<<endl;
}
TreeNode* buildTreeUtil(int preorder[], int inorder[], int inorderStart, int inorderEnd){
    static int preOrderIndex = 0;
    if(inorderStart > inorderEnd)return NULL;
    TreeNode* newNode = new TreeNode(preorder[preOrderIndex]);
    preOrderIndex++;

    if(inorderStart == inorderEnd)return newNode;

    int inorderPartitionIndex = 0;
    for(inorderPartitionIndex=inorderStart; inorderPartitionIndex<=inorderEnd;inorderPartitionIndex++){
        if(inorder[inorderPartitionIndex] == newNode->val)break;
    }

    newNode->left = buildTreeUtil(preorder,inorder,inorderStart,inorderPartitionIndex-1);
    newNode->right = buildTreeUtil(preorder,inorder,inorderPartitionIndex+1,inorderEnd);
    return newNode;
}

TreeNode* buildTree(int preorder[], int inorder[], int n){
    return buildTreeUtil(preorder,inorder,0,n-1);
}

int main(){
    int preorderArr[] ={5,3,2,1,6,7,4,8,9};
    int inorderArr[] = {2,6,1,3,7,5,8,4,9};
    int n = 9;
    TreeNode* root = buildTree(preorderArr,inorderArr,n);
    cout<<"Pre order traversal is\n";
    preorder(root);
    cout<<"\nIn order traversal is\n";
    inorder(root);
    cout<<"\nPost order traversal is\n";
    postorder(root);
}
