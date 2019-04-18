//
// Created by sumover on 19-4-11.
//
//流水作业调度
#ifndef ALGORYTHM_DESIGN_WATER_WORK_JOHNSON_H
#define ALGORYTHM_DESIGN_WATER_WORK_JOHNSON_H
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
    std::sort(jobs, jobs + n, [](const Job &job1, const Job &job2) -> bool {
        return job1.key < job2.key;
    });
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
#endif //ALGORYTHM_DESIGN_WATER_WORK_JOHNSON_H
