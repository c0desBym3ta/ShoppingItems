#include "header.h"
#include "Customer.h"
#include "Items.h"
#include "Order.h"

void line();
void options();

int main() {
    vector<Items> cusList;
    vector<Items> shopList;
    Order order;
    Customer josh("Josh", "Yales", "Valdera 27", true);
    order.insertItemsToShop(shopList);
    //order.printAvailableItems(shopList);
    line();

    bool premium = josh.isPremium();
    int option;

    bool flag = true;
    while (flag) {
        options();
        cout << "\n\t\tSelect an option: ";
        cin >> option;
        switch (option) {
            case 1: order.printAvailableItems(shopList); break;
            case 2: josh.makeOrder(shopList, cusList); break;
            case 3: josh.checkShopCart(cusList); break;
            case 4: josh.totalPrice(cusList, premium); break;
            case 5: cout << "\nThank you for buiyng from us." << endl; flag = false; break;
        }
    }

    line();
    system("pause");
    return 0;
}

void line(){
    cout << endl;
}

void options(){
    cout << "\nAVAILABLE OPTIONS" << endl;
    cout << "-----------------" << endl;
    cout << "1) List of available items.\n2) Buy items.\n3) Check shopping cart.\n4) Check total price.\n5) Exit from shop." << endl;
}