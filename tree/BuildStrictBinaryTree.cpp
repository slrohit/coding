#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v){
        val=v;
        left=NULL;
        right=NULL;
    }
    TreeNode(char v, TreeNode* l, TreeNode* r){
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

TreeNode* buildTree(char A[]){
    static int i=0;
    TreeNode* newNode = new TreeNode(A[i]);
    if(!A[i])return NULL;
    if(A[i] == 'L')
        return newNode;
    i++;
    newNode->left = buildTree(A);
    i++;
    newNode->right = buildTree(A);
    return newNode;
}

int main(){
    char A[]={'I','I','L','L','I','I','L','L','L','\0'};
    TreeNode* root = buildTree(A);
    cout<<"Pre order traversal is\n";
    preorder(root);
    cout<<"\nIn order traversal is\n";
    inorder(root);
    cout<<"\nPost order traversal is\n";
    postorder(root);
}
