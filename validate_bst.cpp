#include<iostream>
#include<vector>
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

Node* insert(Node* root,int data ){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data<root->val){
        root->left = insert(root->left,data);
    }else if(data>root->val){
        root->right = insert(root->right,data);
    }
    return root;
}

Node* buildbst(int arr[], int n){
    Node* root = NULL;

    for(int i=0;i<n;i++){
        root = insert(root,arr[i]);
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->val == key){
        return true;
    }

    if(root->val>key){
        return search(root->left,key);
    }

    if(root->val<key){
        return search(root->right,key);
    }
}

void printrange(Node* root, int start, int end){
    if(root == NULL){
        return;
    }
    
    if(start<=root->val && root->val<=end){
        cout<<root->val<<" ";
        printrange(root->left,start,end);
        printrange(root->right,start,end);
    }
    
       if(root->val<start){
        printrange(root->right,start,end);
    }

    if(root->val>end){
        printrange(root->left,start,end);
    }
}

void printpath(vector<int> path){
    int n = path.size();
    for(int i=0;i<n;i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void pathhelper(Node* root,vector<int> &path){
    if(root==NULL){
        return;
    }

    path.push_back(root->val);

    if(root->left==NULL && root->right==NULL){
        printpath(path);
        path.pop_back();
        return;
    }

    pathhelper(root->left,path);
    pathhelper(root->right,path);
}

void rootToleafpath(Node* root){
    vector<int> path;
    pathhelper(root,path);

}

bool validate(Node* root, Node* min, Node* max){
    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->val<min->val){
        return false;
    }

    if(max!=NULL && root->val>max->val){
        return false;
    }

    return validate(root->left,min,root) && validate(root->right,root,max);
}
int main(){
    int arr[9]= {5,1,3,4,2,7};
    Node* root = buildbst(arr,6);
    cout<<endl;

    inorder(root);

    cout<<endl;

    cout<<"searching of key: 7"<<endl;
    cout<<search(root,7)<<endl;
    cout<<"print range bt. start to end : ";
    printrange(root,5,12);
    cout<<endl;
    cout<<"root to leaf path : "<<endl;
    rootToleafpath(root);
    cout<<"Validating BST: ";
    cout<<validate(root,NULL,NULL)<<endl;
    return 0;
}