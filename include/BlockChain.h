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
    int index = (int)chain.size() - 1;
    Block newBlock(index, d, getLastedBlock() -> getHash());
    //chain.push_back(newBlock);
};

bool BlockChain::isChainValid() {
    vector<Block>::iterator it;
    int chainLen = (int)chain.size();
    cout << "Blockchain length: "<< chainLen << endl;
    for(it = chain.begin(); it != chain.end(); it++){
        Block currentBlock = *it;
        if (!currentBlock.isValidHash()){ //data in block manipulated
            return false;
        }

        if (chainLen > 1){
            Block prevBlock = *(it - 1);
            if (currentBlock.getPreviousHash()!=prevBlock.getHash()){
                return false;
            }
        }
    }

    return true;
}
#endif //BLOCKCHAIN_BLOCKCHAIN_H
