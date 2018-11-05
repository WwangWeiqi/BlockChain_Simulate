//
// Created by weiqi wang on 11/4/18.
//

#ifndef BLOCKCHAIN_TRANSACTION_H
#define BLOCKCHAIN_TRANSACTION_H

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//Transaction data
struct TransactionData {
    double amount;
    string senderKey;
    string receiveKey;
    time_t timeStamp;
};

#endif //BLOCKCHAIN_TRANSACTION_H
