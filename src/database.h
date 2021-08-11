#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
//#include <functional>



#include "date.h"
#include "node.h"

using namespace std;

class Database {
public:
  void Add(const Date&, const string&);

  void Print(ostream&) const;

  template<typename func>
  set<string> FindIf(func) const;

  template<typename func>
  int RemoveIf(func&);

  string Last(const Date&) const;

private:
  map<Date, vector<string>> storage;
  //map<Date, set<string>> storage2;
};
