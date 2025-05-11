#include <fstream>
#include "FileReaderWriter.hpp"



void ReaderWriter::fileReader(const std::string& fileName, std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>>& data) {
	
	std::ifstream ifs(fileName);

	if (ifs.is_open()) {
		std::string line;
		std::string city1;
		std::string city2;
		std::string pathLength_;

		while (std::getline(ifs, line)) {

			int i{ 0 };
			bool first{ true };
			bool second{ false };
			bool third{ false };
			unsigned int pathLength{ 0 };
			while (i != line.size()) {
				if (first) {
					if (line[i] == ' ') {
						first = false;
						second = true;
					}
					city1 += line[i];
				}
				if (second) {
					if (line[i] == ' ') {
						second = false;
						third = true;
					}
					city2 += line[i];
				}
				if (third) {
					if (line[i + 1] == '\n') {
						third = false;
					}
					pathLength_ += line[i];
				}
				i++;
			}
			pathLength = std::stoul(pathLength_);
			city1.pop_back();
			city2.pop_back();

			data[city1].push_back({ city2, pathLength });

			city1.clear();
			city2.clear();
			pathLength_.clear();
		}

	}
	else {
		throw std::runtime_error("Не удалось открыть файл для чтения");
	}

}

void ReaderWriter::fileWriter(std::vector<std::string>& data) {

}
