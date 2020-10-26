bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), cmp);
        if (clips[0][0] > 0 || clips.back()[1] < T) return -1;
        int begin = 0, count = 0, loc = 0, max_loc = begin;
        while (begin < T) {
            while (loc < clips.size() && begin >= clips[loc][0]) {
                max_loc = max(max_loc,clips[loc++][1]);
            }
            if(max_loc == begin) return -1;
            ++count;
            begin = max_loc;
        }
        return count;
    }
};
