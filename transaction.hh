#ifndef TransactionHeader
#define TransactionHeader
#include <string>

class Transaction{
public:
  std::string UID1;
  std::string UID2;
  std::string timestamp;

  Transaction(std::string a, std::string c, std::string t) {
    UID1 = a;
    UID2 = c;
    timestamp = t;
  }

  std::string toJson() {
    std::string json = "{";
    json += "\"UID1\":\"" + UID1 + "\",";
    json += "\"UID2\":\"" + UID2 + "\",";
    json += "\"timestamp\":\"" + timestamp + "\"";
    json += "}";
    return json;
  }
};
#endif
