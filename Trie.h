#ifndef _TRIE_H_
#define _TRIE_H_

#include<iostream>
using namespace std;

struct Node
{
    string value;
    Node* next[26];
};

Node* get(Node* p, string key, int d);
Node* findNode(Node* p, string key);
Node* put(Node* p, string key, string val, int d);
void Insertion(Node* root, string key, string val);
void collect(Node* p, string prefix, int d);
void keysWithPrefix(Node* root, string prefix);
int search(Node* p, string s, int d, int length); 
string longestPrefixOf(Node* root, string s);
Node* del(Node* p, string key, int d);
void Deletion(Node* root, string key); 

#endif