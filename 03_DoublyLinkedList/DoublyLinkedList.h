#pragma once

#include <iostream>

using namespace std;

// 이중 연결 리스트의 노드 구조체
template <typename T>
struct Node
{
    T data;         // 노드에 저장할 데이터
    Node* prev;     // 이전 노드를 가리키는 포인터
    Node* next;     // 다음 노드를 가리키는 포인터

    // 생성자: 데이터 초기화 및 포인터를 nullptr로 설정
    Node(T val) : data(val), prev(nullptr), next(nullptr)
    {
    }
};

// 이중 연결 리스트 클래스
template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;  // 리스트의 첫 노드
    Node<T>* tail;  // 리스트의 마지막 노드

public:
    // 생성자: head와 tail을 nullptr로 초기화하여 빈 리스트 생성
    DoublyLinkedList() : head(nullptr), tail(nullptr)
    {
    }

    // 소멸자: 모든 노드를 삭제하여 메모리 해제
    ~DoublyLinkedList()
    {
        Node<T>* current = head;            // 순회용 포인터

        while (current != nullptr)          // head가 nullptr가 될 때까지 반복
        {
            Node<T>* temp = current;        // 현재 노드를 임시 저장

            current = current->next;        // 다음 노드로 이동

            delete temp;                    // 저장된 노드 삭제
        }

        head = tail = nullptr;              // head와 tail 초기화
    }

    // 리스트 끝에 노드 추가
    void append(T data)
    {
        Node<T>* newNode = new Node<T>(data);   // 새 노드 생성

        if (head == nullptr)                    // 리스트가 비어있으면
        {
            head = tail = newNode;              // head와 tail을 새 노드로 설정

            return;
        }

        tail->next = newNode;                   // 기존 tail의 next를 새 노드로 연결

        newNode->prev = tail;                   // 새 노드의 prev를 기존 tail로 설정

        tail = newNode;                         // tail을 새 노드로 업데이트
    }

    // 리스트 처음에 노드 추가
    void prepend(T data)
    {
        Node<T>* newNode = new Node<T>(data);   // 새 노드 생성

        if (head == nullptr)                    // 리스트가 비어있으면
        {
            head = tail = newNode;              // head와 tail을 새 노드로 설정

            return;
        }

        newNode->next = head;                   // 새 노드의 next를 기존 head로 설정

        head->prev = newNode;                   // 기존 head의 prev를 새 노드로 설정

        head = newNode;                         // head를 새 노드로 업데이트
    }

    // 특정 값의 노드 삭제
    void deleteNode(T data)
    {
        if (head == nullptr) return;            // 리스트가 비어있으면 종료

        Node<T>* current = head;                // 순회용 포인터

        // 삭제할 노드 탐색
        while (current != nullptr && current->data != data)
            current = current->next;

        if (current == nullptr) return;         // 삭제 대상이 없으면 종료

        if (current == head)                    // head 노드 삭제
        {
            head = head->next;                  // head를 다음 노드로 이동

            if (head != nullptr)
                head->prev = nullptr;           // 새 head의 prev를 nullptr로 설정
            else tail = nullptr;                // 리스트가 비면 tail도 초기화

            delete current;                     // 노드 삭제

            return;
        }

        if (current == tail)                    // tail 노드 삭제
        {
            tail = tail->prev;                  // tail을 이전 노드로 이동

            tail->next = nullptr;               // 새 tail의 next를 nullptr로 설정

            delete current;                     // 노드 삭제

            return;
        }

        // 중간 노드 삭제
        current->prev->next = current->next;    // 이전 노드와 다음 노드 연결
        current->next->prev = current->prev;

        delete current;                         // 노드 삭제
    }

    // 정방향 출력
    void printForward()
    {
        if (head == nullptr)                    // 리스트가 비어있으면
        {
            cout << "List is empty" << endl;

            return;
        }

        Node<T>* current = head;                // 순회용 포인터

        cout << "Forward: ";

        while (current != nullptr)              // 리스트 끝까지 순회
        {
            cout << current->data << " <-> ";   // 현재 노드 데이터 출력

            current = current->next;            // 다음 노드로 이동
        }

        cout << "nullptr" << endl;
    }

    // 역방향 출력
    void printBackward()
    {
        if (tail == nullptr)                    // 리스트가 비어있으면
        {
            cout << "List is empty" << endl;

            return;
        }

        Node<T>* current = tail;                // 순회용 포인터

        cout << "Backward: ";

        while (current != nullptr)              // 리스트 처음까지 순회
        {
            cout << current->data << " <-> ";   // 현재 노드 데이터 출력

            current = current->prev;            // 이전 노드로 이동
        }

        cout << "nullptr" << endl;
    }
};
