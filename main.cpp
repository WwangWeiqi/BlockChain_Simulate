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
    Data2.amount = 1.52321;
    Data2.receiveKey = "weiqi";
    Data2.senderKey = "wang";
    Data2.timeStamp = time(&dataTime2);

    AwesomeCoin.addBlock(Data2);

    //Test if someone sneaky, will generateHash() again to validate the carried data
    Block *hackBlock = AwesomeCoin.getLastedBlock();
    hackBlock -> data.amount = 10000;
    hackBlock -> data.receiveKey = "yuzhang";

    AwesomeCoin.printChain();
    cout<<endl;


    return 0;
}




