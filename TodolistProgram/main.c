#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

    printf("\n");

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

void DisplaySchedule() {

    printf("\n");

    // g_schedules 배열 원소 출력
    printf("현재 일정 목록\n");
    for (int i = 0; i < g_num_schedules; i++) {
        printf("%d. 제목: %s, 설명: %s\n", i + 1, g_schedules[i].title, g_schedules[i].description);
    }

    // 일정 시간동안 작업을 대기하는 함수
    sleep(1);
}

void DeleteSchedule() {

    printf("\n");

    int index;
    DisplaySchedule();
    printf("삭제할 일정 번호를 입력: ");
    scanf("%d", &index);

    if (index < 1 || index > g_num_schedules) {
        printf("잘못된 일정 번호 입력.\n");
        return;
    }

    index--;
    for (int i = index; i < g_num_schedules; i++) {
        strcpy(g_schedules[i].title, g_schedules[i+1].title);
        strcpy(g_schedules[i].description, g_schedules[i+1].description);
    }

    g_num_schedules--;
    printf("일정이 삭제됨.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n일정 관리 프로그램\n");
        printf("1. 일정 추가\n");
        printf("2. 일정 목록 표시\n");
        printf("3. 일정 삭제\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddSchedule();
                break;
            case 2:
                DisplaySchedule();
                break;
            case 3:
                DeleteSchedule();
                break;
            case 4:
                printf("프로그램을 종료.\n");
                exit(0);
            default:
                printf("잘못된 선택.\n");
        }
    }

    return 0;
}