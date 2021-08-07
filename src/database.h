#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

#include "date.h"
#include "node.h"

using namespace std;

class Database {
public:
  void Add(const Date&, const string&);

  set<string> Find(const Date&) const;

  void Print(ostream&) const;

  int FindIf();


  template<typename func>
  int RemoveIf(func);

  void Last(const Date&) const;

private:
  map<Date, set<string>> storage;
};
