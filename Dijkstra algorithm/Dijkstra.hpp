#include <unordered_map>
#include <vector>
#include <string>


using std::unordered_map;
using std::vector;
using std::string;
using std::pair;

class Dijkstra {
	unordered_map<string, vector<pair<string, unsigned int>>>& adjList;
	unordered_map<string, unsigned int> dist;
	string start;

public:
	Dijkstra(unordered_map<string, vector<pair<string, unsigned int>>>& adjList_, string start_);

	unordered_map<string, unsigned int> getPath();

private:
	void dijkstra();
};

