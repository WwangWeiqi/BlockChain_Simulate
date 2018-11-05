//
// Created by weiqi wang on 11/4/18.
//
#include "include/BlockChain.h"
using namespace std;

int main(){
    //start blockchain
    BlockChain AwesomeCoin;

    //data first add to block
    TransactionData iniData;
    time_t dataTime;
    iniData.amount = 1.5;
    iniData.receiveKey = "weiqi";
    iniData.senderKey = "wang";
    iniData.timeStamp = time(&dataTime);

    AwesomeCoin.addBlock(iniData);

    TransactionData Data2;
    time_t dataTime2;
    Data2.amount = 1.5;
    Data2.receiveKey = "weiqi";
    Data2.senderKey = "wang";
    Data2.timeStamp = time(&dataTime2);

    AwesomeCoin.addBlock(Data2);

    cout << "BlockChain valid?" << std::boolalpha<< AwesomeCoin.isChainValid() << endl;
    return 0;
}




