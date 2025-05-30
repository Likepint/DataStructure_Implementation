﻿#pragma once

#include <iostream>

using namespace std;

// 이중 환형 연결 리스트의 노드 구조체
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

// 이중 환형 연결 리스트 클래스
template <typename T>
class DoublyCircularLinkedList
{
private:
    Node<T>* head;  // 리스트의 첫 노드 (순환의 시작점)

public:
    // 생성자: head를 nullptr로 초기화하여 빈 리스트 생성
    DoublyCircularLinkedList() : head(nullptr)
    {
    }

    // 소멸자: 모든 노드를 삭제하여 메모리 해제
    ~DoublyCircularLinkedList()
    {
        if (head == nullptr) return;            // 리스트가 비어있으면 종료

        Node<T>* current = head->next;          // 두 번째 노드부터 시작

        while (current != head)                 // head로 돌아올 때까지 반복
        {
            Node<T>* temp = current;            // 현재 노드를 임시 저장

            current = current->next;            // 다음 노드로 이동

            delete temp;                        // 저장된 노드 삭제
        }

        delete head;                            // 마지막으로 head 삭제

        head = nullptr;                         // head 초기화
    }

    // 리스트 끝에 노드 추가
    void append(T data)
    {
        Node<T>* newNode = new Node<T>(data);   // 새 노드 생성

        if (head == nullptr)                    // 리스트가 비어있으면
        {
            head = newNode;                     // head를 새 노드로 설정

            head->next = head;                  // next를 자신으로 연결

            head->prev = head;                  // prev를 자신으로 연결

            return;
        }

        Node<T>* tail = head->prev;             // 현재 tail (head의 prev)

        tail->next = newNode;                   // tail의 next를 새 노드로 연결

        newNode->prev = tail;                   // 새 노드의 prev를 tail로 설정

        newNode->next = head;                   // 새 노드의 next를 head로 설정

        head->prev = newNode;                   // head의 prev를 새 노드로 설정
    }

    // 리스트 처음에 노드 추가
    void prepend(T data)
    {
        Node<T>* newNode = new Node<T>(data);   // 새 노드 생성

        if (head == nullptr)                    // 리스트가 비어있으면
        {
            head = newNode;                     // head를 새 노드로 설정

            head->next = head;                  // next를 자신으로 연결

            head->prev = head;                  // prev를 자신으로 연결

            return;
        }

        Node<T>* tail = head->prev;             // 현재 tail (head의 prev)

        newNode->next = head;                   // 새 노드의 next를 기존 head로 설정

        newNode->prev = tail;                   // 새 노드의 prev를 tail로 설정

        tail->next = newNode;                   // tail의 next를 새 노드로 설정

        head->prev = newNode;                   // 기존 head의 prev를 새 노드로 설정

        head = newNode;                         // head를 새 노드로 업데이트
    }

    // 특정 값의 노드 삭제
    void deleteNode(T data)
    {
        if (head == nullptr) return;            // 리스트가 비어있으면 종료

        Node<T>* current = head;                // 순회용 포인터

        // 단일 노드일 경우
        if (head->data == data && head->next == head)
        {
            delete head;                        // head 삭제

            head = nullptr;                     // head 초기화

            return;
        }

        // 삭제할 노드 탐색
        do
        {
            if (current->data == data) break;   // 삭제 대상 찾으면 중단

            current = current->next;
        } while (current != head);

        if (current->data != data) return;      // 값이 없으면 종료

        if (current == head)                    // head 노드 삭제
        {
            Node<T>* tail = head->prev;         // 현재 tail

            head = head->next;                  // head를 다음 노드로 이동

            tail->next = head;                  // tail의 next를 새 head로 연결

            head->prev = tail;                  // 새 head의 prev를 tail로 연결

            delete current;                     // 삭제

            return;
        }

        // 중간 또는 tail 노드 삭제
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

        cout << "Forward Circular List: ";

        do
        {
            cout << current->data << " <-> ";   // 현재 노드 데이터 출력

            current = current->next;            // 다음 노드로 이동
        } while (current != head);              // head로 돌아오면 종료

        cout << "(head)" << endl;
    }

    // 역방향 출력
    void printBackward()
    {
        if (head == nullptr)                    // 리스트가 비어있으면
        {
            cout << "List is empty" << endl;

            return;
        }

        Node<T>* current = head->prev;          // tail부터 시작 (head의 prev)

        cout << "Backward Circular List: ";

        do
        {
            cout << current->data << " <-> ";   // 현재 노드 데이터 출력

            current = current->prev;            // 이전 노드로 이동
        } while (current != head->prev);        // tail로 돌아오면 종료

        cout << "(tail)" << endl;
    }
};
