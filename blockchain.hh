#include <string>
#include <ctime>
#include <vector>
#include <list>

#include "transaction.hh"
#include "block.hh"

typedef std::string string;


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

  // checks if the given proof is valid
  bool is_valid_proof(Block block, string hash);

  // adds a new transaction to the list
  void add_new_transaction(Transaction transaction);

  // creates a new_block by solving the hash function
  int mine();


};

// Utility Functions

// checks if there are the correct number of 0s in the beginning
bool startsWith0s(int diff, string s);

// returns a string of the current time in seconds
// used to get timestamps
string currTime();
