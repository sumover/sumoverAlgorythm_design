### 实验环境:

    OS:ubuntu 18.1.04 LTS
    compiler:c++11,g++
    MakeTool:CMake

### 实验原理

```text
此处填写具体原理
```

### 实验过程
```C++
#define Job_used
#ifdef Job_used

struct Job {
    int key, index;
    bool job;
};

#include <algorithm>

#endif // JOB_USED

int flow_shop(const int *a, const int *b, int *c, int n) {
    Job *jobs = new Job[n];
    for (int i = 0; i < n; ++i) {
        jobs[i].key = std::min(a[i], b[i]);
        jobs[i].job = a[i] <= b[i];
        jobs[i].index = i;
    }
    std::sort(jobs, jobs + n, [](const Job &job1, const Job &job2) -> bool { return job1.key < job2.key; });
    int j = 0, k = n - 1;
    for (int i = 0; i < n; ++i) {
        if (jobs[i].job)c[j++] = jobs[i].index;
        else c[k--] = jobs[i].index;
    }
    j = a[c[0]];
    k = j + b[c[0]];
    for (int i = 0; i < n; ++i) {
        j += a[c[i]];
        k = j < k ? (k + b[c[i]]) : (j + b[c[i]]);
    }
    delete[] (jobs);
    return k;
}

#undef Job_used
#define Job #error couldnot use Job!
#include <bits/stdc++.h>

using namespace std;

#include "Water_work_Johnson.h"

int main(int argc, char **argv) {
    int n, *a, *b, *c;
    cin >> n;
    a = new int[n], b = new int[n], c = new int[n];
    for (int i = 0; i < n; ++i)scanf("%d", a + i);
    for (int i = 0; i < n; ++i)scanf("%d", b + i);
    cout << flow_shop(a, b, c, n) << endl;
    for (int i = 0; i < n; ++i)cout << c[i] << ' ';
}
```
### 运行结果

#### input:

```text
4
1 2 3 4
2 3 4 5
```

#### output:
```text
17
0 1 2 3
```
