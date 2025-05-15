#include <set>
#include <limits>
#include <utility>
#include <numeric>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "Dijkstra.hpp"


using std::set;
using std::unordered_map;
using std::vector;
using std::string;
using std::pair;

Dijkstra::Dijkstra(unordered_map<string, vector<pair<string, unsigned int>>>& adjList_, string start_,
																						string final_) : adjList(adjList_){
	start = start_;
	final = final_;
	dijkstra();
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
				from[to] = nearest;
				unvisitedVertices.insert({ dist[to], to });
			}
		}
	}
}

const pair<vector<string>, unsigned int> Dijkstra::getPath() const{
	vector<string> road;
	unsigned int totalDist = dist.at(final);

	if (totalDist == std::numeric_limits<unsigned int>::max()) {
		std::cout << "Пути нет" << std::endl;
	}

	for (string at = final; at != ""; at = from.at(at)) {
		road.push_back(at);
	}
	std::reverse(road.begin(), road.end());

	return { road, totalDist };
}