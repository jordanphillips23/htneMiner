#include "blockchain.hh"

Blockchain::Blockchain() {
  // starting difficulty
  difficulty = 2;
  unconfirmed_transactions = std::vector<Transaction>();
  chain = std::list<Block>();

  // creates an empty starting block
  create_genesis_block();
  last_block = chain.back();
}

void Blockchain::create_genesis_block() {

  // creates an "empty" block as the genesis block
  Block genesis_block = Block(0, std::vector<Transaction>(), currTime(), "0");

  // stores the hash in the block
  genesis_block.hash =  genesis_block.compute_hash();

  // adds this block to the chain
  chain.push_back(genesis_block);
}

// creates the hash that proves that the inputs were valid
string Blockchain::proof_of_work(Block block) {

  block.nonce = 0;

  string computed_hash = block.compute_hash();
  // in essence has to run the hashfunction at least difficulty times
  // this results in the true final hash
  while (!startsWith0s(difficulty, computed_hash)) {
    block.nonce++;
    computed_hash = block.compute_hash();
  }

  return computed_hash;
}

void Blockchain::add_new_transaction(Transaction transaction) {
  unconfirmed_transactions.push_back(transaction);
}

int Blockchain::mine() {
  // indexes always start from 1
  if (unconfirmed_transactions.empty()) {
    return -1;
  }
  // creates the new block
  Block new_block = Block(last_block.index + 1, unconfirmed_transactions, currTime(), last_block.hash);

  // finds the hash for the new block
  string proof = proof_of_work(new_block);

  // adds that block to the chain
  add_block(new_block, proof);

  return new_block.index;
}

bool Blockchain::add_block(Block block, string proof) {
  string previous_hash = last_block.hash;

  if (previous_hash != block.previous_hash) {
    return false;
  }

  // verifies proof is valid
  if (!is_valid_proof(block, proof)) {
    return false;
  }

  // adds the block to the chain
  block.hash = proof;
  chain.push_back(block);
  last_block = block;

  return true;

}

bool Blockchain::is_valid_proof(Block block, string hash) {
  return startsWith0s(difficulty, hash) && hash == block.compute_hash();
}

// checks if it starts with diff 0s
bool startsWith0s(int diff, string s) {

  for (int i = 0; i < diff; i++) {
    if (s[i] != '0') {
      return false;
    }
  }
  return true;
}

// returns currentTime as a string
string currTime() {
  time_t currentTime = time(NULL);
  string timestamp = "";
  timestamp += currentTime;
  return timestamp;
}
