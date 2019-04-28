//
// Created by sumover on 19-4-25.
//

#ifndef ALGORYTHM_DESIGN_HUFFMAN_H
#define ALGORYTHM_DESIGN_HUFFMAN_H

#include <map>
#include <queue>
#include <arpa/nameser.h>
#include <ostream>

struct Node {
    double value = 0;
    Node *left = nullptr, *right = nullptr;
    char c = 0;

    Node() = default;

    Node(double v, char c1) : value(v), c(c1) {}

    bool isChar() { return !left; }

    Node(const Node &node) : value(node.value), left(node.left), right(node.right), c(node.c) {}

    bool operator<(const Node &node) const { return !(value < node.value); }
};

struct cmp {
    bool operator()(const Node *node1, const Node *node2) { return *node1 < *node2; }
};

Node *build_huffman(const std::map<char, double> &weight) {
    Node *leaves;
    if (weight.size() == 1)
        return new Node(weight.begin()->second, weight.begin()->first);
    std::priority_queue<Node *, std::vector<Node *>, cmp> queue; // todo
    for (auto &item:weight)
        queue.push(new Node(item.second, item.first));
    while (true) {
        if (queue.size() == 2) {
            leaves = new Node();
            leaves->right = queue.top();
            leaves->value += queue.top()->value;
            queue.pop();
            leaves->left = queue.top();
            leaves->value += queue.top()->value;
            queue.pop();
            return leaves;
        } else {
            leaves = new Node();
            leaves->right = queue.top();
            leaves->value += queue.top()->value;
            queue.pop();
            leaves->left = queue.top();
            leaves->value += queue.top()->value;
            queue.pop();
            queue.push(leaves);
        }
    }
}

#include <stack>
#include <iostream>
#include <algorithm>

std::string binary_print(int temp) {
    std::string string;
    if (!temp)return string = std::string("0");
    while (temp) {
        string += temp & 1 ? "1" : "0";
        temp >>= 1;
    }
    std::reverse(string.begin(), string.end());
    return string;
}

void huffman_print(const Node *root, const int temp = 0) {
    if (root->left->isChar())  // node of left tree is char
        std::cout << root->left->c << " : " << binary_print(temp) << std::endl;
    else huffman_print(root->left, temp << 1);
    if (root->right->isChar())  // node of right tree is char
        std::cout << root->right->c << " : " << binary_print(temp + 1) << std::endl;
    else huffman_print(root->right, (temp + 1) << 1);
}

/**
 * about this function
 * Huffman Constructor
 * the first of pair returned is reformatter,and the second is formatter
 * @param weight
 * @return
 */
std::pair<std::map<int, char>, std::map<char, int>> huffman(const std::map<char, double> &weight) {
    Node *root = build_huffman(weight);

}

#endif //ALGORYTHM_DESIGN_HUFFMAN_H
