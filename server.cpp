#include <iostream>
#include <vector>
#include "blockchain.hh"
#include "httplib.h"
#include <Windows.h>
#include <math.h>
using namespace std;



struct location {
  string UID;
  double lat;
  double lng;

  location() {}
};

double distance(double lat1, double lng1, double lat2, double lng2);
void checkInteractions();

Blockchain bc = Blockchain();
vector<location> vec;

int main() {

  httplib::Server svr;

  cout << "listening" << endl;

  svr.Get("/blockchain", [](const httplib::Request& req, httplib::Response& res) {
    res.set_content(bc.toJson(), "application/json");
  });

  svr.Post("/infected", [](const httplib::Request& req, httplib::Response& res) {

  });

  svr.Post("/location", [](const httplib::Request& req, httplib::Response& res) {
    if (req.has_param("UID") && req.has_param("lat") && req.has_param("lng")) {
      location l;
      l.UID = req.get_param_value("UID");
      l.lat = atof(req.get_param_value("lat").c_str());
      l.lng = atof(req.get_param_value("lng").c_str());
      vec.push_back(l);
    }
  });
  svr.listen("localhost", 1234);

  return 0;
}

void checkInteractions() {

  for (unsigned int i = 0; i < vec.size(); i++) {
    location l = vec[i];
    for (unsigned int j = i + 1; j < vec.size(); j++) {
      location l2 = vec[j];
      if (l.UID != l2.UID) {
        if (distance(l.lat, l.lng, l2.lat, l2.lng) <= 1.8) {
          bc.add_new_transaction(Transaction(l.UID, l2.UID, currTime()));
          vec.erase(vec.begin() + i);
          vec.erase(vec.begin() + j);
          i--;
          break;
        }
      }
    }
  }


}

double distance(double lat1, double lng1, double lat2, double lng2) {
    double latDistanceScale = 110574;
    double lngDistanceScale = 111320;
    double degToRad = acos(-1) / 180;
    double latRadians = degToRad * lat1;
    double latDistance = latDistanceScale * (lat1 - lat2);
    double lngDistance = lngDistanceScale * (lng1 - lng2) * cos(latRadians);
    return sqrt(latDistance * latDistance + lngDistance * lngDistance);
}
