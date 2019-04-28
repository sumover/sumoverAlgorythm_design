#include <bits/stdc++.h>
#include "GasStation.h"

int main(int argc, char **argv) {
/*
    int *arr = new int[5]{2, 4, 6, 8, 10};
    std::cout << _search(arr, arr + 5, 10) - arr;

    /**/
    int n, k;
    std::cin >> n >> k;
    int *arr = new int[k];
    for (int i = 0; i < k; ++i)
        scanf("%d", arr + i);
    std::cout << countAddOil(n, k, arr);/**/
    return 0;
}