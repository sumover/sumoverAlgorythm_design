#include <bits/stdc++.h>
#include "bag_0_1.h"

int main(int argc, char **argv) {
    int *weight, *price, N, size;
    std::cin >> N >> size;
    weight = new int[N], price = new int[N];
    for (int i = 0; i < N; ++i)
        scanf("%d%d", weight + i, price + i);
    printf("%d\n",bag(size, weight, price, N));
    return 0;
}
