//
// Created by UserW7m3ra on 7/23/2017.
//

#ifndef SHOPPINGITEMS_PROGRAM_H
#define SHOPPINGITEMS_PROGRAM_H

#include "header.h"
#include "Customer.h"
#include "Items.h"
#include "Order.h"

class Program {
public:
    Customer newUser(Customer &newCus){
        string newName, newSurname, newAddress, newEmail, anws;
        double newBalanceAcount;
        bool premiumUser;
        cout << "New user registration." << endl;
        cout << "\nEnter your name: "; cin >> newName;
        cout << "Enter your surname: "; cin >> newSurname;
        cout <<"Enter your address: "; cin >> newAddress;
        cout << "Enter your email: "; cin >> newEmail;
        cout << "Enter your balance account: "; cin >> newBalanceAcount;
        cout << "Are you a premium user: "; cin >> anws;
        if(anws == "yes" || anws == "y") {
            premiumUser = true;
            newCus.setPremiumUser(premiumUser);
        }else{
                premiumUser = false;
                newCus.setPremiumUser(premiumUser);
        }
        newCus.setName(newName); newCus.setSurname(newSurname); newCus.setAddress(newAddress); newCus.setEmail(newEmail); newCus.setBalanceAcount(newBalanceAcount);
        cout << "\nRegistretion completed with success.\n" << endl;
        system("pause"); system("clear"); system("cls");

        return newCus;
    }
    void testInit(){
        vector<Items> cusList;
        vector<Items> shopList;
        Order order;

        Customer josh;
        newUser(josh);
        order.insertItemsToShop(shopList);
        line();

        bool premium = josh.isPremiumUser();
        int option;

        bool flag = true;
        while (flag) {
            options();
            cout << "\n\t\tSelect an option: ";
            cin >> option;
            switch (option) {
                case 1:josh.clearScreen(); order.printAvailableItems(shopList);break;
                case 2:josh.clearScreen(); josh.printAvailableItems(shopList);josh.makeOrder(shopList, cusList);break;
                case 3:josh.clearScreen(); josh.checkShopCart(cusList); break;
                case 4:josh.totalPrice(cusList, premium);break;
                case 5:josh.clearScreen(); josh.display(); break;
                case 6:josh.clearScreen(); break;
                case 7:
                    cout << "\nThank you for using our services." << endl; flag = false; break;
                default :
                    cerr << "\nThis option does not exist. Please select again.\n" << endl;
                    system("pause"); system("clear"); system("cls");
                    break;
            }
        }
    }
    void init(){
        vector<Items> cusList;
        vector<Items> shopList;
        Order order;

        Customer josh;
        newUser(josh);
        order.insertItemsToShop(shopList);
        line();

        bool premium = josh.isPremiumUser();
        int option;

        bool flag = true;
        while (flag) {
            options();
            cout << "\n\t\tSelect an option: ";
            cin >> option;
            switch (option) {
                case 1:josh.clearScreen(); order.printAvailableItems(shopList);break;
                case 2:josh.clearScreen(); josh.printAvailableItems(shopList);josh.makeOrder(shopList, cusList);break;
                case 3:josh.clearScreen(); josh.checkShopCart(cusList); break;
                case 4:josh.totalPrice(cusList, premium);break;
                case 5:josh.clearScreen(); josh.display(); break;
                case 6:josh.clearScreen(); break;
                case 7:
                    cout << "\nThank you for using our services." << endl; flag = false; break;
                default :
                    cerr << "\nThis option does not exist. Please select again.\n" << endl;
                    system("pause"); system("clear"); system("cls");
                    break;
            }
        }
    }
    void line(){
        cout << endl;
    }
    void options(){
        cout << "\nAVAILABLE OPTIONS" << endl;
        cout << "-----------------" << endl;
        cout << "1) List of available items.\n2) Buy items.\n3) Check shopping cart.\n4) Check total price.\n5) Check your profile.\n6) Clear menu screen.\n7) Exit from shop." << endl;
    }
};

#endif //SHOPPINGITEMS_PROGRAM_H
