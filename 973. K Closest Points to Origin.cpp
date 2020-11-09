// 方法1：优先队列 O(nlogK) 
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		priority_queue<pair<double, int>> q;
		for (int i = 0; i < K; ++i) {
			q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
		}

		for (int i = K; i < points.size(); ++i) {
			double dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
			if (q.top().first > dis) {
				q.pop();
				q.emplace(dis, i);
			}
		}
		vector<vector<int>> res;
		while (!q.empty()) {
			res.emplace_back(points[q.top().second]);
			q.pop();
		}
		return res;
	}
};


// 方法2：STL 中的 nth_element() 函数
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		nth_element(points.begin(), points.begin() + K, points.end(), [](auto&& l, auto&& r) {return l[0] * l[0] + l[1] * l[1] < r[0] * r[0] + r[1] * r[1]; });
		points.resize(K);
		return points;
	}
}; 
