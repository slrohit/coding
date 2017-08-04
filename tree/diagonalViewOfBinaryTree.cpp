#include<iostream>
#include <map>
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

void viewUtil(TreeNode* root, int idx, map<int,int>&mp){
    if(!root)return;
    map<int,int>::iterator it=mp.find(root->val);
    if( it!= mp.end()){
        if(it->first < idx){
            mp[idx] = root->val;
        }
    }else{
        mp[idx] = root->val;
    }
    mp[idx] = root->val;
    if(root->left)viewUtil(root->left,idx,mp);
    if(root->right)viewUtil(root->right,idx+1,mp);
}

map<int, int> view(TreeNode* root){
    map<int, int> mp;
    viewUtil(root,0, mp);
    for(map<int,int>::iterator it=mp.begin(); it!=mp.end();it++){
        cout<<it->first<<" => "<<it->second<<endl;
    }
    return mp;
}


int main(){
    TreeNode* root = new TreeNode(5,
        new TreeNode(3, new TreeNode(2,NULL,new TreeNode(1,new TreeNode(6),NULL)), new TreeNode(7)), new TreeNode(4,new TreeNode(8),new TreeNode(9))
    );
    view(root);
}

