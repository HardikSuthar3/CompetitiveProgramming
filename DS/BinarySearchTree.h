#include w<iostream>
#include "bits/stdc++.h"

using namespace std;

class Node {
public:
    int data;
    bool visited;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *root;

void BFS(Node *start) {
    if (start == NULL) {
        return;
    }
    queue<Node *> queueBfs;
    queueBfs.push(start);
    while (!queueBfs.empty()) {
        Node *u = queueBfs.front();
        queueBfs.pop();

        cout << u->data << " ";
        u->visited = true;

        if (u->left != NULL && u->left->visited == false) {
            queueBfs.push(u->left);
        }

        if (u->right != NULL && u->right->visited == false) {
            queueBfs.push(u->right);
        }
    }
}

void DFS(Node *start) {
    if (start == NULL) {
        return;
    }

    std::cout << start->data << ' ';
    start->visited = true;
    if (start->left != NULL && start->left->visited == false) {
        DFS(start->left);
    }

    if (start->right != NULL && start->right->visited == false) {
        DFS(start->right);
    }
}


