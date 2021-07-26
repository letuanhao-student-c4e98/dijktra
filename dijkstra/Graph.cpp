#include "Graph.h"

#include <iostream>
using namespace std;

#include <fstream>

#define INF 9999

void Graph::setPoints(int numPoints)
{
	for (int i = 0; i < numPoints; i++)
	{
		Point* point = new Point(i);
		points.push_back(point);
	}
}

void Graph::printPoints()
{
	for (int i = 0; i < points.size(); i++)
		cout << points[i]->getID() << endl;
}

void Graph::addEdge(int cost, Point* from, Point* to)
{
	Edge* edge = new Edge(cost, from, to);
	edges.push_back(edge);
}

void Graph::printEdges()
{
	for (int i = 0; i < edges.size(); i++)
		cout << edges[i]->getCost() << endl;
}

int Graph::getMinDistance(int* dis, bool* visited)
{
	int min = INF, minIndex;
	for (int p = 0; p < points.size(); p++)
		if (!visited[p] && dis[p] <= min)
		{
			min = dis[p];
			minIndex = p;
		}
	return minIndex;
}

Edge* Graph::getEdge(Point* from, Point* to)
{
	for (Edge* edge : edges)
		if ((edge->getFrom() == from) && (edge->getTo() == to))
			return edge;
	return NULL;
}

void Graph::printPath(int parent[], int pointIndex)
{

	if (parent[pointIndex] == -1)
		return;

	printPath(parent, parent[pointIndex]);
	cout << pointIndex << " ";
}

void Graph::printSolution(int from, int to, int dis, int parent[])
{
	cout << "From: " << from << endl;
	cout << "To: " << to << endl;
	cout << "Distance: " << dis << endl;
	cout << "Path: " << from << " ";
	printPath(parent, to);
}

Graph::Graph()
{
}

void Graph::inputFromFile(string file)
{

	std::ifstream stream(file);
	int cost, numPoints;
	stream >> numPoints;

	setPoints(numPoints);

	for (int i = 0; i < numPoints; i++)
		for (int j = 0; j < numPoints; j++)
		{
			stream >> cost;
			
			 if (cost == INF)
				continue;
			
			
			 addEdge(cost, points[i], points[j]);
		}
}

int Graph::shortestPath(Point* from, Point* to)
{

	int numPoints = points.size();
	bool* visited = new bool[numPoints];
	int* dis = new int[numPoints];
	int* parent = new int[numPoints];

	for (int i = 0; i < numPoints; i++)
	{
		parent[i] = -1;
		dis[i] = INF;
		visited[i] = false;
	}

	dis[from->getID()] = 0;

	for (int c = 0; c < numPoints - 1; c++)
	{
		int m = getMinDistance(dis, visited);
		visited[m] = true;
		Point* pointM = getPointByID(m);

		for (int p = 0; p < numPoints; p++)
		{
			Point* pointP = getPointByID(p);
			Edge* edgeMP = getEdge(pointM, pointP);
			if (!visited[p] && edgeMP && dis[m] != INF && (dis[m] + edgeMP->getCost() < dis[p]))
			{
				parent[p] = m;
				dis[p] = dis[m] + edgeMP->getCost();
			}
		}
	}

	printSolution(from->getID(), to->getID(), dis[to->getID()], parent);

	return dis[to->getID()];
}

Point* Graph::getPointByID(int id)
{
	for (Point* point : points)
		if (point->getID() == id)
			return point;

	cout << "[ERROR]: point ID '" << id << "' not found" << endl;

	return NULL;
}
/*

vector<Edge*> Graph::getEdges(Point* point) {
	vector<Edge*> adjEdges;
	for (Edge* edge : edges)
		if (edge->getFrom() == point)
			adjEdges.push_back(edge);
	return adjEdges;
}

*/


