#include <iostream>

using namespace std;

// Node 구조체 정의
// - 데이터를 저장하고, 이전 노드를 가리키는 연결 구조
template <typename T>
struct Node
{
    T data;           // - 노드에 저장될 값
    Node* next;       // - 아래쪽(이전)의 노드를 가리킴

    Node(T val) : data(val), next(nullptr) {}
};

// Stack 클래스 정의
// - Node를 기반으로 동작하는 스택 자료구조
template <typename T>
class MyStack
{
private:
    Node<T>* topNode; // - 스택의 최상단 노드를 가리키는 포인터
    int count;        // - 스택에 저장된 요소 수

public:
    // 생성자
    // - 초기화 시 top은 nullptr, 요소 개수는 0
    MyStack()
        : topNode(nullptr), count(0)
    {
    }

    // 소멸자
    // - 남아 있는 모든 노드를 삭제하여 메모리 누수 방지
    ~MyStack()
    {
        while (!empty())
            pop();
    }

    // 요소 추가 (push)
    // - 새 노드를 만들어 현재 top 위에 쌓는다
    void push(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        newNode->next = topNode;

        topNode = newNode;

        count++;
    }

    // 요소 제거 (pop)
    // - 최상단 노드를 삭제하고 다음 노드로 이동
    void pop()
    {
        if (empty())
            return;

        Node<T>* temp = topNode;

        topNode = topNode->next;

        delete temp;

        count--;
    }

    // 최상단 요소 반환
    // - 스택이 비어 있을 경우 예외 발생
    T top() const
    {
        if (empty())
            throw runtime_error("Stack is empty!");

        return topNode->data;
    }

    // 스택이 비었는지 확인
    bool empty() const
    {
        return count == 0;
    }

    // 스택의 요소 개수 반환
    int size() const
    {
        return count;
    }
};