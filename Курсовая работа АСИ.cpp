#include <iostream>
#include <vector>
#include <locale.h>
#include <string>
#include <map>
#include <iomanip>


using namespace std;

class Teacher { //����� �������� �������������: ���, ��������� ���������, ���-�� �������, ������� ������ ��������
    public:
        string name;
        vector<pair<int, int>> busy_intervals; // ������� ��������� �������
        int need_to_teach; // ���������� ���, ������� ����� ��������
        int assigned_lessons; //���������� ����������� ���
        Teacher(string n,  int classes)
            : name(n), need_to_teach(classes), assigned_lessons(0) {}
};

class Timetable {
public:
    vector<string> lessons; //������: ����� ����- ��� �������������.
    Timetable(int N) : lessons(N, "null") {}

    bool is_free(int lesson_num) const {
        return lessons[lesson_num-1] == "null";
    }

    void assign_lesson(int lesson_num, string name) {
        lessons[lesson_num-1] = name;
    }

    void unassign_lesson(int lesson_num) {
        lessons[lesson_num-1] = "null";
    }
};

// ������� ��� ��������, ����� �� ������������� ����� ���� � ������ �����
bool can_teach(const Teacher& teacher, int lesson_num) {
    for (const auto& interval : teacher.busy_intervals) {
        if (lesson_num >= interval.first  && lesson_num <= interval.second) {
            return false;
        }
    }
    return true;
}

bool backtrack_schedule(vector<Teacher>& teachers, Timetable& timetable, int current_lesson, int N) {
    // ������� ������: ��� ���� ������������
    if (current_lesson > N) {
        // ���������, ��� �� ������������� �������� ������ ���������� ���
        for (const Teacher& teacher : teachers) {
            if (teacher.assigned_lessons != teacher.need_to_teach) {
                return false;
            }
        }
        return true;
    }

    // ���� ������� ���� ��� ���������, ��������� � ���������
    if (!timetable.is_free(current_lesson)) {
        return backtrack_schedule(teachers, timetable, current_lesson + 1, N);
    }

    // ������� ��������� ������� ������������� �� ������� ����
    for (Teacher& teacher : teachers) {
        // ���������, ����� �� ������������� ����� ��� ���� � �������� �� �� � ��� �����
        if (teacher.assigned_lessons < teacher.need_to_teach && can_teach(teacher, current_lesson)) {
            // ������� ��������� �������������
            timetable.assign_lesson(current_lesson, teacher.name);
            teacher.assigned_lessons++;

            // ���������� ������� ��������� ���������� ����������
            if (backtrack_schedule(teachers, timetable, current_lesson + 1, N)) {
                return true;
            }


            // ���� �� ����������, �������� ���������� (backtrack)
            timetable.unassign_lesson(current_lesson);
            teacher.assigned_lessons--;
        }
    }

    return false;
}

void print_timetable(const Timetable& timetable, vector<Teacher>& teachers, int N) {
    setlocale(LC_ALL, "Russian");
    cout << "\n����������:\n";
    cout << "-------------------------\n";
    cout << "���� | �������������\n";
    cout << "-------------------------\n";

    for (int i = 0; i < N; ++i) {
        cout << setw(4) << i + 1 << " | ";
        if (timetable.lessons[i] != "null") {
            cout  << timetable.lessons[i];
        }
        else {
            cout << "�� ���������";
        }
        cout << endl;
    }
    cout << "-------------------------\n";
}

bool validate_input(int N, vector<Teacher>& teachers){
    return 1;
}

/*int main() {
    setlocale(LC_ALL, "Russian");

    int N;  // ����� ���������� ���
    int M;  // ���������� ��������������

    cout << "������� ����� ���������� ���: \n";
    cin >> N;

    cout << "������� ���������� ��������������/���������: \n";
    cin >> M;

    vector<Teacher> teachers;

    // ���� ������ � ��������������
    for (int i = 0; i < M; ++i) {
        int n_i;
        string name;
        cout << "\n�������������/������� " ;
        cin >> name;
        cout << "������� ���������� ��������� ���: ";
        cin >> n_i ;

        Teacher teacher(name, n_i );

        int intervals;
        cout << "������� ���������� ���������� ���������: ";
        cin >> intervals;

        for (int j = 0; j < intervals; ++j) {
            int start, end;
            cout << "������� �������� ��������� " << j + 1 << " (������ �����). ���� ��������� ���� ����, �� ������ � ����� ��������� ���������� ���������: ";
            cin >> start >> end;
            teacher.busy_intervals.push_back({ start, end });
        }

        teachers.push_back(teacher);
    }

  
    // ��������� ������������ ������� ������
    if (!validate_input(N, teachers)) {
        return 1;
    }

    Timetable timetable(N);

    // �������� ��������� ����������
    if (backtrack_schedule(teachers, timetable, 1, N)) {
        cout << "\n���������� ������� ����������!\n";
        print_timetable(timetable, teachers , N);
    }
    else {
        cout << "\n���������� ��������� ���������� � ��������� �������������!\n";
    }

    return 0;
} */
