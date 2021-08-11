#include "database.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

//добавь нормальную обработку для set и string

void Database::Add(const Date& date, const string& event) {
	if(storage.count(date)==0 && find(storage.at(date).begin(), storage.at(date).end(), event) == storage.at(date).end()){
		storage[date].push_back(event);
	}
}

template<typename func>
set<string> Database::FindIf(func predicate) const{
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
		auto new_end = remove_if(el.second.begin(), el.second.end(), [&predicate, &el](const Date& input){
			return predicate(el.first, el.second);
		});
		num += el.second.end() - new_end;
		el.second.erase(new_end, el.second.end());
	}
	return num;
}

string Database::Last(const Date& date) const{
	stringstream stream;
	auto begin = storage.begin();
	auto it = lower_bound(begin, storage.end(), [](auto left, Date right){
		left.first < right;
	});
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
	return stream.str();
}


