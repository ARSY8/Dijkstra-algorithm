#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include "Dijkstra.hpp"
#include "FileReaderWriter.hpp"

namespace fs = std::filesystem;

class DijkstraTest : public ::testing::Test {
protected:
    std::string inputFile = "test_graph.txt";
    std::string outputFile = "test_output.txt";

    void SetUp() override {
        std::ofstream ofs(inputFile);
        ofs << "Moscow Novosibirsk 7\n";
        ofs << "Moscow Toronto 9\n";
        ofs << "Moscow Krasnoyarsk 14\n";
        ofs << "Novosibirsk Toronto 10\n";
        ofs << "Novosibirsk Omsk 15\n";
        ofs << "Omsk Toronto 11\n";
        ofs << "Toronto Krasnoyarsk 2\n";
        ofs << "Krasnoyarsk Kiev 9\n";
        ofs << "Kiev Omsk 6\n";
        ofs.close();
    }

    void TearDown() override {
        fs::remove(inputFile);
        fs::remove(outputFile);
    }

    std::vector<std::string> readFileLines(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }
};

TEST_F(DijkstraTest, ShortestPathFromMoscowToKiev) {

    auto graph = ReaderWriter::fileReader(inputFile);
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

TEST_F(DijkstraTest, ShortestPathFromTorontoToKiev) {
    auto graph = ReaderWriter::fileReader(inputFile);
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

TEST_F(DijkstraTest, NoPathFromMoscowToLondon) {

    auto graph = ReaderWriter::fileReader(inputFile);

    EXPECT_ANY_THROW(Dijkstra dijkstra(graph, "Moscow", "London"));
}

TEST_F(DijkstraTest, NoPathDueToDisconnectedGraph) {

    std::ofstream ofs(inputFile);
    ofs << "Moscow Novosibirsk 7\n";
    ofs << "London Minsk 9\n";
    ofs << "Moscow Toronto 9\n";
    ofs << "Toronto Krasnoyarsk 2\n";
    ofs << "Krasnoyarsk Omsk 15\n";
    ofs.close();

    auto graph = ReaderWriter::fileReader(inputFile);
    Dijkstra dijkstra(graph, "London", "Novosibirsk");

    EXPECT_ANY_THROW(dijkstra.getPath());
}
