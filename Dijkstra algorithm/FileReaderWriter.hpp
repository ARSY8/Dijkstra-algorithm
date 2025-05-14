#include <string>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::string;
using std::pair;

class ReaderWriter {
	ReaderWriter() = delete;
	~ReaderWriter() = delete;
public:
	static void fileReader(const string& fileName, unordered_map<string, vector<pair<string, unsigned int>>>& data);
	static void fileWriter(unordered_map<string, unsigned int>& data);
};