#include "Edge.h"

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
	vector<Point*> points; // All points of this Graph.
	vector<Edge*> edges;	// All edges of this Graph.

	/* Set the point list of this Graph.
	* @param     numPoints     Number of points.
	*/
	void setPoints(int numPoints);

	// Print all points of this Graph.
	void printPoints();

	/* Add new edge to this Graph's edge list.
	* @param     cost      Edge cost.
	* @param     from     Starting point.
	* @param     to         Target point.
	*/
	void addEdge(int cost, Point* from, Point* to);

	// Print all edges of this Graph.
	void printEdges();

	/* Find the point with minimum distance from the set of points not yet included in the shortest path tree.
	* @param     dis           Distance list.
	* @param     visited     Visit status manifest.
	*/
	int getMinDistance(int* dis, bool* visited);

	/* Get edge between 2 points.
	* @param     from     Starting point.
	* @param     to         Target point.@param     from
	* @return                 Pointer to the edge.
	*/
	Edge* getEdge(Point* from, Point* to);

	/* Print path.
	* @param     parent     parent[i] stores parent point of point "i" in the shortest path.
	* @param     target      Index of target point.
	*/
	void printPath(int parent[], int target);

	/* Print solution.
	* @param     from     Starting point.
	* @param     to         Target point.
	* @param     dis        Distance.
	* @param     parent   parent[i] stores parent point of point "i" in the shortest path.
	*/
	void printSolution(int from, int to, int dist, int parent[]);

	/* Get adjacency edges which start from the specified point.
	* @param     point     The specified point.
	* @return                 The adjacency edges list.
	*/
	vector<Edge*> getEdges(Point* point);

public:
	// Constructor.
	Graph();

	/* Import Graph from .txt file which contains Adjacency Matrix representation of the Graph.
	* @param     file     File name.
	*/
	void inputFromFile(string file);

	/* Find the shortest path.
	* @param     from     Starting point.
	* @param     to         Target point.
	* @return                 Shortest path's distance.
	*/
	int shortestPath(Point* from, Point* to);

	/* Get point by its ID.
	* @param     id     Point ID.
	* @return            Pointer to the point.
	*/
	Point* getPointByID(int id);
};

