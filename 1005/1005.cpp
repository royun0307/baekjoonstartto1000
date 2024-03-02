#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node{
    int time = 0;
    int total_time = 0;
    std::vector <int> next;
    int num_pre = 0;
};

class ACMCraft {
public:
    ACMCraft(int _size) :size(_size){
        SetBuilding();
    }
    void SetBuilding() {
        Node node;
        for (int i = 0; i < size; i++)
        {
            building.push_back(node);
        }
        return;
    }
    void SetTime() {
        int time;
        for (int i = 0; i < size; i++)
        {
            time = -1;
            std::cin >> time;
            building[i].time = time;
        }
        return;
    }
    void SetOrder(int num) {
        int x, y = 0;
        for (int i = 0; i < num; i++)
        {
            std::cin >> x >> y;
            building[x - 1].next.push_back(y);
            building[y - 1].num_pre++;
        }
        
        for (int i = 0; i < size; i++)
        {
            if (building[i].num_pre == 0) {
                queue.push(i);
            }
        }
        return;
    }

    void getTotalTime() {
        int w;
        int num;
        std::cin >> w;
        while (building[w - 1].num_pre > 0) {
            num = queue.front();
            queue.pop();
            for (int i = 0; i < building[num].next.size(); i++)
            {
                int next = building[num].next[i] - 1;
                building[next].total_time = std::max(building[next].total_time, building[num].total_time + building[num].time);
                building[next].num_pre--;
                if (building[next].num_pre == 0) {
                    queue.push(next);
                }
            }
        }
        std::cout << building[w - 1].time + building[w - 1].total_time << std::endl;
        return;
    }
private:
    int size;
    std::vector <Node> building;
    std::queue <int> queue;
};

int main() {
    int t, n, k;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n >> k;
        ACMCraft acmcraft(n);
        acmcraft.SetTime();
        acmcraft.SetOrder(k);
        acmcraft.getTotalTime();
    }

    return 0;
}
