#include <string>
struct Transaction{
  string author;
  string content;
  string timestamp;

  string toJson() {
    string json = "{"
    json << "'author':'" << author << "',";
    json << "'content':'" << content << "',";
    json << "'timestamp':'" << timestamp << "',";
    json << "}";
    return json;
  }
}
