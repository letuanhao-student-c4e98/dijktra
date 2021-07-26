#include "Edge.h"

Edge::Edge(int cost, Point* from, Point* to) {
	this->cost = cost;
	this->from = from;
	this->to = to;
}

int Edge::getCost() {
	return cost;
}

Point* Edge::getFrom() {
	return from;
}

Point* Edge::getTo() {
	return to;
}

