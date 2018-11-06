//
// Created by weiqi wang on 11/4/18.
// Block stored information about transaction after hashed
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include "transaction.h"

using namespace std;


//Block class
class Block {

private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();

public:
    //Constructor
    Block(int idx, TransactionData d,size_t prevHash); //cannot use initialize list to initialize blockhash

    //get original hash
    size_t getHash();

    int getIndex();

    //get previous hash
    size_t getPreviousHash();

    size_t getGenerate();

    //transaction data
    TransactionData data;

    //valid hash
    bool isValidHash();
};

Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}


size_t Block::generateHash() {
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash;
    string toHash = to_string(data.amount) + data.receiveKey + data.senderKey + to_string(data.timeStamp);

    return finalHash(hash1(toHash) + hash2(previousHash));
};

size_t Block::getGenerate(){
    return generateHash();
};

size_t Block::getHash() {
    return blockHash;
};

int Block::getIndex() {
    return index;
};


size_t Block::getPreviousHash() {
    return previousHash;
};

bool Block::isValidHash() {
   // cout <<  generateHash() << endl;
    // cout << blockHash << endl;
    return generateHash() == getHash(); // blockHash initialized with generateHash(), if any data manipulated, generateHash will return value different from blockhash
};




#endif //BLOCKCHAIN_BLOCK_H
