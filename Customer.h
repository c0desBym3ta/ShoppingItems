//
// Created by UserW7m3ra on 7/21/2017.
//

#ifndef BERTINIBUYITEMS_CUSTOMER_H
#define BERTINIBUYITEMS_CUSTOMER_H


#include "header.h"
#include "Order.h"

class Customer : public Order{
public:
    Customer(string name = "", string surname = "", string address = "", string email = "", double balanceAcount  = 0.00, bool premiumUser = false)
            : name(name), surname(surname), address(address), email(email), balanceAcount(balanceAcount), premiumUser(premiumUser) {}

    void display(){
        cout << "\nPERSONAL ACCOUNT INFO" << endl;
        cout << "---------------------" << endl;
        cout << "Name: "  << name << "\nSurname: " << surname << "\nAddress: " << address << "\nEmail: " << email << endl;
        cout << "Balance account: " << balanceAcount << "$" << "\nPremium: " << premiumUser << endl << endl;
        system("pause");system("clear"); system("cls");
    }

    const string &getName() const {return name;}
    void setName(const string &newName){this->name = newName;}
    const string &getSurname() const{return surname;}
    void setSurname(const string &newSurname){this->surname = newSurname;}
    const string &getAddress() const{return address;}
    void setAddress(const string &newAddress){this->address = newAddress;}
    const string &getEmail() const{return email;}
    void setEmail(const string &newEmail) { this->email = newEmail; }
    bool isPremiumUser() const{return premiumUser;}
    void setPremiumUser(bool newPremiumUser){this->premiumUser = newPremiumUser;}
    double getBalanceAcount() const { return balanceAcount; }
    void setBalanceAcount(double newBalanceAcount) { this->balanceAcount = newBalanceAcount; }

private:
    string name, surname, address, email;
    bool premiumUser;
    double balanceAcount;
    vector <Items> itemsList;
};


#endif //BERTINIBUYITEMS_CUSTOMER_H
