#include "LinkedList.h"
#include "Node.h"
#include<iostream>
#include<limits>

LinkedList::LinkedList(){
    head = nullptr;
};
LinkedList::LinkedList(int* array, int len){
    head = new Node(array[0]);
    Node* curr = head;
    for(int i = 1; i < len; i++){
        Node* addedNode = new Node(array[i]);
        curr->addLink(addedNode);
        curr = curr->getNext();
    }
    curr->addLink(nullptr);
};
LinkedList::~LinkedList(){
    Node* curr = head;
    while(curr){
        Node* nxt = head->getNext();
        delete curr;
        curr = nxt;
    }
};
void LinkedList::insertPosition(int pos, int newNum){
    Node* insertedNode = new Node(newNum);
    if(pos<=1||!head){
        insertedNode->addLink(head);
        head = insertedNode;
    } else {
        Node* prev = head;
        for(int i = 2; i<pos; i++){
            if(prev->getNext() == nullptr){
                prev->addLink(insertedNode);
                // std::cout<<"end node";
                return;
            }else{
                // std::cout<<"i: "<<i<<" ";
                prev = prev->getNext();
                // std::cout<<"prev: "<<prev->getData()<<std::endl;
            }
        }
        // std::cout<<"prev: "<<prev->getData();
        insertedNode->addLink(prev->getNext());
        prev->addLink(insertedNode);
    }
};
bool LinkedList::deletePosition(int pos){
    if(pos<1) return false;
    if(pos==1&&head){
        head=head->getNext();
        return true;
    }
    Node* prev = head;
    for(int i = 2; i<pos; i++){
        if(prev->getNext() == nullptr){
            return false;
        }else{
            // std::cout<<"i: "<<i<<" ";
            prev = prev->getNext();
            // std::cout<<"prev: "<<prev->getData()<<std::endl;
        }
    }
    if(!prev->getNext()) return false;
    prev->addLink(prev->getNext()->getNext());
    return true;
};
int LinkedList::get(int pos){
    if(pos<1) return std::numeric_limits<int>::max();
    Node* prev = head;
    for(int i = 1; i<pos; i++){
        if(prev->getNext() == nullptr){
            return std::numeric_limits<int>::max();
        }else{
            // std::cout<<"i: "<<i<<" ";
            prev = prev->getNext();
            // std::cout<<"prev: "<<prev->getData()<<std::endl;
        }
    }
    return prev->getData();
};
int LinkedList::search(int target){
    Node* curr = head;
    int idx = 1;
    while(curr){
        if(curr->getData()==target) return idx;
        idx++;
        curr=curr->getNext();
    }
    return -1;
};
void LinkedList::printList(){
    Node* curr = head;
    bool print = false;
    if(head) print = true;
    if(print) std::cout<<"[";
    while(curr){
        std::cout<<curr->getData()<<" ";
        curr = curr->getNext();
    }
    if(print) std::cout<<"]"<<std::endl;
};