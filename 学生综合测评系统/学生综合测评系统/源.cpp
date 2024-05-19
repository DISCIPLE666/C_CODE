#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 结构体定义：学生信息
struct Student {
    int studentId;
    char name[50];
    float chinese;
    float math;
    float english;
    float examAverage;
    int examRank;
    float peerAssessment;
    float moralityScore;
    float teacherAssessment;
    float totalScore;
    int totalRank;
};

// 函数声明
void inputStudentScores(struct Student students[], int numStudents);
void calculateTotalScore(struct Student students[], int numStudents);
void displayStudentInfo(struct Student students[], int numStudents);
void saveToFile(struct Student students[], int numStudents);
void loadFromFile(struct Student students[], int* numStudents);
void manageStudentData(struct Student students[], int numStudents);
void queryStudentData(struct Student students[], int numStudents);

int main() {
    const int MAX_STUDENTS = 100;  // 最大学生数
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;

    do {
        // 显示菜单
        printf("==== 学生综合测评系统 ====\n");
        printf("1. 录入学生成绩\n");
        printf("2. 计算综合测评\n");
        printf("3. 学生数据管理\n");
        printf("4. 学生数据查询\n");
        printf("5. 输出学生信息\n");
        printf("0. 退出\n");
        printf("请输入选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inputStudentScores(students, numStudents);
            break;
        case 2:
            calculateTotalScore(students, numStudents);
            break;
        case 3:
            manageStudentData(students, numStudents);
            break;
        case 4:
            queryStudentData(students, numStudents);
            break;
        case 5:
            displayStudentInfo(students, numStudents);
            break;
        case 0:
            printf("程序已退出。\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    } while (choice != 0);

    return 0;
}

// 录入学生成绩
void inputStudentScores(struct Student students[], int numStudents) {
    // 实现录入学生成绩的逻辑
    printf("请输入学生的信息：\n");
    printf("学号: ");
    scanf("%d", &students[numStudents].studentId);
    printf("姓名: ");
    scanf("%s", students[numStudents].name);
    printf("语文成绩: ");
    scanf("%f", &students[numStudents].chinese);
    printf("数学成绩: ");
    scanf("%f", &students[numStudents].math);
    printf("外语成绩: ");
    scanf("%f", &students[numStudents].english);

    // 计算平均成绩和名次
    students[numStudents].examAverage = (students[numStudents].chinese + students[numStudents].math + students[numStudents].english) / 3;
    students[numStudents].examRank = 0; // 未计算名次

    // 将学生信息写入文件
    saveToFile(students, numStudents + 1);

    printf("学生成绩录入成功！\n");
}

// 计算综合测评
void calculateTotalScore(struct Student students[], int numStudents) {
    // 实现计算综合测评的逻辑
    for (int i = 0; i < numStudents; ++i) {
        students[i].totalScore = students[i].examAverage * 0.6 +
            students[i].peerAssessment * 0.1 +
            students[i].moralityScore * 0.1 +
            students[i].teacherAssessment * 0.2;
        students[i].totalRank = 0; // 未计算名次
    }

    printf("综合测评计算完成！\n");
}

// 输出学生信息
void displayStudentInfo(struct Student students[], int numStudents) {
    // 实现输出学生信息的逻辑
    printf("学生信息如下：\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("学号: %d, 姓名: %s, 综合测评总分: %.2f, 综合测评名次: %d\n",
            students[i].studentId, students[i].name, students[i].totalScore, students[i].totalRank);
    }
}

// 保存学生信息到文件
void saveToFile(struct Student students[], int numStudents) {
    // 实现保存学生信息到文件的逻辑
    FILE* file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("无法打开文件进行保存。\n");
        return;
    }
    for (int i = 0; i < numStudents; ++i) {
        fprintf(file, "%d %s %.2f %.2f %.2f %.2f %d %.2f %.2f %.2f %.2f %d\n",
            students[i].studentId, students[i].name, students[i].chinese, students[i].math,
            students[i].english, students[i].examAverage, students[i].examRank,
            students[i].peerAssessment, students[i].moralityScore,
            students[i].teacherAssessment, students[i].totalScore, students[i].totalRank);
    }

    fclose(file);
    printf("学生信息已保存到文件。\n");
}

// 从文件加载学生信息
void loadFromFile(struct Student students[], int* numStudents) {
    // 实现从文件加载学生信息的逻辑
    FILE* file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("无法打开文件进行加载。\n");
        return;
    }

    while (fscanf(file, "%d %s %f %f %f %f %d %f %f %f %f %d",
        &students[*numStudents].studentId, students[*numStudents].name,
        &students[*numStudents].chinese, &students[*numStudents].math,
        &students[*numStudents].english, &students[*numStudents].examAverage,
        &students[*numStudents].examRank, &students[*numStudents].peerAssessment,
        &students[*numStudents].moralityScore, &students[*numStudents].teacherAssessment,
        &students[*numStudents].totalScore, &students[*numStudents].totalRank) != EOF) {
        (*numStudents)++;
    }

    fclose(file);
    printf("学生信息已从文件加载。\n");
}

// 学生数据管理
void manageStudentData(struct Student students[], int

    numStudents) {
    int studentId;
    int foundIndex = -1;

    // 输入要管理的学生学号
    printf("请输入要管理的学生学号: ");
    scanf("%d", &studentId);

    // 查找学生信息
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].studentId == studentId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // 显示学生信息
        printf("学生信息如下：\n");
        displayStudentInfo(&students[foundIndex], 1);

        // 输入新数据
        printf("请输入新的学生信息：\n");
        printf("语文成绩: ");
        scanf("%f", &students[foundIndex].chinese);
        printf("数学成绩: ");
        scanf("%f", &students[foundIndex].math);
        printf("外语成绩: ");
        scanf("%f", &students[foundIndex].english);

        // 重新计算平均成绩和保存到文件
        students[foundIndex].examAverage = (students[foundIndex].chinese + students[foundIndex].math + students[foundIndex].english) / 3;
        saveToFile(students, numStudents);

        printf("学生信息更新成功！\n");
    }
    else {
        printf("未找到学生学号为%d的信息。\n", studentId);
    }
}

// 学生数据查询
void queryStudentData(struct Student students[], int numStudents) {
    int studentId;
    int foundIndex = -1;

    // 输入要查询的学生学号
    printf("请输入要查询的学生学号: ");
    scanf("%d", &studentId);

    // 查找学生信息
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].studentId == studentId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // 显示学生信息
        printf("学生信息如下：\n");
        displayStudentInfo(&students[foundIndex], 1);
    }
    else {
        printf("未找到学生学号为%d的信息。\n", studentId);
    }
}



