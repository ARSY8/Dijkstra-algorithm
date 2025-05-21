#include <string>
#include <vector>
#include <unordered_map>
#include <utility>


class ReaderWriter final{
	ReaderWriter() = delete;
	~ReaderWriter() = delete;
public:
	static std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>> fileReader (const std::string& fileName);
	static void fileWriter(const std::pair<std::vector<std::string>, unsigned int>& data, std::ofstream& ofs);
};
