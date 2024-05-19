#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// �ṹ�嶨�壺ѧ����Ϣ
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

// ��������
void inputStudentScores(struct Student students[], int numStudents);
void calculateTotalScore(struct Student students[], int numStudents);
void displayStudentInfo(struct Student students[], int numStudents);
void saveToFile(struct Student students[], int numStudents);
void loadFromFile(struct Student students[], int* numStudents);
void manageStudentData(struct Student students[], int numStudents);
void queryStudentData(struct Student students[], int numStudents);

int main() {
    const int MAX_STUDENTS = 100;  // ���ѧ����
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;

    do {
        // ��ʾ�˵�
        printf("==== ѧ���ۺϲ���ϵͳ ====\n");
        printf("1. ¼��ѧ���ɼ�\n");
        printf("2. �����ۺϲ���\n");
        printf("3. ѧ�����ݹ���\n");
        printf("4. ѧ�����ݲ�ѯ\n");
        printf("5. ���ѧ����Ϣ\n");
        printf("0. �˳�\n");
        printf("������ѡ��: ");
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
            printf("�������˳���\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    } while (choice != 0);

    return 0;
}

// ¼��ѧ���ɼ�
void inputStudentScores(struct Student students[], int numStudents) {
    // ʵ��¼��ѧ���ɼ����߼�
    printf("������ѧ������Ϣ��\n");
    printf("ѧ��: ");
    scanf("%d", &students[numStudents].studentId);
    printf("����: ");
    scanf("%s", students[numStudents].name);
    printf("���ĳɼ�: ");
    scanf("%f", &students[numStudents].chinese);
    printf("��ѧ�ɼ�: ");
    scanf("%f", &students[numStudents].math);
    printf("����ɼ�: ");
    scanf("%f", &students[numStudents].english);

    // ����ƽ���ɼ�������
    students[numStudents].examAverage = (students[numStudents].chinese + students[numStudents].math + students[numStudents].english) / 3;
    students[numStudents].examRank = 0; // δ��������

    // ��ѧ����Ϣд���ļ�
    saveToFile(students, numStudents + 1);

    printf("ѧ���ɼ�¼��ɹ���\n");
}

// �����ۺϲ���
void calculateTotalScore(struct Student students[], int numStudents) {
    // ʵ�ּ����ۺϲ������߼�
    for (int i = 0; i < numStudents; ++i) {
        students[i].totalScore = students[i].examAverage * 0.6 +
            students[i].peerAssessment * 0.1 +
            students[i].moralityScore * 0.1 +
            students[i].teacherAssessment * 0.2;
        students[i].totalRank = 0; // δ��������
    }

    printf("�ۺϲ���������ɣ�\n");
}

// ���ѧ����Ϣ
void displayStudentInfo(struct Student students[], int numStudents) {
    // ʵ�����ѧ����Ϣ���߼�
    printf("ѧ����Ϣ���£�\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("ѧ��: %d, ����: %s, �ۺϲ����ܷ�: %.2f, �ۺϲ�������: %d\n",
            students[i].studentId, students[i].name, students[i].totalScore, students[i].totalRank);
    }
}

// ����ѧ����Ϣ���ļ�
void saveToFile(struct Student students[], int numStudents) {
    // ʵ�ֱ���ѧ����Ϣ���ļ����߼�
    FILE* file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("�޷����ļ����б��档\n");
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
    printf("ѧ����Ϣ�ѱ��浽�ļ���\n");
}

// ���ļ�����ѧ����Ϣ
void loadFromFile(struct Student students[], int* numStudents) {
    // ʵ�ִ��ļ�����ѧ����Ϣ���߼�
    FILE* file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("�޷����ļ����м��ء�\n");
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
    printf("ѧ����Ϣ�Ѵ��ļ����ء�\n");
}

// ѧ�����ݹ���
void manageStudentData(struct Student students[], int

    numStudents) {
    int studentId;
    int foundIndex = -1;

    // ����Ҫ�����ѧ��ѧ��
    printf("������Ҫ�����ѧ��ѧ��: ");
    scanf("%d", &studentId);

    // ����ѧ����Ϣ
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].studentId == studentId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // ��ʾѧ����Ϣ
        printf("ѧ����Ϣ���£�\n");
        displayStudentInfo(&students[foundIndex], 1);

        // ����������
        printf("�������µ�ѧ����Ϣ��\n");
        printf("���ĳɼ�: ");
        scanf("%f", &students[foundIndex].chinese);
        printf("��ѧ�ɼ�: ");
        scanf("%f", &students[foundIndex].math);
        printf("����ɼ�: ");
        scanf("%f", &students[foundIndex].english);

        // ���¼���ƽ���ɼ��ͱ��浽�ļ�
        students[foundIndex].examAverage = (students[foundIndex].chinese + students[foundIndex].math + students[foundIndex].english) / 3;
        saveToFile(students, numStudents);

        printf("ѧ����Ϣ���³ɹ���\n");
    }
    else {
        printf("δ�ҵ�ѧ��ѧ��Ϊ%d����Ϣ��\n", studentId);
    }
}

// ѧ�����ݲ�ѯ
void queryStudentData(struct Student students[], int numStudents) {
    int studentId;
    int foundIndex = -1;

    // ����Ҫ��ѯ��ѧ��ѧ��
    printf("������Ҫ��ѯ��ѧ��ѧ��: ");
    scanf("%d", &studentId);

    // ����ѧ����Ϣ
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].studentId == studentId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // ��ʾѧ����Ϣ
        printf("ѧ����Ϣ���£�\n");
        displayStudentInfo(&students[foundIndex], 1);
    }
    else {
        printf("δ�ҵ�ѧ��ѧ��Ϊ%d����Ϣ��\n", studentId);
    }
}



