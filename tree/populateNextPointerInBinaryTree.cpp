#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int v){
        val=v;
        left=NULL;
        right=NULL;
        next=NULL;
    }
    TreeNode(int v, TreeNode* l, TreeNode* r){
        val=v;
        left=l;
        right=r;
        next=NULL;
    }
};
void populateNextPointer(TreeNode* root){
    if(!root)return;
    if(!root->left && !root->right)return;

    TreeNode *head, *tail, *cur;
    cur = root;
    head=tail=NULL;

    while(cur){
        if(cur->left){
            if(!tail)
                head = tail = cur->left;
            else{
                tail->next = cur->left;
                tail=tail->next;
            }
        }
        if(cur->right){
            if(!tail)
                head = tail = cur->right;
            else{
                tail->next = cur->right;
                tail=tail->next;
            }
        }
        if(cur->next){
            cur = cur->next;
        }else{
            cur = head;
            head=tail=NULL;
        }
    }
}

int main(){
    TreeNode* root = new TreeNode(5,
            new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), NULL), new TreeNode(4,new TreeNode(8),new TreeNode(9,NULL,new TreeNode(7)))
        );
    populateNextPointer(root);

    cout<<"next pointer of 3 is : "<<root->left->next->val<<endl;
    cout<<"next pointer of 2 is : "<<root->left->left->next->val<<endl;
    cout<<"next pointer of 1 is : "<<root->left->left->right->next->val<<endl;

}
