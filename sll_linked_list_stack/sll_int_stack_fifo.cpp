
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Student
{
    string name;
    double gpa;
    int sID;
    char grade;
};

struct Node
{
    int data;
    Node *next;
};

Node* create_sll(const int);

//void populate_data(Node*);
void display_data(Node*); //pass by value
void cleanup(Node* &);  //pass by ref.

int main()
{
    const int SIZE = 4;
    Node *head = create_sll(SIZE);
    cout << "In the main(): " << endl;
    cout << setw(10) << "&head: " << &head << endl;
    cout << setw(10) << "head: " << head << endl;
    //populate_data(head);
    display_data(head);
    cleanup(head);

    return 0;
}

void display_data(Node* head) // header is local to display data
{
    cout << "In the display(): " << endl;
    cout << setw(10) << "&head: " << &head << endl;
    cout << setw(10) << "head: " << head << endl;

    Node* current = head;

    while(current != nullptr)
    {
        cout << "\t current->data " << current->data << " " <<   "current: " << current << endl;
        current = current->next;
    }
    cout << setw(10) << "prev. : " << current << endl;
}

Node* create_sll(const int SIZE)
{
    srand(time(0));
    Node* head = nullptr; // int. value in virtual RAM add.
    Node* prev = nullptr;
    for(int i = 0; i < SIZE; i++)
    {
        // allocation in the heap
        if(head == nullptr) {
        // head = new Node; // collection of nodes in a forward direction/backward --> just need only "1" pointer
            prev = head = new Node;
            head->next = nullptr; // new next node "empty"
            head->data = rand() % 100; // 0-99
        }
        else {
           head = new Node; // Collection of Nodes in a Forward Direction
           head->next = prev;
           head->data = rand() % 100;
           prev = head; // head = prev
        }
        cout << "head->data: " << head->data <<endl;
    }
        cout << "In the create_sll(): " << endl;
        cout << setw(10) << "&head: " << &head << endl;
        cout << setw(10) << "head: " << head << endl;

        return head;
}

void populate_data(Node* head) { // head: local to pop
    string names[] = {"Kevin Mitnick", " Jon Erickson", "Cliff Stoll", "Nicole Perloth"};
    double gpa[] = {3.6, 4.0, 4.0, 3.5};
    int    sID[] = {2015140, 2015141, 2015142, 2015143};
    char   grade[] = {'B', 'A', 'A', 'B'};

}

void cleanup(Node*& head) { //head: local to display
    cout << "In the cleanup(): " << endl;
        cout << setw(10) << "&head: " << &head << endl;
        cout << setw(10) << "head: " << head << endl;
    Node* current = head;
    while(current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    // cout << " current: " << current << endl;
}


