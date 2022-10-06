#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <limits.h>
#include<time.h>

class scopeTimer
{
	time_t start, end;
	std::string  showMessage;
public: static std::string  m_Message;
public:
	scopeTimer(const char* message)
	{
		start = time(NULL); // 시간 측정 시작
		showMessage = message;
	}

	~scopeTimer()
	{
		end = time(NULL); // 시간 측정 
		m_Message += (showMessage + " : " + std::to_string((double)(end - start)) +'\n');
	}

	static void Show()
	{
		std::cout << m_Message << std::endl;
	}
};

std::string scopeTimer::m_Message = std::string();



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
	//scopeTimer time("CheckResultCost");
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

			if (targetIndex <= -1)
			{
				resultValue = -1;
				break;
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
	{
		for (size_t i = 0; i < edgeCount; ++i)
		{
			int vertex1, vertex2, cost;
			std::cin >> vertex1 >> vertex2 >> cost;

			int index1 = vertex1 - 1;
			int index2 = vertex2 - 1;

			vertexs[index1].AddConnectVertex(index2, cost);
			vertexs[index2].AddConnectVertex(index1, cost);
		}
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
