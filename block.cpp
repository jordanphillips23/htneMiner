#include "block.hh"

Block::Block(int index, std::vector<Transaction> transactions, string timestamp, string previous_hash, int nonce)) {
  this->index = index;
  this->transactions = transactions;
  this->timestamp = timestamp;
  this->previous_hash = previous_hash;
  this->nonce = nonce;
}

string Block::compute_hash() {
  SHA3_256 currHash;
  string msg = toJson();
  string digest;

  currHash.Update((const byte*)msg.data(), msg.size());
  digest.resize(hash.DigestSize());
  currHash.Final((byte*)&digest[0]);

  hash = digest;
  
  return digest;
}

string Block::toJson() {
    string json = "{";
    json << "'index':" << index << ",";
    json << "'transactions':["
    for (Transaction transaction in transactions) {
        json << transaction.toJson() << ","
    }
    json << "],";
    json << "'timestamp':'" << timestamp << "',";
    json << "'previous_hash':'" << previous_hash << "',";
    json << "'nonce':" << nonce << ',';
    json << "}";
    return json;
}
