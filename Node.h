#pragma once
class Node {
private:
    int data;
    Node* link;
public:
    Node();
    Node(int data);
    void addLink(Node* node);
    Node* getNext();
    int getData();
    void setData(int data);
};