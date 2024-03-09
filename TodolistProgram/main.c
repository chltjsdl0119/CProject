#include <stdio.h>

#define MAX_SCHEDULES 50
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

// 일정 구조체
// 멤버로 50Byte의 배열과 100Byte의 배열을 가진다.
struct Schedule {
    // 문자열을 제목으로 입력받을 배열
    char title[MAX_TITLE_LENGTH]; // 1Byte * 50

    // 문자열을 일정 설명으로 입력받을 배열
    char description[MAX_DESCRIPTION_LENGTH]; // 1Byte * 100
};

// 전역 변수 선언
// 아래 변수 schedules와 num_schedules는 프로그램이 실행될 때 메모리의 data영역에 할당된다.
struct Schedule g_schedules[MAX_SCHEDULES];
int g_num_schedules = 0;

// 일정을 추가하는 함수
// 메모리의 data영역에 할당된 전역 변수 g_schedules[MAX_SCHEDULES]에 일정을 추가하는 함수
void AddSchedule() {

    // 스케줄이 50개 이상일 경우, 더 이상 스케줄을 추가할 수 없다.
    if (g_num_schedules >= MAX_SCHEDULES) {
        printf("일정을 더 이상 추가할 수 없다.\n");
        return;
    }

    printf("새로운 일정을 추가.\n");
    printf("일정 제목을 입력: ");

    // 전역 변수로 선언된 g_schedules배열 g_num_schedules번째 원소의 멤버인 title에 일정 제목을 입력받는다.
    scanf("%s", g_schedules[g_num_schedules].title);
    printf("일정 설명을 입력: ");

    // 전역 변수로 선언된 g_schedules배열 g_num_schedules번째 원소의 멤버인 description에 일정 제목을 입력받는다.
    scanf("%s", g_schedules[g_num_schedules].description);

    // 일정 하나를 추가했으므로, g_num_schedules++;
    g_num_schedules++;
}