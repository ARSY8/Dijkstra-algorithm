#include <string>
#include <vector>
#include <unordered_map>


class ReaderWriter {
	ReaderWriter() = delete;
	~ReaderWriter() = delete;
public:
	static void fileReader(const std::string& fileName, std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>>& data);
	static void fileWriter(std::vector<std::string>& data);
};