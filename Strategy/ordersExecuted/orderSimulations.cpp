#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

struct Order {
    bool isOurs;
    int quantity;
};

int executeOrders(int ourOrderCount, int theirOrderCount, int ourOrderQuantity, int theirOrderQuantity, double executionPercentage) {
    std::vector<Order> orders;
    int totalOrderCount = ourOrderCount + theirOrderCount;

    // Place our orders
    for (int i = 0; i < ourOrderCount; ++i) {
        orders.push_back({true, ourOrderQuantity});
    }

    // Place their orders
    for (int i = 0; i < theirOrderCount; ++i) {
        orders.push_back({false, theirOrderQuantity});
    }

    // Shuffle the orders to randomize
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(orders.begin(), orders.end(), g);

    // Calculate the number of orders to execute
    int ordersToExecute = static_cast<int>(totalOrderCount * executionPercentage);

    // Count how many of our orders get executed
    int ourOrdersExecuted = 0;
    for (int i = 0; i < ordersToExecute; ++i) {
        if (orders[i].isOurs) {
            ourOrdersExecuted++;
        }
    }

    return ourOrdersExecuted;
}

int main() {
    int ourOrdersExecuted = executeOrders(100, 100000, 1, 10, 0.20);
    std::cout << "Number of our orders executed: " << ourOrdersExecuted << std::endl;
    return 0;
}
