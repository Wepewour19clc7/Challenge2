#include "Trie.h"

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
