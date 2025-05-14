#include <iostream>
#include "Dijkstra.hpp"
#include "FileReaderWriter.hpp"

int main() {
    std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>> graph;

    try {
        ReaderWriter::fileReader("graph.txt", graph);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при чтении файла: " << e.what() << std::endl;
        return 1;
    }

    std::string startCity = "Moscow";

    Dijkstra d(graph, startCity);
    auto distances = d.getPath();

    try {
        ReaderWriter::fileWriter(distances);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при записи в файл: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Готово. Длины кратчайших путей сохранены в файл roads.txt.\n";
    return 0;
}