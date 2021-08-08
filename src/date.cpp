#include "date.h"

#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

  // конструктор выбрасывает исключение, если его аргументы некорректны
  Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
      throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
      throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
  }

  int Date::GetYear() const {
    return year;
  }
  int Date::GetMonth() const {
    return month;
  }
  int Date::GetDay() const {
    return day;
  }

  // определить сравнение для дат необходимо для использования их в качестве ключей словаря
  bool operator<(const Date& lhs, const Date& rhs) {
    // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
    // создадим вектор из года, месяца и дня для каждой даты и сравним их
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
  }

  bool operator>(const Date& lhs, const Date& rhs){
	  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
	  	  vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
  }

  bool operator>=(const Date& lhs, const Date& rhs){
	  return !(lhs<rhs);
  }

  bool operator<=(const Date& lhs, const Date& rhs){
	  return !(lhs>rhs);
  }

  // даты будут по умолчанию выводиться в нужном формате
  ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
        "-" << setw(2) << setfill('0') << date.GetMonth() <<
        "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
  }

  bool operator==(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
			vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
  }

  bool operator!=(const Date& lhs, const Date& rhs){
	  return !(lhs == rhs);
  }

Date ParseDate(istream& is) {
  string date;
  getline(is, date, ' ');
  istringstream date_stream(date);
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  if (!ok) {
    throw logic_error("Wrong date format: " + date);
  }
  return Date(year, month, day);
}
