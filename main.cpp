#include "blockchain.hh"
#include <iostream>
using namespace std;
void mainPage();
Blockchain bc = Blockchain();
int main() {

  cout << "Blockchain created" << endl;
  mainPage();



}

void mainPage() {
  string input = "";
  while (input != "4") {
    cout << "\n\n\n\n\n";
    if (input == "3") {
      cout << bc.toJson() << endl;
    }
    if (input == "2") {
      cout << "starting mining!" << endl;
      bc.mine();
      cout << "mined"<< endl;
    }
    if (input == "1") {
      string UID1;
      string UID2;
      string timestamp = currTime();
      cout << "What is the first UID" << endl;
      cin >> UID1;
      cout << "What is the second UID" << endl;
      cin >> UID2;
      bc.add_new_transaction(Transaction(UID1, UID2, timestamp));
      cout << "Object created and added to unconfirmed_transactions" << endl;
    }
    cout << "\n\n\n\n\n";
    cout << "Would you like to ..." << endl;
    cout << "1. create a new transaction?" << endl;
    cout << "2. mine the current block?" << endl;
    cout << "3. view the whole chain?" << endl;
    cout << "4. exit" << endl;
    input = "";
    cin >> input;

  }


}
