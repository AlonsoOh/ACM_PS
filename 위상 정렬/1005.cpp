#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000 + 1

vector<int> build_time;                                     //건물 건설 시간
vector<int> graph[MAX];                                     //순서에 대한 정보 저장
int node_count[MAX] = { 0, };                               //해당 번호로 들어가는 링크 수 저장
long long order_time[MAX] = { 0, };                         //해당 순서의 최대 값
int N, K, W;                                                //건물 수, 규칙 개수, 완료해야할 건물 번호

//자료구조 초기화
void init() {
    for (int i = 1; i <= N; i++) {
        graph[i].clear();
        node_count[i] = 0;
        order_time[i] = 0;
    }

    build_time.clear();
}

//위상 정렬로 문제 해결
long long topology() {
    queue<pair<int, int>> q;                                    //건물 번호와 순서 번호로 위상 정렬 수행
    int order = 1;                                              //순서 번호

    for (int i = 1; i <= N; i++) {                              //해당 정점에 들어가는 간선이 없다면 큐에 삽입
        if (!node_count[i]) {
            q.push({ i, order });
            order_time[i] = build_time[i];
        }
    }

    while (!q.empty()) {
        int b, o;
        b = q.front().first;
        o = q.front().second;
        q.pop();

        //원하는 건물 번호에 도달하면 order_time을 리턴
        if (b == W) return order_time[W];

        //그 다음 순서에 올 건물의 빌드 타임을 비교하여 업데이트
        for (int i : graph[b]) {
            node_count[i]--;
            order_time[i] = max(order_time[i], order_time[b] + build_time[i]);

            //해당 노드에 들어가는 노드들이 더 이상 없으면 큐에 해당 노드를 삽입함 
            if (!node_count[i]) q.push({ i, o + 1 });
        }
    }
}

int main() {
    int T;

    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &K);
        build_time.resize(N + 1);

        for (int i = 1; i <= N; i++)
            scanf("%d", &build_time[i]);

        while (K--) {
            int X, Y;

            scanf("%d %d", &X, &Y);
            graph[X].push_back(Y);
            node_count[Y]++;
        }

        scanf("%d", &W);
        printf("%d\n", topology());
        //다음 케이스를 위해 자료구조 초기화
        init();
    }

    return 0;
}
