#ifndef _TRIE_H_
#define _TRIE_H_

#include<iostream>
using namespace std;

struct Trie
{
    string value;
    Trie* next[26];
};

Trie* get(Trie* p, string key, int d);
Trie* findNode(Trie* p, string key);
Trie* put(Trie* p, string key, string val, int d);
void Insertion(Trie* root, string key, string val);
void collect(Trie* p, string prefix, int d);
void keysWithPrefix(Trie* root, string prefix);
int search(Trie* p, string s, int d, int length); 
string longestPrefixOf(Trie* root, string s);
Trie* del(Trie* p, string key, int d);
void Deletion(Trie* root, string key); 

#endif