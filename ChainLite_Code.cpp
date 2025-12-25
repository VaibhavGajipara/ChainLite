#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <functional>

using namespace std;

string sha256(const string &input) 
{
    hash<string> hasher;
    size_t h = hasher(input);
    stringstream ss;
    ss << hex << setw(16) << setfill('0') << h;
    return ss.str();
}

class Block 
{
public:
    int index;
    string data;
    string previousHash;
    string hash;
    long long timestamp;
    int nonce;
    Block* next; 
    Block(int idx,string data,string prevHash) : index(idx),data(data),previousHash(prevHash),nonce(0),next(nullptr)
    {
        timestamp = time(nullptr);
        hash = calculateHash();
    }
    string calculateHash() const 
    {
        stringstream ss;
        ss << index << timestamp << data << previousHash << nonce;
        return sha256(ss.str());
    }
    void mineBlock(int difficulty) 
    {
        string target(difficulty, '0');
        while (hash.substr(0, difficulty) != target) 
        {
            nonce++;
            hash = calculateHash();
        }
        cout << "Block mined: " << hash << endl;
    }
};

class Blockchain 
{
private:
    Block* head;   
    Block* tail;   
    int difficulty;
    int size;
public:
    Blockchain(int diff=3) : head(nullptr),tail(nullptr),difficulty(diff),size(0)
    {
        Block* genesis = createGenesisBlock();
        head = tail = genesis;
        size = 1;
    }
    Block* createGenesisBlock() 
    {
        cout << "Creating Genesis Block..." << endl;
        return new Block(0, "Genesis Block", "0");
    }
    void addBlock(string data) 
    {
        cout << "\nMining block " << size << "..." << endl;
        Block *newBlock = new Block(size, data, tail->hash);
        newBlock->mineBlock(difficulty);
        tail->next = newBlock;
        tail = newBlock;
        size++;
    }
    bool isChainValid() const 
    {
        Block *temp = head;
        while (temp && temp->next) {
            Block* nextBlock = temp->next;

            if (nextBlock->hash != nextBlock->calculateHash())
                return false;
            if (nextBlock->previousHash != temp->hash)
                return false;

            temp = nextBlock;
        }
        return true;
    }
    void printChain() const 
    {
        Block* temp = head;
        while (temp != nullptr) {
            cout << "\n----- Block " << temp->index << " -----\n";
            cout << "Timestamp: " << temp->timestamp << endl;
            cout << "Data: " << temp->data << endl;
            cout << "PrevHash: " << temp->previousHash << endl;
            cout << "Hash: " << temp->hash << endl;
            cout << "Nonce: " << temp->nonce << endl;
            temp = temp->next;
        }
    }
    ~Blockchain() 
    {
        Block* temp = head;
        while (temp) {
            Block* nextBlock = temp->next;
            delete temp;
            temp = nextBlock;
        }
    }
};

int main() 
{
    Blockchain myChain(3);
    myChain.addBlock("Alice pays Bob 10 coins");
    myChain.addBlock("Bob pays Charlie 5 coins");
    myChain.addBlock("Charlie pays Dave 2 coins");
    cout << "\nBlockchain:\n";
    myChain.printChain();
    cout << "\nIs blockchain valid? "<<(myChain.isChainValid() ? "YES" : "NO") << endl;
    return 0;
}