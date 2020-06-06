#ifndef TransactionHeader
#define TransactionHeader
#include <string>

struct Transaction{
  std::string author;
  std::string content;
  std::string timestamp;

  std::string toJson() {
    std::string json = "{";
    json += "'author':'" + author + "',";
    json += "'content':'" + content + "',";
    json += "'timestamp':'" + timestamp + "',";
    json += "}";
    return json;
  }
};
#endif
