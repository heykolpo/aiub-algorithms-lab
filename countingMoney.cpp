#include <iostream>
using namespace std;

void countMoney(int amount) {
  int denominations[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int n = sizeof(denominations) / sizeof(denominations[0]);

  for (int i = 0; i < n; i++) {
    if (amount >= denominations[i]) {
      int count = amount / denominations[i];
      amount = amount % denominations[i];
      cout << denominations[i] << " x " << count << endl;
    }
  }
}

int main() {
  int amount;
  cout << "Enter amount: ";
  cin >> amount;

  if (amount < 0) {
    cout << "Invalid amount" << endl;
    return 1;
  }

  countMoney(amount);
  return 0;
}
