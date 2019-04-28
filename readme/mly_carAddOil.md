### 实验过程
```C++
#include <bits/stdc++.h>
using namespace std;
void Greed(int *cost, int n, int k)
{
    int sum = 0, now = n;
    for (int i = 0; i <= k; ++i)
    {
        if (cost[i] <= now)
        {
            now -= cost[i];
        }
        else
        {
            if (cost[i] <= n)
            {
                sum++;
                now = n - cost[i];
            }
            else
            {
                sum = -1;
                break;
            }
        }
    }
    if (sum == -1)
        cout << "No Solution\n";
    else
        cout << sum << endl;
}
int main()
{
    int n, k, *cost;
    cin >> n >> k;
    cost = new int[k + 10];
    for (int i = 0; i <= k; ++i)
    {
        cin >> cost[i];
    }
    Greed(cost, n, k);
    return 0;
}
```
### 运行结果

#### input:

```text
7 7
1 2 3 4 5 1 6 6
```

#### output:
```text
4
```
