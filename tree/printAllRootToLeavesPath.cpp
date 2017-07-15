#include<iostream>
#include<algorithm>
#include<vector>

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
void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void printAllPathsUtil(TreeNode* root,vector<int> path){
    if(!root)return;
    path.push_back(root->val);
    if(!root->left && !root->right){
        print(path);
    }else{
        printAllPathsUtil(root->left,path);
        printAllPathsUtil(root->right,path);
    }
}

void printAllPaths(TreeNode* root){
    vector<int> v;
    printAllPathsUtil(root,v);
}

int main(){
    TreeNode* root = new TreeNode(5,
        new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), new TreeNode(7)), new TreeNode(4,new TreeNode(8),new TreeNode(9))
    );
    printAllPaths(root);
}

