#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>>graph[20001];
int cost[20001];

void dijkstra(int st)
{
	priority_queue<pair<int, int>>pq;
	pq.push({ 0, st });
	cost[st] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first; // 우선순위큐: 내림차순 정렬
		int now = pq.top().second;
		pq.pop();

		if (cost[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cal = dist + graph[now][i].second;
			int targetNode = graph[now][i].first;

			if (cal < cost[targetNode])
			{
				cost[targetNode] = cal;
				pq.push(make_pair(-cal, targetNode));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}

	fill(cost, cost + 20001, 1e9);

	// dijkstra algorithm
	dijkstra(K);

	// output
	for (int i = 1; i <= V; i++)
	{
		if (cost[i] == 1e9)
		{
			cout << "INF\n";
		}
		else
		{
			cout << cost[i] << "\n";
		}
	}

	return 0;
}