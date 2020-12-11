#include "Trie.h"

Trie* get(Trie* p, string key, int d);
Trie* findNode(Trie* p, string key);
Trie* put(Trie* p, string key, string val, int d);
void Insertion(Trie* root, string key, string val);
void collect(Trie* p, string prefix, int d);
void keysWithPrefix(Trie* root, string prefix) {
    Trie* p = get(root, prefix, 0);
    int d = prefix.length();
    collect(p, prefix, d);
}
int search(Trie* p, string s, int d, int length){
    if (p == NULL) return length;
    if (!p->value.empty()) length = d;
    if (d == s.length()) return length;
    int c = s[d];
    return search(p->next[c], s, d + 1, length);
}
string longestPrefixOf(Trie* root, string s){
    int length = search(root, s, 0, 0);
    string result;
    for (int i = 0; i < length; i++) {
        result.push_back(s[i]);
    }
    return result;
}
Trie* del(Trie* p, string key, int d){
    if (p == NULL) return NULL;
    if (d == key.length())
        p->value = "";
    else {
        int c = key[d];
        p->next[c] = del(p->next[c], key, d + 1);
    }
    if (p->value.empty()) return p;
    for (int c = 0; c < 26; c++)
        if (p->next[c] != NULL) return p;
    delete p;
    return NULL;
}
void Deletion(Trie* root, string key){
    Trie* root = del(root, key, 0);
}
