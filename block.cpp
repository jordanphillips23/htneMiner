#include "block.hh"

Block::Block(int index, std::vector<Transaction> transactions, string timestamp, string previous_hash, int nonce) {
  this->index = index;
  this->transactions = transactions;
  this->timestamp = timestamp;
  this->previous_hash = previous_hash;
  this->nonce = nonce;
}

string Block::compute_hash() {
  // creates the Hasher
  CryptoPP::SHA3_256 currHash;

  // stores the json as a string
  string msg = toJson();
  string digest;

  // prepares the hasher
  currHash.Update((const CryptoPP::byte*)msg.data(), msg.size());

  // resizes the output to fit the hash
  digest.resize(currHash.DigestSize());

  // stores the resulting hash into digest
  currHash.Final((CryptoPP::byte*)&digest[0]);

  return digest;
}

// converts all the data into a json string

string Block::toJson() {
    string json = "{";
    std::stringstream indexStr;
    indexStr << index;

    json += "'index':" + indexStr.str() + ",";
    json += "'transactions':[";
    for (Transaction transaction : transactions) {
        json += transaction.toJson() + ",";
    }
    json += "],";
    json += "'timestamp':'" + timestamp + "',";
    json += "'previous_hash':'" + previous_hash + "',";
    json += "'nonce':" + nonce + ',';
    json += "}";
    return json;
}
