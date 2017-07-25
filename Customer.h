//
// Created by UserW7m3ra on 7/21/2017.
//

#ifndef BERTINIBUYITEMS_CUSTOMER_H
#define BERTINIBUYITEMS_CUSTOMER_H


#include "header.h"
#include "Order.h"
#define yes 1
#define no 0

class Customer : public Order{
public:
    Customer(string name = "", string surname = "", string address = "", string email = "", double balanceAcount  = 0.00, bool premiumUser = false)
            : name(name), surname(surname), address(address), email(email), balanceAcount(balanceAcount), premiumUser(premiumUser) {}

    Customer changeSettings(Customer &cus){
            string anws, newName, newSurname, newAddress, newEmail, premiumAsk;
            double newBalanceAccount;
            bool premiumUser = false;
            again:
            cout << "\nChange personal info (yes, no): "; cin >> anws;
            if(anws == "yes" || anws == "y"){
                    int slc;
                    cout << "\nSelect ID number: "; cin >> slc;
                    switch (slc){
                            case 1: cout << "New name: "; cin >> newName; cus.setName(newName); break;
                            case 2: cout << "New surname: "; cin >> newSurname; cus.setSurname(newSurname); break;
                            case 3: cout << "New address: "; cin >> newAddress; cus.setAddress(newAddress); break;
                            case 4: cout << "New email: "; cin >> newEmail; cus.setEmail(newEmail); break;
                            case 5: cout << "New balance account: "; cin >> newBalanceAccount; cus.setBalanceAcount(newBalanceAccount); break;
                            default: display(); break;
                    }
                    cout << "\nAccount settings updated successfully!\n" << endl;
                    pauseClear();
                    display();
                    goto again;
            }
            else {
                    cout << endl;
                    pauseClear();
            }
        return cus;
    }
    void pauseClear(){
                system("pause");system("clear"); system("cls");
    }
    void display(){
        cout << "\nPERSONAL ACCOUNT INFO" << endl;
        cout << "---------------------" << endl;
        cout << "[1] Name: "  << name << "\n[2] Surname: " << surname << "\n[3] Address: " << address << "\n[4] Email: " << email << endl;
        cout << "[5] Balance account: " << setprecision(2) << fixed << balanceAcount << "$" << "\n[6] Premium: " << premiumUser << endl << endl;

          //  pauseClear();
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
