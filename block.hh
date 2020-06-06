#include <string>
#include <std>
#include "transaction.hh"

class Block{
public:
  int index;
  std_vector<Transaction>;
  string timestamp;
  string previous_hash;
  int nonce;

  Block(int index, std::vector<Transaction>, string timestamp, string previous_hash, nonce = 0);
  string compute_hash();
}
