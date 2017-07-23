//
// Created by UserW7m3ra on 7/21/2017.
//

#ifndef BERTINIBUYITEMS_CUSTOMER_H
#define BERTINIBUYITEMS_CUSTOMER_H


#include "header.h"
#include "Order.h"

class Customer : public Order{
public:
    Customer(string name = "", string surname = "", string address = "", bool premium = false)
            : name(name), surname(surname), address(address), premium(premium) {}

    bool isPremium() const{return premium;}

private:
    string name, surname, address;
    bool premium;
    vector <Items> itemsList;
};


#endif //BERTINIBUYITEMS_CUSTOMER_H
