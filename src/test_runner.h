#pragma once

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const set<T>& s);

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);

inline void Assert(bool b, const string& hint);

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
	  func();
	  cerr << test_name << " OK" << endl;
	} catch (runtime_error& e) {
	  ++fail_count;
	  cerr << test_name << " fail: " << e.what() << endl;
	}
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};
