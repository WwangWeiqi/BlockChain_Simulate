//
// Created by weiqi wang on 11/4/18.
//
#include "include/BlockChain.h"
using namespace std;

int main(){
    //start blockchain
    BlockChain AwesomeCoin;

    //add first data
    time_t dataTime;
    TransactionData Data1(1.5,"weiqi","wang",time(&dataTime));
    AwesomeCoin.addBlock(Data1);

    //add second data
    time_t dataTime2;
    TransactionData Data2(1.4442,"ZHANG","YU",time(&dataTime2));
    AwesomeCoin.addBlock(Data2);

    //Test if someone sneaky, will generateHash() again to validate the carried data
    Block *hackBlock = AwesomeCoin.getLastedBlock();
    hackBlock -> data.amount = 10000;
    hackBlock -> data.receiveKey = "yuzhang";

    AwesomeCoin.printChain();
    cout<<endl;


    return 0;
}




