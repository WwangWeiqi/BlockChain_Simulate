//
// Created by weiqi wang on 11/4/18.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include "Block.h"
using namespace std;

//BlockChain
class BlockChain {

private:
    Block createGenesisBlock();
    vector<Block> chain;

public:
    //constructor
    BlockChain(){
        Block genesis = createGenesisBlock();
        chain.push_back(genesis);
    };

    //public function
    void addBlock(TransactionData data);
    bool isChainValid();
    void printChain();


    //for demo
    Block *getLastedBlock();
};

Block BlockChain::createGenesisBlock() {
    time_t current;
    TransactionData d;
    d.amount = 0;
    d.receiveKey = "none";
    d.senderKey = "none";
    d.timeStamp = time(&current);

    hash<int> hash1;
    Block genesis(0,d,hash1(0));
    return genesis;

};

Block *BlockChain::getLastedBlock() {
    return &chain.back();
}

void BlockChain::addBlock(TransactionData d) {
    int index = (int)chain.size();
    cout << "add block" << endl;
    size_t prevHash = (int)chain.size() > 0? getLastedBlock() -> getHash():0;
    Block newBlock(index, d, prevHash);
    chain.push_back(newBlock);
};

bool BlockChain::isChainValid() {
    vector<Block>::iterator it;
    int chainLen = (int)chain.size();
    cout << "Blockchain length: "<< chainLen << endl;
    for(it = chain.begin(); it != chain.end(); it++){
        Block currentBlock = *it;
        if (!currentBlock.isValidHash()){ //data in block manipulated
            cout<<"data in current block manipulated"<<endl;
            return false;
        }

        if (it != chain.begin()){
            Block prevBlock = *(it - 1);
            if (currentBlock.getPreviousHash()!=prevBlock.getHash()){
                cout<<"data in prev block manipulated"<<endl;
                return false;
            }
        }
    }

    return true;
}

void BlockChain::printChain() {
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        printf("\n\nBlock ===================================");
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount);
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.receiveKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.timeStamp);
        printf("\nHash: %zu", currentBlock.getHash());
        printf("\nGenerate to Validate: %zu", currentBlock.getGenerate());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid?: %d", currentBlock.isValidHash());
    }
}
#endif //BLOCKCHAIN_BLOCKCHAIN_H
