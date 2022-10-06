#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#include <string>
#include <queue>
#include <limits.h>



struct Vertex
{
	std::unordered_map<int, int> connectedVertexs;
	std::vector<int> resultArray;

	void AddConnectVertex(const int vertexIdx, const int cost)
	{
		connectedVertexs.insert(std::pair<int, int>(vertexIdx, cost));
	}

	void findRoad(std::vector<int>& resultArray, const int idx) const
	{
		const int myCost = resultArray[idx];

		std::unordered_map<int, int>::const_iterator iter = connectedVertexs.begin();
		std::unordered_map<int, int>::const_iterator itEnd = connectedVertexs.end();
		for (; iter != itEnd; ++iter)
		{
			const int arrayIndex = iter->first;
			int temp = resultArray[arrayIndex];
			if (temp < 0)
			{
				resultArray[arrayIndex] = myCost + iter->second;
			}
			else
			{
				int& target = resultArray[arrayIndex];
				temp = myCost + iter->second;
				if (temp < target)
				{
					target = temp;
				}
			}
		}
	}
};



int CheckResultCost(const Vertex* vertexs, const int vertexCount, std::queue<int>& stepList)
{
	std::vector<int> resultArray;
	std::unordered_set<int> queue;

	resultArray.resize(vertexCount, -1);

	int resultValue = 0;

	while (true)
	{
		const size_t startIdx = stepList.front() - 1;
		stepList.pop();

		if (true == stepList.empty())
		{
			break;
		}

		std::fill(resultArray.begin(), resultArray.end(), -1);
		for (size_t i = 0; i < vertexCount; ++i)
		{
			queue.insert(i);
		}
		resultArray[startIdx] = 0;


		while (false == queue.empty())
		{
			int targetIndex = -1;
			int min = INT_MAX;

			std::unordered_set<int>::iterator iter = queue.begin();
			for (; iter != queue.end(); ++iter)
			{
				int tempIdx = *iter;
				if (resultArray[tempIdx] < 0)
				{
					continue;
				}

				if (min <= resultArray[tempIdx])
				{
					continue;
				}

				min = resultArray[tempIdx];
				targetIndex = tempIdx;
			}

			vertexs[targetIndex].findRoad(resultArray, targetIndex);
			queue.erase(targetIndex);
		}

		const size_t endIdx = stepList.front() - 1;

		if (resultArray[endIdx] < 0)
		{
			resultValue = -1;
			break;
		}

		resultValue += resultArray[endIdx];
	}

	return resultValue;
}

int main()
{

	std::queue<int> stepList;
	int resultValue = 0;

	size_t vertexCount = 0;
	size_t edgeCount = 0;
	std::cin >> vertexCount >> edgeCount;

	Vertex* vertexs = new Vertex[vertexCount];

	for (size_t i = 0; i < edgeCount; ++i)
	{
		int vertex1, vertex2, cost;
		std::cin >> vertex1 >> vertex2 >> cost;

		vertexs[vertex1 - 1].AddConnectVertex(vertex2 - 1, cost);
		vertexs[vertex2 - 1].AddConnectVertex(vertex1 - 1, cost);
	}

	size_t step1, step2;
	std::cin >> step1;
	std::cin >> step2;
	stepList.push(1);
	stepList.push(step1);
	stepList.push(step2);
	stepList.push(vertexCount);
	int result1 = CheckResultCost(vertexs, vertexCount, stepList);

	stepList.push(1);
	stepList.push(step2);
	stepList.push(step1);
	stepList.push(vertexCount);
	int result2 = CheckResultCost(vertexs, vertexCount, stepList);

	resultValue = result1 < result2 ? result1 : result2;
	std::cout << resultValue << std::endl;

	if (vertexs)
	{
		delete[] vertexs;
		vertexs = nullptr;
	}
}
