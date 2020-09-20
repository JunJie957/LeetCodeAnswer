// ��ϣ�� 
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = { 0,  1,  0,  -1 };
        int dy[4] = { 1,  0, -1,   0 };
        int x = 0, y = 0, direction = 0;

        // ���ϰ��㶼�浽��ϣ���У��ƶ�ʱ���бȶԣ��Ƿ������ϰ���
        unordered_map<int, unordered_set<int>> obs;
        for (auto& iter : obstacles) {
            obs[iter[0]].insert(iter[1]);
        }

        int ans = 0;
        for (auto& cmd : commands) {
            if (cmd == -1) {
                direction = (direction + 1) % 4;    // ������
            } else if (cmd == -2) {
                direction = (direction + 3) % 4;    // ������
            } else {
                for (int i = 0; i < cmd; ++i) { // ÿ��һ������Ҫ�ж��Ƿ������ϰ���
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    auto iter = obs.find(nx);
                    if (iter == obs.end() || iter->second.find(ny) == iter->second.end()) {
                        x = nx, y = ny;
                        ans = max(ans, x * x + y * y);
                    } else {
                    	break; // �����ϰ��������һ������ 
					} 
                }
            }
        }
        return ans;
    }
};
