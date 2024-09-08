#include "Node.h"

Node::Node(){
    this->data = 0;
    this->link = nullptr;
}

Node::Node(int data){
    this->data = data;
    this->link = nullptr;
}

void Node::addLink(Node* node){
    this->link = node;
}

Node* Node::getNext(){
    return link;
}

int Node::getData(){
    return data;
}
void Node::setData(int data){
    this->data=data;
}