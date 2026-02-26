#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//preprocessor
#define MAX_DISCOUNT 30
#define SERVICE_COMMISION 7

#define CHECK_PRICE(price) static_assert(price > 0)

struct Item {
    string name;
    double price;
    int quantity;
//constructor    
    Item(string n, double p, int q) :name(n), price(p), quantity(q) {
        if (price < 0) {
            cout << "Item price must be positive.";
        }
        else if (price = 0) {
            cout << "Free item";
        }
    }
    //total price including quantity
    double TotalPriceGet() {
        return price * quantity;
    }
};

struct Order {
    int id;
    string customer;
    vector<Item> items;
    
    Order(int i, string c) :id(i), customer(c) {
        if (id < 0) {
            cout << "Order does not exist.";
        }
    }
//add item in order
    void ItemAdd(const Item& item) {
        items.push_back(item);
    }
    //order summary
    double TotalAmountGet() {
        double total = 0;
        for (auto& item : items) { //loop for calculation sum of prices
            total += item.TotalPriceGet();

        }
        return total;
    }
    //order summary with Discount
    double TotalAmountGetD() {
        double total = TotalAmountGet();
        return total * (100 - MAX_DISCOUNT) / 100;
    }
};


struct Store {
    vector<Order> orders;
    //add order
    void OrderAdd(const Order& order) {
        orders.push_back(order);
    }
    //revenue total
    double TotalRevenueGet() {
        double total = 0;
        for (auto& order : orders) {
            total += order.TotalAmountGet();
        }
        return total;
    }
    //revenue total with discount
    double TotalRevenueGetD() {
        double total = 0;
        for (auto& order : orders) {
            total += order.TotalAmountGetD();
        }
        return total;
    }
    //service commission
    double ServiceCommisionGet() {
        return TotalRevenueGet() * SERVICE_COMMISION / 100;
    }



};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Store store;

    Order order1(1, "Ivan Ivanov");
    order1.ItemAdd(Item("Laptop", 29999, 1));
    order1.ItemAdd(Item("Thermopaste", 305, 2));

    Order order2(2, "Dmitriy Vasilev");
    order2.ItemAdd(Item("MotherBoard", 9999, 1));
    order2.ItemAdd(Item("CPU", 10500, 1));
    order2.ItemAdd(Item("GPU", 16650, 1));

}
