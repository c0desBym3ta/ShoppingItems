//
// Created by UserW7m3ra on 7/21/2017.
//

#ifndef BERTINIBUYITEMS_ORDER_H
#define BERTINIBUYITEMS_ORDER_H

#include "header.h"
#include "Items.h"
#include "Customer.h"

class Order {
public:
    void insertItemsToShop(vector<Items> &shopList){
        string itemName,choice;
        double itemPrice;
        cout << "ADDING ITEMS TO THE SHOP" << endl;
        cout << "------------------------" << endl;
        cout << "Type (manual) or (automatic): "; cin >> choice;
        if(choice == "manual" || choice == "m"){
            int slc;
            cout << "How many items do you want to add: "; cin >> slc;
            for(auto i = 0; i<slc; i++){
                cout << "\nItem's name: "; cin >> itemName;
                cout << "Item's price: "; cin >> itemPrice;
                Items newItem(itemName, itemPrice);
                shopList.push_back(newItem);
            }
        }else if(choice == "automatic" || choice == "a"){
            Items laptop("Hp Laptop", 650.78);
            Items iPhone("iPhone", 559.95);
            Items usbStick("KingStone USB 3.0 32 Gb ", 25.93);
            Items lgTv("LG TV 42' ", 899.95);
            Items gps("MLS GPS Destination, 4.5'", 99.94);
            Items sdCard("Micro sd card", 12.25);
            Items nanoSim("Nano sim card", 8.90);
            Items samsungCover("Samsung j5 cover ", 12.99);
            shopList.push_back(laptop);
            shopList.push_back(iPhone);
            shopList.push_back(usbStick);
            shopList.push_back(lgTv);
            shopList.push_back(gps);
            shopList.push_back(sdCard);
            shopList.push_back(nanoSim);
            shopList.push_back(samsungCover);
        }
    }
    void printAvailableItems(const vector<Items> &shopList){
        cout << "\nAVAILABLE SHOP ITEMS" << endl;
        cout << "--------------------" << endl;
        for(auto i = 0; i<shopList.size(); i++){
            cout << "ID:[" << i+1 << "] " << shopList[i].getName() << " " << setprecision(2) << fixed << shopList[i].getPrice() << "$"<< endl;
        }
    }
    double totalPrice(vector<Items> &cusList, bool &premium ){
        double price = 0.00, discount = 0.00;
        if(premium){
            cout << "\nPremium user detected. Discount 15% to items under 15$." << endl;
            for(auto i = 0; i<cusList.size(); i++){
                if(cusList[i].getPrice() <= 15.00){
                    double tmpPrice;
                    cout << "\n\tID:["<<i+1<<"] Actual item's price: " << setprecision(2) << fixed <<cusList[i].getPrice() << "$" << endl;
                    tmpPrice = cusList[i].getPrice();
                    discount = tmpPrice*0.15;
                    tmpPrice -= discount;
                    cusList[i].setPrice(tmpPrice);
                    cout << "\tID:["<<i+1<< "] Item's Price after 15% discount: " << setprecision(2) << fixed << cusList[i].getPrice() << "$" << endl;
                }
                    price += cusList[i].getPrice();
            }
            cout << "\n\t\t\tTotal price: " << setprecision(2) << fixed << price << "$" << endl;
            return price;
        }else{
            for(auto i = 0; i<cusList.size(); i++)
                price += cusList[i].getPrice();
            cout << "\n\t\t\tTotal price: " << setprecision(2) << fixed << price << "$"<< endl;
            return price;
        }
    }
    void deleteFromCart(vector<Items> &cusList){
        int num,id;
        cout << "How many items do you want to remove from your card: "; cin >> num;
        for(auto i = 0; i < num; i++){
            cout << "Which items do you want to remove (select ID): "; cin >> id;
            cusList.pop_back();
        }
    }
    void makeOrder(vector<Items> &shopList, vector<Items> &cusList){
        int id,num;
        cout << "\nHow many items you want to add to your shopping cart: "; cin >> num;
        cout << endl;
        for(auto i = 0; i<num; i++){
            cout << "Which item do you want yo buy (select ID): "; cin >> id;
            cusList.push_back(shopList[id-1]);
        }
    }

    int testOrder(vector<Items> &shopList, vector<Items> &cusList){
        int id,num;
        cout << "\nHow many items you want to add to your shopping cart: "; cin >> num;
        cout << endl;
        try{
            if(num > shopList.size())
                throw runtime_error("ERROR 99: ");
        }catch(runtime_error &error){
            cout << error.what() << "You cannot by more items than the shop has." << endl;
            exit;
        }

            /*cout << "How many items you want to add to your shopping cart: "; cin >> num;
            cout << endl;
            for(auto i = 0; i<num; i++){
                cout << "Which item do you want yo buy (select ID): "; cin >> id;
                cusList.push_back(shopList[id-1]);
            }
             */
    }

    void checkShopCart(vector<Items> cusList){
        cout << "\nCUSTOMER SHOP CART" << endl;
        cout << "------------------" << endl;
        for(auto i = 0; i<cusList.size(); i++){
            cout << i+1 <<") " << cusList[i].getName() << " " << setprecision(2) << fixed<< cusList[i].getPrice() << "$" << endl;
        }
    }
private:
};

#endif //BERTINIBUYITEMS_ORDER_H