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

string hexToString(string s) {
  using namespace std;
  std::stringstream out;
  for (int i = 0; i != (signed int)s.length(); i++) {
    int curr = ((int) s[i]) + 128;
    if ((curr / 16) < 10) {
      out << curr / 16;
    }
    else {
      out << (char) ('A' + curr / 16 - 10);
    }
    if (curr % 16 < 10) {
      out << curr / 16;
    }
    else {
      out << (char) ('A' + curr % 16 - 10);
    }

  }
  return out.str();

}

// converts all the data into a json string

string Block::toJson() {
    string json = "{";
    std::stringstream indexStr;
    indexStr << index;

    std::stringstream nonceStr;
    nonceStr << nonce;

    json += "\"index\":" + indexStr.str() + ",";
    json += "\"transactions\":[";
    for (Transaction transaction : transactions) {
        json += transaction.toJson() + ",";
    }
    if (!transactions.empty()) {
      json.pop_back();
    }

    json += "],";
    json += "\"timestamp\":\"" + timestamp + "\",";
    json += "\"previous_hash\":\"" + hexToString(previous_hash) + "\",";
    json += "\"nonce\":" + nonceStr.str();
    json += "}";
    return json;
}
