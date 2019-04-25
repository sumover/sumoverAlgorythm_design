#include <bits/stdc++.h>
#include <ostream>
#include "Huffman.h"

int main(int argc, char **argv) {

    double value;
    char ch;
    int N;
    std::cin >> N;
    std::map<char, double> map;
    while (N--) {
        std::cin >> ch >> value;
        map[ch] = value;
    }
    huffman_print(build_huffman(map));
    return 0;
}
