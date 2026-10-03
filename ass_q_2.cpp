#include<iostream>
#include<vector>
#include<climits>  
using namespace std;

class Node{
    public:

    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left=right=NULL;
    }

};

int findnode(Node* root, int k){
    if(root==NULL){
        return -1;
    }
    int ans = root->val;
    while(root!=NULL){
        int diff = abs(root->val-k);
        if(diff<abs(ans-k)){
            ans = root->val;
        }

        if(root->val == k){
            return root->val;
        }
        if(k<root->val){
           root =  root->left;
        }else{
              root = root->right;
        }
    }
    return ans;
}



int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(6);

    root->right = new Node(11);
    root->right->right = new Node(20);


    cout<<"node : ";
    cout<<findnode(root,19)<<endl;

    return 0;
}