#include<iostream>
#include<stack>
#include<queue>
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
void preorder(TreeNode* root);
void inorder(TreeNode* root);
void postorder(TreeNode* root);

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

void levelorder(TreeNode* root){
    if(!root)return;
    queue<TreeNode*> q;
    TreeNode* temp;
    q.push(root);
    while(!q.empty()){
        temp = q.front();q.pop();
        cout<<temp->val<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}


int main(){
    TreeNode* root = new TreeNode(5,
        new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), new TreeNode(7)), new TreeNode(4,new TreeNode(8),new TreeNode(9))
    );
    cout<<"Pre order traversal is\n";
    preorder(root);
    cout<<"\nIn order traversal is\n";
    inorder(root);
    cout<<"\nPost order traversal is\n";
    postorder(root);
    cout<<"\nLevel order traversal is\n";
    levelorder(root);
}
