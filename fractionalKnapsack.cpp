#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n;
    cin >> n;
    Item items[n];
    for (int i = 0; i < n; i++)
        cin >> items[i].weight >> items[i].value;

    int capacity;
    cin >> capacity;

    sort(items, items + n, compare);

    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) break;
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0;
        }
    }

    cout << "Max value: " << totalValue << endl;

    return 0;
}
