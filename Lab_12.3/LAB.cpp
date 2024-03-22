#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->next = NULL; // 3
    if (last != NULL)
        last->next = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value; // 7
}

void insertBeforeFirst(Elem*& first, int V1, int V2) {
    if (first == NULL || first->info == V1) {
        Elem* tmp = new Elem;
        tmp->info = V2;
        tmp->prev = NULL;
        tmp->next = first;
        if (first != NULL)
            first->prev = tmp;
        first = tmp;
    }
}

void insertBeforeMiddle(Elem*& first, int V1, int V2) {
    Elem* current = first;
    while (current != NULL && current->next != NULL) {
        if (current->next->info == V1) {
            Elem* tmp = new Elem;
            tmp->info = V2;
            tmp->prev = current;
            tmp->next = current->next;
            current->next->prev = tmp;
            current->next = tmp;
            break;
        }
        current = current->next;
    }
}

void insertBeforeLast(Elem*& first, Elem*& last, int V1, int V2) {
    if (last != NULL && last->info == V1) {
        Elem* tmp = new Elem;
        tmp->info = V2;
        tmp->prev = last->prev;
        tmp->next = last;
        if (last->prev != NULL)
            last->prev->next = tmp;
        last->prev = tmp;
    }
}

void printList(Elem* head)
{
    while (head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* head = NULL;
    Elem* last = NULL;

    enqueue(head, last, -2);
    enqueue(head, last, 5);
    enqueue(head, last, -7);
    enqueue(head, last, 3);
    enqueue(head, last, -8);

    // Роздрукуємо список
    cout << "Список: ";
    printList(head);

    // Вставка перед першим елементом
    insertBeforeFirst(head, -2, 0);
    cout << "Після вставки перед першим елементом: ";
    printList(head);

    // Вставка перед середнім елементом
    insertBeforeMiddle(head, -7, -6);
    cout << "Після вставки перед середнім елементом: ";
    printList(head);

    // Вставка перед останнім елементом
    insertBeforeLast(head, last, -8, -9);
    cout << "Після вставки перед останнім елементом: ";
    printList(head);

    // Звільняємо пам'ять
    while (head != nullptr)
    {
        Elem* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
