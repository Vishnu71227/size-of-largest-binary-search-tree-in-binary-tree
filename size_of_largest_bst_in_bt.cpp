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

class info{

    public:
    bool isbst;
    int min;
    int max;
    int sz;

    info(bool isbst,int min,int max,int sz){
        this->isbst = isbst;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

static int maxsize;
static Node* largestBstroot;
info* largestBst(Node* root){
    if(root==NULL){
        return new info(true,INT_MAX,INT_MIN,0);   
    }
    //another basecase for leaf node
    /*if(root==NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        return new info(true,root->val,root->val,1);
    }*/
    
    info* leftsubinfo = largestBst(root->left);
    info* rightsubinfo = largestBst(root->right); 
    
    int currmin = min(root->val,min(leftsubinfo->min,rightsubinfo->min));
    int currmax = max(root->val,max(leftsubinfo->max,rightsubinfo->max));
    int currsz = leftsubinfo->sz + rightsubinfo->sz + 1;

    if(leftsubinfo->isbst && rightsubinfo->isbst 
        && (root->val > leftsubinfo->max 
            && root->val < rightsubinfo->min)){
                largestBstroot = root;
                maxsize = max(maxsize,currsz);
        return new info(true,currmin,currmax,currsz);
    }

    return new info(false,currmin,currmax,currsz);
    
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBst(root);
    cout<<"Largest BST is: "<<largestBstroot->val<<endl;
    cout<<"Size of largest BST is: "<<maxsize<<endl;  
    return 0;
}