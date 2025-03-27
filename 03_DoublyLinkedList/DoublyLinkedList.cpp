#include "DoublyLinkedList.h"

// 테스트 코드
int main()
{
    DoublyLinkedList<int> list;

    // 노드 추가
    list.append(1);     // 1
    list.append(2);     // 1 <-> 2
    list.prepend(0);    // 0 <-> 1 <-> 2
    list.append(3);     // 0 <-> 1 <-> 2 <-> 3
    list.printForward();    // 정방향 출력
    list.printBackward();   // 역방향 출력

    // 노드 삭제
    list.deleteNode(1);     // 0 <-> 2 <-> 3
    list.printForward();    // 정방향 출력
    list.printBackward();   // 역방향 출력

    return 0;
}
