#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "transaction.hh"


#include "cryptopp820/cryptlib.h"
#include "cryptopp820/sha3.h"

typedef std::string string;

class Block{
public:
  int index;
  std::vector<Transaction> transactions;
  string timestamp;
  string previous_hash;
  int nonce;

  string hash;

  // default constructor
  Block() {}

  // constructor
  Block(int index, std::vector<Transaction> transactions, string timestamp, string previous_hash, int nonce = 0);

  // returns the hash of all the data
  string compute_hash();

  // converts this object to string Json format
  string toJson();
};

string hexToString(string s);
