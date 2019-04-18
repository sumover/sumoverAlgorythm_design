### 实验环境:

    OS:ubuntu 18.1.04 LTS
    compiler:c++11,g++
    MakeTool:CMake

### 实验原理




```text
此处填写具体原理
```

### 实验过程
```c++
#include <bits/stdc++.h>

using namespace std;

class JobType
{
public:
    int key, pos, type;

    bool operator<=(JobType a)
    {
        return key <= a.key;
    }
};

bool cmp(const JobType& a, const JobType& b)
{
    return a.key <= b.key;
}

int FlowShop(int n, int *a, int *b, int *c)
{
    JobType jobtype[n + 10];
    for (int i = 0; i < n; ++i)
    {
        jobtype[i].pos = i;
        if (a[i] >= b[i])
        {
            jobtype[i].key = b[i];
            jobtype[i].type = 1;
        } else
        {
            jobtype[i].key = a[i];
            jobtype[i].type = 0;
        }
    }

    sort(jobtype, jobtype + n, cmp);

    int j = 0, k = n - 1;
    for (int i = 0; i < n; ++i)
    {
        if (jobtype[i].type)
            c[k--] = jobtype[i].pos;
        else
            c[j++] = jobtype[i].pos;
    }
    j = k = 0;
    for (int i = 0; i < n; ++i)
    {
        j += a[c[i]];
        k = max(j + b[c[i]], k + b[c[i]]);
    }
    return k;

}

int main()
{
    int n;
    int *a, *b, *c;
    cin >> n;
    a = new int[n + 10];
    b = new int[n + 10];
    c = new int[n + 10];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    cout << FlowShop(n, a, b, c) << endl;
    for (int i = 0; i < n; ++i)
        cout << c[i] << " ";
    return 0;
}
```
### 运行结果

#### input:

```text
4
3 4 8 10
6 2 9 15
```

#### output:
```text
38
0 2 3 1
```
