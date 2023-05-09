#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<functional>
using namespace std;

class Data : ISortableObject
{   
    public:
    string ticket;
    string station;
    int train_num;
    int wagon_num;
    int cost;
    int seat;
    int date;
   virtual bool isSame(Data& other, int choise = 0);
   virtual bool isHigher(Data& other, int choise = 0);
   virtual bool isLower(Data& other,int choise=0); // ������ �����, ����� ����� ���� ������� 0 - date, 1 - wagon
    Data();
    void setData(string ticket,
        string station,
        int train_num,
        int wagon_num,
        int cost,
        int seat,
        int date);
  /*  Data(   string ticket,
            string station,
            int train_num,
            int wagon_num,
            int cost,
            int seat,
            int date);*/
    void printData();

};

class ISortableObject
{
public:
    virtual bool isSame(Data& other, int choise = 0);
    virtual bool isHigher(Data& other, int choise = 0);
    virtual bool isLower(Data& other, int choise = 0);
    virtual void printData();
};

class Node {
public:
    ISortableObject* obj;
    Node* next;
    Node* prev;
    Node();
    Node(ISortableObject* obj);
    ~Node();
    //void setDataToNode(string ticket, string station,
    //    int train_num,
    //    int wagon_num,
    //    int cost,
    //    int seat,
    //    int data);
    /*void deleteNode(int date);*/
    void CloneData();//��� ����� �������, ������� ������� ������, ��� ���� �� �������
    ISortableObject* getObject() { return obj; };
};
    



class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    void cloneNodes(Node* temp, Node* left, Node* right);
public:
    DoublyLinkedList();
    void addNode(ISortableObject*);
    void printList();
    void reversePrintList();
    void deleteNode(function<ISortableObject>obj);
    void sortedList(int inkr=0);
    void addSortedByWagon(string ticket, string station,
        int train_num,
        int wagon_num,
        int cost,
        int seat,
        int data);
    Node* nodeSearch(int val); //������� ���� ������ ���, ����� ������ ����� �� �����, ����� ����� ���� ������� ���������, ���� � � ����� ����� ��� ������ � ������� ��� ����� �� ��������� �� ���������, ���
    void deleteByDate(int data);
    void formNewList(int data);
   

};

        