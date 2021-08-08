#include "database.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

//добавь нормальную обработку для set и string

void Database::Add(const Date& date, const string& event) {
	if(storage2.at(date))
	storage1[date].push_back(event);
}

//template<typename func>
set<string> Database::FindIf(std::function<bool(const Date&, const string&)>& predicate) const{
	set<string> out;
	for(auto& el : storage){
		for(auto& vec_el : el.second){
			if(predicate(el.first, vec_el)) out.insert(vec_el);
		}
	}
	return out;
}

void Database::Print(ostream& os) const {
	for (const auto& item : storage) {
	  for (const string& event : item.second) {
		os << item.first << " " << event << endl;
	  }
	}
}

template<typename func>
int Database::RemoveIf(func& predicate){
	int num = 0;
	for(auto& el : storage){
		remove_if(el.second.begin(), el.second.end(), [&predicate, &el, &num](const Date& input){
			return predicate(el.first, el.second);
			++num;
		});

	}
	return num;
}

stringstream Database::Last(const Date& date) const{
	stringstream stream;
	auto begin = storage.begin();
	auto it = lower_bound(begin, storage.end(), date);
	if(it != begin){
		--it;
		stream << it->first << " ";
		for(const auto& el : it->second){
			stream << el << " ";
		}
		stream << endl;
	} else{
		throw invalid_argument("");
	}
	return stream;
}


