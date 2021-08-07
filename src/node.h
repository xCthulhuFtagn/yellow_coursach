#pragma once

#include "date.h"

#include <memory>
#include <string>

enum class Comparison{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation{
	And,
	Or
};

class Node{
public:
	virtual bool Evaluate(const Date&, const string&) = 0;
};
class EmptyNode : public Node{
public:
	EmptyNode(){}
	bool Evaluate(const Date&, const string&) override;
};
class DateComparisonNode : public Node{
public:
	DateComparisonNode(const Comparison& c, const Date& d) : cmp(c), date(d){}//добавь
	bool Evaluate(const Date&, const string&) override;
private:
	const Comparison cmp;
	const Date date;
};
class EventComparisonNode : public Node{
public:
	EventComparisonNode(const Comparison& c, const string& e) : cmp(c), event(e){}//добавь
	bool Evaluate(const Date&, const string&) override;
private:
	const Comparison cmp;
	const string event;
};
class LogicalOperationNode : public Node{
public:
	LogicalOperationNode(const LogicalOperation& lg, shared_ptr<Node> l, shared_ptr<Node> r) : op(lg), left(l), right(r){}//добавь
	bool Evaluate(const Date&, const string&) override;
private:
	const LogicalOperation op;
	const shared_ptr<Node> left, right;
};
