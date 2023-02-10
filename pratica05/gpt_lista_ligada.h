/*
 * gpt_lista_ligada.h
 *
 *  Created on: 18 de jan. de 2023
 *      Author: acfer
 */

#ifndef GPT_LISTA_LIGADA_H_
#define GPT_LISTA_LIGADA_H_

#include<iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T data) : data(data), next(nullptr) {}
    };
    Node* head;
    int size;
    int maxSize;

public:
    LinkedList(int maxSize) : head(nullptr), size(0), maxSize(maxSize) {}

    ~LinkedList() {
        clear();
    }

    int tamanho() {
        return size;
    }

    void adiciona(T data) {
        if (size == maxSize) {
            throw "Lista cheia";
        }
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pega(int index) {
        if (index < 1 || index > size) {
            throw "Indice invalido";
        }
        Node* current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void remove(T data) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->data == data) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                size--;
                return;
            }
            previous = current;
            current = current->next;
        }
        throw "Elemento nao encontrado";
    }

    void insere(int index, T data) {
        if (index < 1 || index > size + 1) {
            throw "Indice invalido";
        }
        Node* newNode = new Node(data);
        if (index == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    void exibe() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " :  ";
            current = current->next;
        }
        cout << endl;
    }

};



#endif /* GPT_LISTA_LIGADA_H_ */
