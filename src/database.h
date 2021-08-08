#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <functional>



#include "date.h"
#include "node.h"

using namespace std;

class Database {
public:
  void Add(const Date&, const string&);

  void Print(ostream&) const;

  //template<typename func>
  set<string> FindIf(std::function<bool(const Date&, const string&)>&) const;

  template<typename func>
  int RemoveIf(func&);

  stringstream Last(const Date&) const;

private:
  map<Date, vector<string>> storage1;
  map<Date, set<string>> storage2;
};
