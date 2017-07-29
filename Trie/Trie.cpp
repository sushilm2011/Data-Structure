/****************************************************************
/ Author- Sushil Maurya
/ Purpose- Implementation of Trie DataStructure
/ Helps in searching in a given dictionary of words
****************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Trie{
    class Node{
    public:
        Node* c[26];
        bool isLeaf;
        Node(){
           for(int i=0;i<26;i++){
               c[i] = NULL;
           } 
           isLeaf = false;
        }
    };
    
    Node* root;
    
public:
    Trie(){
       root =new Node(); 
    }
    
    void insert(string word){
        
        int l = word.length();
        
        Node *crawler = root;
        
        for(int i=0;i<l;i++){
            int indx = word[i]-'a';
            if(!crawler->c[indx]){
                crawler->c[indx] = new Node();
            }
            crawler = crawler->c[indx];
        }
        crawler->isLeaf = true;
    }
    
    bool find(string word){
        int l = word.length();
        
        Node *crawler = root;
        
        for(int i=0;i<l;i++){
            int indx = word[i]-'a';
            if(!crawler->c[indx]){
                return false;
            }
            crawler = crawler->c[indx];
        }
        
        if(crawler->isLeaf)
            return true;
        
        return false;
    }
        
};

//Usage
int main(){
	string dictionary[] = {"This", "is", "a", "Trie", "Datastructure"};
	string willbefound = "This";
	string willnotbefound = "Sejal";
	
	//Construction
	Trie trie;
	for(int i=0;i<5;i++){
		trie.insert(dictionary[i]);
	}
	cout<<"Finding: "<<willbefound<<(trie.find(willbefound)==true?" Found":" Not Found")<<endl;
	cout<<"Finding: "<<willnotbefound<<(trie.find(willnotbefound)==true?" Found":" Not Found")<<endl;
	return 0;
}
