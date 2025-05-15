#include <gtest/gtest.h>
#include "Dijkstra.hpp"
#include <unordered_map>
#include <vector>
#include <string>


using std::unordered_map;
using std::vector;
using std::string;
using std::pair;

TEST(DijkstraTest, ShortestPathFromMoscow) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>> graph;

    graph["Moscow"].push_back({"Novosibirsk", 7});
    graph["Novosibirsk"].push_back({"Moscow", 7});
    graph["Moscow"].push_back({"Toronto", 9});
    graph["Toronto"].push_back({"Moscow", 9});
    graph["Moscow"].push_back({"Krasnoyarsk", 14});
    graph["Krasnoyarsk"].push_back({"Moscow", 14});
    graph["Novosibirsk"].push_back({"Toronto", 10});
    graph["Toronto"].push_back({"Novosibirsk", 10});
    graph["Novosibirsk"].push_back({"Omsk", 15});
    graph["Omsk"].push_back({"Novosibirsk", 15});
    graph["Omsk"].push_back({"Toronto", 11});
    graph["Toronto"].push_back({"Omsk", 11});
    graph["Toronto"].push_back({"Krasnoyarsk", 2});
    graph["Krasnoyarsk"].push_back({"Toronto", 2});
    graph["Krasnoyarsk"].push_back({"Kiev", 9});
    graph["Kiev"].push_back({"Krasnoyarsk", 9});
    graph["Kiev"].push_back({"Omsk", 6});
    graph["Omsk"].push_back({"Kiev", 6});

    Dijkstra dijkstra(graph, "Moscow", "Kiev");

    auto pathResult = dijkstra.getPath();
    auto& road = pathResult.first;
    auto totalDistance = pathResult.second;

    EXPECT_EQ(totalDistance, 20);

    EXPECT_EQ(road.size(), 4);
    EXPECT_EQ(road[0], "Moscow");
    EXPECT_EQ(road[1], "Toronto");
    EXPECT_EQ(road[2], "Krasnoyarsk");
    EXPECT_EQ(road[3], "Kiev");
}

TEST(DijkstraTest, ShortestPathFromToronto) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>> graph;

    graph["Moscow"].push_back({"Novosibirsk", 7});
    graph["Novosibirsk"].push_back({"Moscow", 7});
    graph["Moscow"].push_back({"Toronto", 9});
    graph["Toronto"].push_back({"Moscow", 9});
    graph["Moscow"].push_back({"Krasnoyarsk", 14});
    graph["Krasnoyarsk"].push_back({"Moscow", 14});
    graph["Novosibirsk"].push_back({"Toronto", 10});
    graph["Toronto"].push_back({"Novosibirsk", 10});
    graph["Novosibirsk"].push_back({"Omsk", 15});
    graph["Omsk"].push_back({"Novosibirsk", 15});
    graph["Omsk"].push_back({"Toronto", 11});
    graph["Toronto"].push_back({"Omsk", 11});
    graph["Toronto"].push_back({"Krasnoyarsk", 2});
    graph["Krasnoyarsk"].push_back({"Toronto", 2});
    graph["Krasnoyarsk"].push_back({"Kiev", 9});
    graph["Kiev"].push_back({"Krasnoyarsk", 9});
    graph["Kiev"].push_back({"Omsk", 6});
    graph["Omsk"].push_back({"Kiev", 6});

    Dijkstra dijkstra(graph, "Toronto", "Kiev");

    auto pathResult = dijkstra.getPath();
    auto& road = pathResult.first;
    auto totalDistance = pathResult.second;

    EXPECT_EQ(totalDistance, 11);

    EXPECT_EQ(road.size(), 3);
    EXPECT_EQ(road[0], "Toronto");
    EXPECT_EQ(road[1], "Krasnoyarsk");
    EXPECT_EQ(road[2], "Kiev");
}