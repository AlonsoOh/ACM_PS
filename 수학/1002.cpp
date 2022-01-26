#include<stdio.h>
#include<math.h>

int main(void) {
    int t;							        //테스트 케이스의 수
    int x1, x2, y1, y2, r1, r2;				//x1, x2, y1, y2 두 사람의 위치를 나타내는 좌표, r1, r2 : 마린까지의 거리 
    double distance;					    //두 터렛 사이의 거리
    
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        //두 점 사이의 거리
        distance = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));

        //둘이 같은 위치일 경우
        if (distance == 0) {
            //r1, r2가 일치하면 둘의 위치를 중심으로 원을 이루는 위치 어디든 가능하므로 무한대
            if (r1 == r2) printf("-1\n");

            //거리 다르면 만족하는 위치는 존재하지 않음
            else printf("0\n");
        }

        //두 점에 만나는 경우
        else if (abs(r1 - r2) < distance && distance < r1 + r2) printf("2\n");

        //한 점에서 외접하거나 내접하는 경우
        else if (r1 + r2 == distance || distance == abs(r1 - r2)) printf("1\n");

        //그 밖의 경우는 없음
        else printf("0\n");
    }
    return 0;
}
