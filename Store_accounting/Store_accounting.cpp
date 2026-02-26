#include <Windows.h>
#include <iostream>


using namespace std;

struct Item {
    string name;
    int price;
    int quantity;
};

struct Order {
    int id;
    int customer;
    Item* Items;
};

int main()
{
    cout << "Hello World!\n";
}
