#include "DoublyLinkedList.h"

//
//Data::Data(string _ticket,
//    string _station,
//    int _train_num,
//    int _wagon_num,
//    int _cost,
//    int _seat,
//    int _date) : ticket(_ticket), station(_station),train_num(_train_num),wagon_num(_wagon_num),cost(_cost),seat(_seat),date(_date)
//{}

Data::Data()
{
    ticket = "Standart ticket";
    station = "Station";
    train_num = wagon_num = cost = seat = date = 1;
}

void Data::setData(string _ticket,
    string _station,
    int _train_num,
    int _wagon_num,
    int _cost,
    int _seat,
    int _date)
{
    cout << "Please, input ticket,station, train, wagon, cost, seat, date\n";
    cin >> _ticket >> _station >> _train_num >> _wagon_num >> _cost >> _seat >> _date;  // может правильно, по идее не надо будет менять ничего в дрругих, как раз не параметризированный конструктор
    this->station = _station;                                                          // или можно с ним, просто вызывать конструктор и типа все
    this->ticket = _ticket;
    this->train_num = _train_num;
    this->wagon_num = _wagon_num;
    this->cost = _cost;
    this->seat = _seat;
    this->date = _date;
}

void Data::printData() 
{
    cout << "Ticket: " << ticket << " Station:" << station << " Train:" << train_num << " Wagon:" << wagon_num << " Cost:" << cost
        << " Seat:" << seat << " Date:" << date << endl;
}

 bool Data::isHigher(Data& other, int choise = 0) 
{
    if (choise == 0) 
    {
        if (this->date > other.date)
            return true;
        else
            return false;
    }
    else
        if (this->wagon_num > other.wagon_num)
            return true;
        else
            return false;
}

bool Data::isLower(Data& other, int choise = 0)
{
    if (choise == 0)
    {
        if (this->date <  other.date)
            return true;
        else
            return false;
    }
    else
        if (this->wagon_num < other.wagon_num)
            return true;
        else
            return false;
}

bool Data::isSame(Data& other, int choise = 0)
{
    if (choise == 0)
    {
        if (this->date == other.date)
            return true;
        else
            return false;
    }
    else
        if (this->wagon_num == other.wagon_num)
            return true;
        else
            return false;
}
///////////////////////////////////////////////////////////////////////////////////

Node::Node()
{
    prev = NULL;
    next = NULL;
}

Node::Node(ISortableObject* obj)
{
    prev = NULL;
    next = NULL;
    this->obj = obj;
}

Node::~Node() 
{
    delete obj;
}

//void Node::deleteNode(int _date)
//
//{
//
//
//}


///////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////
DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

void DoublyLinkedList::addNode(ISortableObject* obj)
{
    Node* NewNode = new Node(obj);
    if (head == NULL) //Значит список пустой
    {
        head = NewNode;
        tail = NewNode;
        // NewNode->prev  и  NewNode->next = NULL
    }
    else //В списке есть хоть один узел
    {
        NewNode->prev = tail;
        tail->next = NewNode;
        tail = NewNode;
    }
    
}

void DoublyLinkedList::printList() {
    Node* current = head;

    while (current != NULL) {
        current->getObject()->printData();
    }
    cout << endl;
}

void DoublyLinkedList::reversePrintList() {
    Node* current = tail;

    while (current != NULL) {
        current->getObject()-> printData();
        current = current->prev;
    }
    cout << endl;
}
void DoublyLinkedList::deleteNode(function<ISortableObject>obj) {//не совем понятно, а по какому принципу сделать, можно добавить свитч кейс на поиск, пока оставлю типа по номеру поезда,хз, завтра допишу с кейсом чтобы можно было выбрать,хе
    Node* current = head;
    while (current != NULL) {
        if (current->getObject() == ) {
            if (current == head && current == tail) { // удаляем последний элемент
                head = NULL;
                tail = NULL;
            }
            else if (current == head) { // удаляем первый элемент
                head = current->next;
                head->prev = NULL;
            }
            else if (current == tail) { // удаляем последний элемент
                tail = current->prev;
                tail->next = NULL;
            }
            else { // удаляем элемент в середине списка
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

        }
    }
}
//Node* DoublyLinkedList::nodeSearch(int val) 
//{
//    Node* current = head;
//    while (current!=NULL)
//    {
//        if (current->train_num = val)
//            return current;
//    }
//    cout << "Not found";
//    return nullptr;
//}
    void DoublyLinkedList::sortedList(int inkr){
    Node* left = head;                
    Node* right = head->next;          
    int choise;

    Node* temp = new Node;             
    
    printList();
}
void DoublyLinkedList::cloneNodes(Node* temp, Node* left, Node* right)
{
    temp->data = left->data;
    temp->cost = left->cost;
    temp->seat = left->seat;
    temp->station = left->station;
    temp->ticket = left->ticket;
    temp->train_num = left->train_num;
    temp->wagon_num = left->wagon_num;

    left->data = right->data;
    left->cost = right->cost;
    left->seat = right->seat;
    left->station = right->station;
    left->ticket = right->ticket;
    left->train_num = right->train_num;
    left->wagon_num = right->wagon_num;

    right->data = temp->data;             
    right->cost = temp->cost;
    right->seat = temp->seat;
    right->station = temp->station;
    right->ticket = temp->ticket;
    right->train_num = temp->train_num;
    right->wagon_num = temp->wagon_num;

}

void DoublyLinkedList::deleteByDate(int data)
{
    Node* current = head;
    while (current!=NULL)
    {
        if (current->data < data)
            deleteNode(current->data);
        current = current->next;
    }
    printList();
}
void DoublyLinkedList::formNewList(int data)
{
    Node* current = head;
    while (head!=NULL)
    {
        if (current->data != data)
            deleteNode(current->data);    
        current = current->next;
    }
    printList();
}
void DoublyLinkedList::addSortedByWagon(string ticket, string station,
    int train_num,
    int wagon_num,
    int cost,
    int seat,
    int data)
{
    addNode(ticket, station, train_num, wagon_num, cost, seat, data);
    sortedList(1);

}

DoublyLinkedList list;

Data* d = new Data();

list.addNode(d);
list.tail->GetObject()->SetData()
