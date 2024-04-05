#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool isValid(int x, int y, int N, int M, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0 && !visited[x][y]);
}

vector<Point> findPath(vector<vector<int>>& maze, int startX, int startY, int targetX, int targetY) {
    int N = maze.size();
    int M = maze[0].size();

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<Point>> parent(N, vector<Point>(M, {-1, -1}));

    queue<Point> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == targetX && current.y == targetY) {
            vector<Point> path;
            while (current.x != -1 && current.y != -1) {
                path.push_back(current);
                current = parent[current.x][current.y];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            if (isValid(newX, newY, N, M, maze, visited)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
                parent[newX][newY] = current;
            }
        }
    }

    return {};
}

int main() {
    ifstream fin(R"(C:\Users\Egor\Desktop\Coding\C++\KA_Lab1\in.txt)");
    ofstream fout(R"(C:\Users\Egor\Desktop\Coding\C++\KA_Lab1\out.txt)");

    if (!fin.is_open()) // если файл не открыт
        cout << "Cannot open the file\n";

    int N, M;
    fin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            fin >> maze[i][j];
        }
    }

    int startX, startY, targetX, targetY;
    fin >> startX >> startY >> targetX >> targetY;

    vector<Point> path = findPath(maze, startX - 1, startY - 1, targetX - 1, targetY - 1);

    if (path.empty()) {
        fout << "N" << endl;
    } else {
        fout << "Y" << endl;
        for (const auto& point : path) {
            fout << point.x + 1 << " " << point.y + 1 << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
