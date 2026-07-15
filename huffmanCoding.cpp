#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
        return;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;
    char ch[n];
    int freq[n];
    for (int i = 0; i < n; i++)
        cin >> ch[i] >> freq[i];

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < n; i++)
        pq.push(new Node(ch[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    printCodes(pq.top(), "");

    return 0;
}
