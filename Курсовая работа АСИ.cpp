#include <iostream>
#include <vector>
#include <locale.h>
#include <string>
#include <map>
#include <iomanip>


using namespace std;

class Teacher { //Здесь хранятся преподаватели: имя, интервалы занятости, кол-во занятий, которые должен провести
    public:
        string name;
        vector<pair<int, int>> busy_intervals; // Занятые интервалы времени
        int need_to_teach; // Количество пар, которые нужно провести
        int assigned_lessons; //Количество назначенных пар
        Teacher(string n,  int classes)
            : name(n), need_to_teach(classes), assigned_lessons(0) {}
};

class Timetable {
public:
    vector<string> lessons; //Вектор: номер пары- имя преподавателя.
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

// Функция для проверки, может ли преподаватель вести пару в данное время
bool can_teach(const Teacher& teacher, int lesson_num) {
    for (const auto& interval : teacher.busy_intervals) {
        if (lesson_num >= interval.first  && lesson_num <= interval.second) {
            return false;
        }
    }
    return true;
}

bool backtrack_schedule(vector<Teacher>& teachers, Timetable& timetable, int current_lesson, int N) {
    // Базовый случай: все пары распределены
    if (current_lesson > N) {
        // Проверяем, все ли преподаватели получили нужное количество пар
        for (const Teacher& teacher : teachers) {
            if (teacher.assigned_lessons != teacher.need_to_teach) {
                return false;
            }
        }
        return true;
    }

    // Если текущая пара уже назначена, переходим к следующей
    if (!timetable.is_free(current_lesson)) {
        return backtrack_schedule(teachers, timetable, current_lesson + 1, N);
    }

    // Пробуем назначить каждого преподавателя на текущую пару
    for (Teacher& teacher : teachers) {
        // Проверяем, может ли преподаватель взять ещё пары и доступен ли он в это время
        if (teacher.assigned_lessons < teacher.need_to_teach && can_teach(teacher, current_lesson)) {
            // Пробуем назначить преподавателя
            timetable.assign_lesson(current_lesson, teacher.name);
            teacher.assigned_lessons++;

            // Рекурсивно пробуем составить оставшееся расписание
            if (backtrack_schedule(teachers, timetable, current_lesson + 1, N)) {
                return true;
            }


            // Если не получилось, отменяем назначение (backtrack)
            timetable.unassign_lesson(current_lesson);
            teacher.assigned_lessons--;
        }
    }

    return false;
}

void print_timetable(const Timetable& timetable, vector<Teacher>& teachers, int N) {
    setlocale(LC_ALL, "Russian");
    cout << "\nРасписание:\n";
    cout << "-------------------------\n";
    cout << "Пара | Преподаватель\n";
    cout << "-------------------------\n";

    for (int i = 0; i < N; ++i) {
        cout << setw(4) << i + 1 << " | ";
        if (timetable.lessons[i] != "null") {
            cout  << timetable.lessons[i];
        }
        else {
            cout << "Не назначено";
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

    int N;  // Общее количество пар
    int M;  // Количество преподавателей

    cout << "Введите общее количество пар: \n";
    cin >> N;

    cout << "Введите количество преподавателей/предметов: \n";
    cin >> M;

    vector<Teacher> teachers;

    // Ввод данных о преподавателях
    for (int i = 0; i < M; ++i) {
        int n_i;
        string name;
        cout << "\nПреподаватель/Предмет " ;
        cin >> name;
        cout << "Введите количество требуемых пар: ";
        cin >> n_i ;

        Teacher teacher(name, n_i );

        int intervals;
        cout << "Введите количество интервалов занятости: ";
        cin >> intervals;

        for (int j = 0; j < intervals; ++j) {
            int start, end;
            cout << "Введите интервал занятости " << j + 1 << " (начало конец). Если занятость одна пара, то начало и конец задавайте одинаковым значением: ";
            cin >> start >> end;
            teacher.busy_intervals.push_back({ start, end });
        }

        teachers.push_back(teacher);
    }

  
    // Проверяем корректность входных данных
    if (!validate_input(N, teachers)) {
        return 1;
    }

    Timetable timetable(N);

    // Пытаемся составить расписание
    if (backtrack_schedule(teachers, timetable, 1, N)) {
        cout << "\nРасписание успешно составлено!\n";
        print_timetable(timetable, teachers , N);
    }
    else {
        cout << "\nНевозможно составить расписание с заданными ограничениями!\n";
    }

    return 0;
} */
