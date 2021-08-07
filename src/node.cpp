#include "node.h"


bool EmptyNode :: Evaluate(const Date&, const string&){
	return true;
}
bool DateComparisonNode :: Evaluate(const Date& input_d, const string& input_e){
	switch(cmp){
	case Comparison::Less:
		return input_d < date;
	case Comparison::LessOrEqual:
		return input_d <= date;
	case Comparison::Greater:
		return input_d > date;
	case Comparison::GreaterOrEqual:
		return input_d >= date;
	case Comparison::Equal:
		return input_d == date;
	case Comparison::NotEqual:
		return input_d != date;
	}
}
bool EventComparisonNode :: Evaluate(const Date& input_d, const string& input_e){
	switch(cmp){
	case Comparison::Less:
		return input_e < event;
	case Comparison::LessOrEqual:
		return input_e <= event;
	case Comparison::Greater:
		return input_e > event;
	case Comparison::GreaterOrEqual:
		return input_e >= event;
	case Comparison::Equal:
		return input_e == event;
	case Comparison::NotEqual:
		return input_e != event;
	}
}
bool LogicalOperationNode :: Evaluate(const Date& input_d, const string& input_e){
	switch(op){
	case LogicalOperation::And:
		return left->Evaluate(input_d, input_e) && right->Evaluate(input_d, input_e);
		break;
	case LogicalOperation::Or:
		return left->Evaluate(input_d, input_e) || right->Evaluate(input_d, input_e);
	}
}

