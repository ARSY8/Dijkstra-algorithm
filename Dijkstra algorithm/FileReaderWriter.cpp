#include <fstream>
#include <sstream>
#include "FileReaderWriter.hpp"

using std::unordered_map;
using std::vector;
using std::string;
using std::pair;

unordered_map<string, vector<pair<string, unsigned int>>> ReaderWriter::fileReader(const string& fileName) {
	
	unordered_map<string, vector<pair<string, unsigned int>>> data;

	std::ifstream ifs(fileName);

	if (!ifs.is_open()) {
		throw std::runtime_error("Не удалось открыть файл для чтения");
	}
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
	return data;
}

void ReaderWriter::fileWriter(const std::pair<std::vector<std::string>, unsigned int>& data, std::ofstream& ofs) {

	if (!ofs.is_open()) {
		throw std::runtime_error("Не удалось открыть файл для записи");
	}

	for(const auto& city : data.first){
		ofs << city << ' ';
	}
	ofs << data.second;

	ofs.close();

}