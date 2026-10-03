#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;

}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

void levelorder(Node* root){
    if(root==NULL){
        return ;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr  = q.front();
        q.pop();

        if(curr == NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftht = height(root->left);
    int rightht = height(root->right);

    int currht = max(leftht,rightht)+1;

    return currht;
}

int count(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftcount = count(root->left);
    int rightcount = count(root->right);

    int currcount = leftcount+rightcount+1;

    return currcount;
}

int sum(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftsum = sum(root->left);
    int rightsum = sum(root->right);

    int currsum = leftsum+rightsum+root->data;

    return currsum;
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }

    int currDiam = diameter(root->left)+diameter(root->right)+1;
    int leftdiam = diameter(root->left);
    int rightdiam = diameter(root->right);

    return max(currDiam,max(leftdiam,rightdiam));
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    //cout << root->data << endl;
    //postorder(root);
    levelOrder(root);
    levelorder(root);
    cout<<height(root)<<endl;;
    cout<<"count:"<<count(root)<<endl;
    cout<<"sum:"<<sum(root)<<endl;
    cout<<"diam: "<<diameter(root)<<endl;

    return 0;
}