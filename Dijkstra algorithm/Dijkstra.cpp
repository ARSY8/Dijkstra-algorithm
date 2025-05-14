#include <set>
#include <limits>
#include "Dijkstra.hpp"


using std::set;

Dijkstra::Dijkstra(unordered_map<string, vector<pair<string, unsigned int>>>& adjList_, string start_) : adjList(adjList_){
	start = start_;
	dijkstra();
}

unordered_map<string, unsigned int> Dijkstra::getPath() {
	return dist;
}

void Dijkstra::dijkstra() {
	for (const auto& v : adjList) {
		dist[v.first] = std::numeric_limits<unsigned int>::max();
	}
	dist[start] = 0;

	set<pair<unsigned int, string>> unvisitedVertices;
	unvisitedVertices.insert({ dist[start], start });

	while (!unvisitedVertices.empty()) {
		string nearest = unvisitedVertices.begin()->second;
		unvisitedVertices.erase(unvisitedVertices.begin());

		for (auto& [to, weight] : adjList[nearest]) {
			if (dist[to] > dist[nearest] + weight) {
				unvisitedVertices.erase({ dist[to], to });
				dist[to] = dist[nearest] + weight;
				unvisitedVertices.insert({ dist[to], to });
			}
		}
	}
}


