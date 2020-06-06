#include <std>
#include <string>

#include "transaction.hh"
#include "block.hh"

class Blockchain
{
public:
  std::vector<Transaction> unconfirmed_transactions;
  std::list<Block> chain;

  Block last_block;
  int difficulty;

  // constructor
  Blockchain();

  // creates first block
  void create_genesis_block();

  // returns the hash calculated for this block
  string proof_of_work(Block block);

  // adds a block to the chain
  bool add_block(Block block, string proof);

  bool is_valid_proof(Block block,  string hash);

  void add_new_transaction(Transaction transaction);

  int mine();


}
