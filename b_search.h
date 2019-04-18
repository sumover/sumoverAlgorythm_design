//
// Created by sumover on 19-4-11.
//

#ifndef ALGORYTHM_DESIGN_B_SEARCH_H
#define ALGORYTHM_DESIGN_B_SEARCH_H
#define endless while(true)

template<typename type>
int b_search(type *const arr, const int len, const type &fund) {
    type *__arr = arr;
    int __len = len;
    endless {
        if (__len < 2) {
            if (__arr[0] != fund)return -1;
            return static_cast<int>(__arr - arr);
        }
        int __middle = (__len) / 2;
        if (fund < __arr[__middle]) {
            __len = __middle;
        } else {
            __len = (__len + 1) / 2;
            __arr += __middle;
        }
    }
}

#endif //ALGORYTHM_DESIGN_B_SEARCH_H
