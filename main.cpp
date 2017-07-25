#include "header.h"
#include "Customer.h"
#include "Items.h"
#include "Order.h"
#include "Program.h"

bool checkAccount(){
    Customer cus;
    cus.createAccount(cus);
    cus.login();
}

int main() {
    Program program;
    if(checkAccount())
        program.testInit();

    program.line();
    program.pauseClear();
    return 0;
}

