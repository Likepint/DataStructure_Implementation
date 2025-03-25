#include "SinglyLinkedList.h"

int main()
{
    // 단일 연결 리스트 테스트
    cout << "Singly Linked List:" << endl;

    SinglyLinkedList<int> sList;

    sList.append(1);
    sList.append(2);
    sList.prepend(0);
    sList.printList();  // 0 -> 1 -> 2 -> nullptr

    sList.deleteNode(1);
    sList.printList();  // 0 -> 2 -> nullptr

    return 0;
}
