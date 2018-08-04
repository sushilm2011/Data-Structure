#include<iostream>
using namespace std;


class BinaryTree{
    class Node{
        int data;
        Node *left;
        Node *right;
    public:
        Node(int data);
        Node();
        int getData();
        bool setData(int);
        Node *getLeft();
        Node *getRight();
        bool setLeft(Node *);
        bool setRight(Node *);
    };
    Node *root;
    BinaryTree::Node* createFromString(string, int&);
    void _preOrder(Node*);
    void _postOrder(Node*);
    void _inOrder(Node*);
    void _getKthLevelNodesSum(Node*,int,int,int&);
public:
	BinaryTree();
	BinaryTree(string);
	void preOrder();
	void postOrder();
	void inOrder();
	int getKthLevelNodesSum(int);
};

//Function Definitions
BinaryTree::Node::Node(int data){
    this->data = data;
    this->left = this->right = NULL;
}

BinaryTree::Node::Node(){
    this->left = this->right = NULL;
}

int BinaryTree::Node::getData(){
    return this->data;
}

bool BinaryTree::Node::setData(int data){
    this->data = data;
    return true;
}

BinaryTree::Node* BinaryTree::Node::getLeft(){
    return this->left;
}

BinaryTree::Node* BinaryTree::Node::getRight(){
    return this->right;
}

bool BinaryTree::Node::setLeft(Node* left){
    this->left = left;
}

bool BinaryTree::Node::setRight(Node* right){
    this->right = right;
}

BinaryTree::BinaryTree(){
	root = NULL;
}

BinaryTree::BinaryTree(string serializedTree){
	int i = 0;
	this->root = createFromString(serializedTree, i);
}

BinaryTree::Node* BinaryTree::createFromString(string input, int &i){
	if(i>=input.length()){
		return NULL;
	}
	//if Leaf Node
	if(input[i]=='(' && input[i+1]==')'){
		i+=2;
		return NULL;
	}
	//find the next node
	while(i<input.length() && input[i]!='('){
		i++;
	}

	//create Node and the subtrees
	if(i<input.length() && input[i]=='('){
		int data =0;
		i++;
		while(input[i]>='0' && input[i]<='9'){
			data = data*10 + (input[i]-'0');
			i++;
		}
		Node* node = new Node(data);
		node->setLeft(createFromString(input, i));
		node->setRight(createFromString(input, i));
		return node;
	}
	return NULL;
}

void BinaryTree::preOrder(){
	_preOrder(root);
}

void BinaryTree::_preOrder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->getData()<<" ";
	_preOrder(root->getLeft());
	_preOrder(root->getRight());
}

void BinaryTree::postOrder(){
	_preOrder(root);
}

void BinaryTree::_postOrder(Node* root){
	if(root == NULL){
		return;
	}
	_preOrder(root->getLeft());
	_preOrder(root->getRight());
	cout<<root->getData()<<" ";
}

void BinaryTree::inOrder(){
	_inOrder(root);
}

void BinaryTree::_inOrder(Node* root){
	if(root == NULL){
		return;
	}
	_preOrder(root->getLeft());
	cout<<root->getData()<<" ";
	_preOrder(root->getRight());
}

void BinaryTree::_getKthLevelNodesSum(Node* root, int k, int level, int &sum){
	if(root == NULL){
		return;
	}
	if(level == k){
		sum+=root->getData();
		return;
	}
	_getKthLevelNodesSum(root->getLeft(), k, level+1, sum);
	_getKthLevelNodesSum(root->getRight(), k, level+1, sum);
}

int BinaryTree::getKthLevelNodesSum(int k){
	int sum = 0;
	_getKthLevelNodesSum(root, k, 0, sum);
	return sum;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int k;
        string s;
        cin>>k>>s;
        BinaryTree bt(s);
        cout<<bt.getKthLevelNodesSum(k)<<endl;
    }
    return 0;
}
