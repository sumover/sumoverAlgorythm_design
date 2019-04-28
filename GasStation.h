//
// Created by sumover on 19-4-28.
//

#ifndef ALGORYTHM_DESIGN_GASSTATION_H
#define ALGORYTHM_DESIGN_GASSTATION_H

/**
 * donnot use this function!
 * @param begin
 * @param end
 * @param pos
 * @return
 */
int *_search(int *begin, int *end, int pos) {
    if (pos < *begin)return nullptr;
    if (pos == *begin)return begin;
    if (pos > *(end - 1))return end - 1;
    int *__begin = begin, __len = (end - begin);
    while (true) {
        if (__len < 2) {
            return __begin;
        } else {
            int __middle = __len / 2;
            if (pos >= __begin[__middle]) {
                __begin += __middle;
                __len = (__len + 1) / 2;
            } else {
                __len /= 2;
            }
        }
    }
}

/**
 * count how many times you add oil.
 * @param n
 * @param k
 * @param pos
 * @param cnt
 * @return
 */
int countAddOil(int n, int k, int *pos, int cnt = 1) {
    if (k == 1)return cnt;
    int *next_pos = _search(pos + 1, pos + k, *pos + n);
    if (!next_pos)return -1;
    return countAddOil(n, k - (next_pos - pos), next_pos, cnt + 1);
}

#endif //ALGORYTHM_DESIGN_GASSTATION_H
