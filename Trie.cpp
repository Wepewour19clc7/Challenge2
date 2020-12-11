#include "Trie.h"

Node* get(Node* p, string key, int d){
    if (p == NULL) return NULL;
    if (d == key.length()) return p;
    int c = key[d];
    return get(p->next[c], key, d + 1);
}
Node* findNode(Node* p, string key){
    p = get(p, key, 0);
    return (p && !p->value.empty()) ? p : NULL;
}
Node* put(Node* p, string key, string val, int d){
    if (p == NULL) {
        p = new Node;
        for (int i = 0; i < 26; i++) p->next[i] = NULL;
    }
    if (d == key.length()) {
        p->value = val;
        return p;
    }
    int c = key[d];
    p->next[c] = put(p->next[c], key, val, d + 1);
    return p;
}
void Insertion(Node* root, string key, string val){
    root = put(root, key, val, 0);
}
void collect(Node* p, string prefix, int d){
    if (p == NULL) return;
    if (!p->value.empty())
        cout << p->value << " " << prefix << endl;
    for (int c = 0; c < 26; c++)
        collect(p->next[c], prefix + char(c), d + 1);
}
void keysWithPrefix(Node* root, string prefix) {
    Node* p = get(root, prefix, 0);
    int d = prefix.length();
    collect(p, prefix, d);
}
int search(Node* p, string s, int d, int length){
    if (p == NULL) return length;
    if (!p->value.empty()) length = d;
    if (d == s.length()) return length;
    int c = s[d];
    return search(p->next[c], s, d + 1, length);
}
string longestPrefixOf(Node* root, string s){
    int length = search(root, s, 0, 0);
    string result;
    for (int i = 0; i < length; i++) {
        result.push_back(s[i]);
    }
    return result;
}
Node* del(Node* p, string key, int d){
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
void Deletion(Node* root, string key){
    Node* root = del(root, key, 0);
}
