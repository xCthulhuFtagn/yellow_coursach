#include "database.h"

#include <algorithm>

using namespace std;

void Database::Add(const Date& date, const string& event) {
	storage[date].insert(event);
}

set<string> Database::Find(const Date& date) const {
	if (storage.count(date) > 0) {
	  return storage.at(date);
	} else {
	  return {};
	}
}

void Database::Print(ostream& os) const {
	for (const auto& item : storage) {
	  for (const string& event : item.second) {
		os << item.first << " " << event << endl;
	  }
	}
}

template<typename func>
int Database::RemoveIf(func predicate){
	if(predicate){

	}
}
/*

void Database::Last(const Date& date) const{
	auto begin = storage.begin();
	auto it = lower_bound(begin, storage.end(), date);
	if(it != begin){
		--it;
		cout << it->first << " ";
		for(const auto& el : it->second){
			cout << el << " ";
		}
		cout << endl;
	} else{
		cout << "No entries" <<endl;
	}
}
*/

