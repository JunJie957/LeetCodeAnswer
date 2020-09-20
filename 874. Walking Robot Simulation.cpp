// 哈希表 
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = { 0,  1,  0,  -1 };
        int dy[4] = { 1,  0, -1,   0 };
        int x = 0, y = 0, direction = 0;

        // 将障碍点都存到哈希表中，移动时进行比对，是否碰到障碍物
        unordered_map<int, unordered_set<int>> obs;
        for (auto& iter : obstacles) {
            obs[iter[0]].insert(iter[1]);
        }

        int ans = 0;
        for (auto& cmd : commands) {
            if (cmd == -1) {
                direction = (direction + 1) % 4;    // 向右走
            } else if (cmd == -2) {
                direction = (direction + 3) % 4;    // 向左走
            } else {
                for (int i = 0; i < cmd; ++i) { // 每走一步，都要判断是否碰到障碍物
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    auto iter = obs.find(nx);
                    if (iter == obs.end() || iter->second.find(ny) == iter->second.end()) {
                        x = nx, y = ny;
                        ans = max(ans, x * x + y * y);
                    } else {
                    	break; // 遇到障碍物，继续下一个命令 
					} 
                }
            }
        }
        return ans;
    }
};
