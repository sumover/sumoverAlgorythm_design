//
// Created by sumover on 19-4-12.
//

#ifndef ALGORYTHM_DESIGN_BAG_0_1_H
#define ALGORYTHM_DESIGN_BAG_0_1_H

#include <cstring>
#include <algorithm>

int bag(int size, const int *weight, const int *price, int n) {
    int matrix[n][size + 1];
    memset(matrix, 0, sizeof(matrix));
    for (int i = weight[n - 1]; i <= size; ++i)
        matrix[n - 1][i] = price[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        for (int j = weight[i]; j <= size; ++j) {
            matrix[i][j] = std::max(matrix[i][j], matrix[i + 1][j - weight[i]] + price[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("%d\n", matrix[i][size]);
    }
    return matrix[0][size];
}

#endif //ALGORYTHM_DESIGN_BAG_0_1_H
