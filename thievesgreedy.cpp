#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    double remainKg;   // how much is left in the shop
    double valuePerKg; // value per kg (constant)
};

// Greedy function: simulate one thief stealing
double stealOneThief(double capacity, vector<Item>& items, int thiefId) {
    double profit = 0.0;
    vector<pair<string,double>> took;

    for (auto &it : items) {
        if (capacity <= 0) break;
        if (it.remainKg <= 0) continue;

        double take = min(it.remainKg, capacity);
        profit += take * it.valuePerKg;
        it.remainKg -= take;
        capacity -= take;
        took.push_back({it.name, take});
    }

    // Print what this thief took
    cout << "Thief " << thiefId << " carries:\n";
    for (auto &p : took) {
        cout << "  " << fixed << setprecision(0) << p.second << " kg of " << p.first << "\n";
    }
    cout << "Profit = " << fixed << setprecision(0) << profit << "\n\n";

    return profit;
}

int main() {
    // Initial shop stock
    vector<Item> items = {
        {"Rice", 12, 840.0/12},
        {"Salt", 10, 870.0/10},
        {"Saffron", 8, 2000.0/8},
        {"Sugar", 5, 500.0/5}
    };

    // Sort by value density (highest first)
    sort(items.begin(), items.end(), [](const Item &a, const Item &b){
        return a.valuePerKg > b.valuePerKg;
    });

    double thiefCapacity = 9.0;
    int thiefCount = 0;
    double totalProfit = 0.0;

    while (true) {
        bool shopEmpty = true;
        for (auto &it : items) if (it.remainKg > 0) shopEmpty = false;
        if (shopEmpty) break;

        thiefCount++;
        totalProfit += stealOneThief(thiefCapacity, items, thiefCount);
    }

    cout << "Total thieves needed = " << thiefCount << "\n";
    cout << "Total profit from shop = " << fixed << setprecision(0) << totalProfit << "\n";

    return 0;
}