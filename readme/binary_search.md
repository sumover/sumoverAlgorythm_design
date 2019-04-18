### 实验环境:

    OS:ubuntu 18.1.04 LTS
    compiler:c++11,g++
    MakeTool:CMake

### 实验原理

```text
将n个元素分为个数相同(n为偶数时)的两半(否则一半为n/2,另一半为n/2+1)
取a[n/2]与比较,若a[n/2]>x,则在数组的左半部分找,否则在另一部分找,
若n为1时,则比较a[0]是否与x比较,如果相同则返回此时的位置,否则则返回-1
```

### 实验过程
```C++
#define endless while(1)

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
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char **argv) {
    int n, *arr;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    int search;
    cin >> search;
    cout << b_search(arr, n, search);
}
```
### 运行结果

#### input:

```text
5
1 2 3 4 5
3
```

#### output:
```text
2
```
