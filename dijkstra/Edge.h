#include "Point.h"

class Edge {
private:
	int cost;
	Point* from;
	Point* to;

public:
	Edge(int cost, Point* from, Point* to);
	int getCost();
	Point* getFrom();
	Point* getTo();
};
