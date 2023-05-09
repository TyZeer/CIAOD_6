#include <iostream>
#include <vector>
#include "DoublyLinkedList.h"
#include <string>
using namespace std;

int main() 
{
	DoublyLinkedList list;
	list.addNode("01a4", "Belorusskaya", 1, 5, 123, 5, 201201);
	list.addNode("01a5", "Belorusskaya", 5, 8, 8634, 6, 201119);
	list.addNode("51B5", "Ozernaya", 7, 3, 543, 42, 200816);
	list.addNode("dfg54", "Ozernaya", 7, 11, 547, 54, 201023);
	list.addNode("sodif54", "Yaroslavl", 79, 9, 110, 12, 200916);
	list.printList();
	list.sortedList();
	list.addSortedByWagon("abba12", "Zavod", 90, 1, 12, 34, 200915);

}