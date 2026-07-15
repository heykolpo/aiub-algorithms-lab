#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cin >> n;
    Job jobs[n];
    for (int i = 0; i < n; i++)
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;

    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    int slot[maxDeadline + 1];
    bool free[maxDeadline + 1];
    fill(free, free + maxDeadline + 1, true);

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (free[j]) {
                free[j] = false;
                slot[j] = i;
                break;
            }
        }
    }

    cout << "Scheduled jobs: ";
    for (int j = 1; j <= maxDeadline; j++)
        if (!free[j])
            cout << jobs[slot[j]].id << " ";
    cout << endl;

    return 0;
}
