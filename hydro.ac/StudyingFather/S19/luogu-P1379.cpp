#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

class State {
private:
    int matrix[3][3] = {{0}};

    // 获取空白格的位置
    pair<int, int> getZeroPos() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] == 0) {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1); // 错误情况
    }
    
    
public:
    State() = default;

    State(int in[3][3]) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                matrix[i][j] = in[i][j];
            }
        }
    }
    
    /**
     * A* 算法 f(x) = g(x) + h(x)
     * 中的启发函数 h(x)
     * @brief 计算当前状态与目标状态的差异位置数作为h(x)
     * 
     * @param target 目标状态
     * @return int
     */
    int h(const State &target) const {
        int cnt = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(matrix[i][j] != target.matrix[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    // 实现比较运算符，以便State可以被放入set中
    bool operator<(const State &other) const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    return matrix[i][j] < other.matrix[i][j];
                }
            }
        }
        return false;
    }
    
    bool operator==(const State &other) const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // 生成所有可能的下一步状态
    vector<State> next() const { 
        vector<State> next_states;
        pair<int, int> zero_pos = getZeroPos();
        int x = zero_pos.first;
        int y = zero_pos.second;
        
        // 四个方向移动: 上, 下, 左, 右
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 检查边界
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                // 创建新状态
                int new_matrix[3][3];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        new_matrix[j][k] = matrix[j][k];
                    }
                }
                
                // 交换0和相邻数字
                swap(new_matrix[x][y], new_matrix[nx][ny]);
                next_states.push_back(State(new_matrix));
            }
        }
        
        return next_states;
    }
};

int mt[3][3] = { {1, 2, 3}, {8, 0, 4}, {7, 6, 5} };
const State TARGET(mt);

class Node {
    State state;
    int g;

public:
    Node(State s, int g) {
        state = s;
        this->g = g;
    }
    
    bool operator<(const Node &other) const {
        return g + state.h(TARGET) > other.g + other.state.h(TARGET);
    }
    
    State getState() const {
        return state;
    }
    
    int getG() const {
        return g;
    }
};

int main (int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }
    
    int mi[3][3];
    char c;
    for(int i = 0; i < 9; i++) {
        cin >> c;
        mi[i / 3][i % 3] = c - '0';
    }
    State init(mi);
    
    priority_queue<Node> queue;
    set<State> visited;
    
    queue.push(Node(init, 0));
    
    while (!queue.empty()) {
        Node current = queue.top();
        queue.pop();
        
        State current_state = current.getState();
        int current_g = current.getG();
        
        // 检查是否到达目标状态
        if (current_state == TARGET) {
            cout << current_g << endl;
            return 0;
        }
        
        // 如果已经访问过，跳过
        if (visited.find(current_state) != visited.end()) {
            continue;
        }
        
        visited.insert(current_state);
        
        // 生成下一步状态
        vector<State> next_states = current_state.next();
        for (const State& next_state : next_states) {
            if (visited.find(next_state) == visited.end()) {
                queue.push(Node(next_state, current_g + 1));
            }
        }
    }
    
    return 0;
}