#include <unordered_map>
#include <vector>
#include <string>


class Dijkstra final{
	std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>>& adjList;
	std::unordered_map<std::string, unsigned int> dist;
	std::unordered_map<std::string, std::string> from;
	std::string start;
	std::string final;
public:
	Dijkstra(std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned int>>>& adjList_, std::string start_,
																									  std::string final_);

	const std::pair<std::vector<std::string>, unsigned int> getPath() const;

private:
	void dijkstra();
};