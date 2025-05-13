#include <fstream>
#include <sstream>
#include "FileReaderWriter.hpp"



void ReaderWriter::fileReader(const std::string& fileName, std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>>& data) {

	std::ifstream ifs(fileName);

	if (ifs.is_open()) {
		std::string line;

		while (std::getline(ifs, line)) {

			std::istringstream iss(line);

			std::string city1, city2;
			unsigned int weight;

			if (!(iss >> city1 >> city2 >> weight)) {
				throw std::runtime_error("Ошибка чтения строки");
			}

			data[city1].push_back({ city2, weight });
			data[city2].push_back({ city1, weight });
		}
		ifs.close();
	}
	else {
		throw std::runtime_error("Не удалось открыть файл для чтения");
	}
}

void ReaderWriter::fileWriter(std::vector<std::string>& data) {

}
