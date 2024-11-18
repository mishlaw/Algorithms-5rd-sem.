#include <iostream>
#include <string>

using namespace std;

/*class Node {
public:
    double data;
    Node* next;

public:
    Node(double data) {
        this->data = data;
        this->next = NULL;
    }
};

class OneLinkedList {
private:
    Node* head; // Указатель на начало списка
public:
    OneLinkedList() : head(nullptr) {}; //Конструктор
    void append(double val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next; //Определяем следующий элемент(указатель хранящийся в current)
            current->next = prev; //Теперь этот указатель становится предыдущим
            prev = current; //
            current = next;
        }

        head = prev; // Устанавливаем новое начало списка
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << " ";
    }

    int search(double key) {
        Node* current = head;
        int i = -1;
        // Перемещаемся по списку до конца или до нахождения элемента
        while (current != nullptr) {
            i++;
            if (current->data == key) {
                cout << "Элемент есть в списке, его номер " << i;
                return i; // Элемент найден
            }
            current = current->next;
        }
        cout << "Элемента нет в списке";
        return -1; // Элемент не найден
    }

    void deleteEl(double key) {
        Node* current = head;
        Node* prev = nullptr;

        // Поиск элемента и его предшествующего узла
        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        // Если элемент найден, удаляем его
        if (current != nullptr) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
        }
    }

    void deleteList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

};

void Append_Test() {
    OneLinkedList list;
    cout << "Введите длину списка";
    int n; cin >> n;
    cout << "Введите список";
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        list.append(a);
    }
    cout << "Введите элемент, который необходимо добавить"; double el; cin >> el;
    list.append(el);
    list.display();
}

void Search_Test() {
    OneLinkedList list;
    cout << "Введите длину списка";
    int n; cin >> n;
    cout << "Введите список";
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        list.append(a);
    }
    cout << "Введите элемент, который необходимо найти"; double el; cin >> el;
    list.search(el);
}

void Delete_Element_Test() {
    OneLinkedList list;
    cout << "Введите длину списка";
    int n; cin >> n;
    cout << "Введите список";
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        list.append(a);
    }
    cout << "Введите элемент, который необходимо удалить"; double el; cin >> el;
    list.deleteEl(el);
    list.display();
}

void PersonalTask() {
    OneLinkedList list;
    cout << "Введите длину списка";
    int n; cin >> n;
    cout << "Введите список";
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        list.append(a);
    }
    list.reverse();
    list.display();
}

/*int main() {
    setlocale(LC_ALL, "Russian");
    while (1) {
        //Append_Test();
        //Search_Test();
        //Delete_Element_Test();
        PersonalTask();
        cout << endl;
    }
} */