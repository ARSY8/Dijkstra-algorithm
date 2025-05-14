#include <fstream>
#include <sstream>
#include "FileReaderWriter.hpp"



void ReaderWriter::fileReader(const string& fileName, unordered_map<string, vector<pair<string, unsigned int>>>& data) {

	std::ifstream ifs(fileName);

	if (ifs.is_open()) {
		string line;

		while (std::getline(ifs, line)) {

			std::istringstream iss(line);

			string city1, city2;
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

void ReaderWriter::fileWriter(unordered_map<string, unsigned int>& data) {
	std::ofstream ofs("roads.txt");

	if (ofs.is_open()) {
		for (auto& [city, weight] : data) {
			ofs << city << ' ' << weight << '\n';
		}
		ofs.close();
	}
	else {
		throw std::runtime_error("Не удалось открыть файл для записи");
	}

}
