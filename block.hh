#include <string>
#include <std>
#include "transaction.hh"

using namespace CryptoPP;
#include "cryptlib.h"
#include "sha3.h"

class Block{
public:
  int index;
  std_vector<Transaction> transactions;
  string timestamp;
  string previous_hash;
  int nonce;

  string hash;

  Block(int index, std::vector<Transaction> transactions, string timestamp, string previous_hash, int nonce = 0);

  string compute_hash();

  string toJson();
}
