#include <iostream>
#include "colors.h"
#include <cstdlib>

void clear() {
    system("clear || cls"); // "clear" for unix-like systems, "cls" is for windows
}

class Node{
public:
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {top = nullptr;} // constructor, gets called when an object is created
    //?isEmpty, peek, display
    void push(int valueToPush) {
        Node* newNode = new Node(valueToPush);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if(top == nullptr) {
            std::cout << "The stack is empty; nothing to pop." << std::endl;
            return;
        }
        Node* valueToDelete = top;
        top = top->next;
        delete valueToDelete;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void peek() {
        if(top == nullptr) {
            std::cout << "nullptr (stack's empty)" << std::endl;
            return;
        }
        std::cout << top->data << std::endl;
    }
    void display() {
        Node* temp = top;
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    bool exit = false;
    Stack s;
    do{
        clear();
        int user_option;
        std::cout << "Welcome to SH (Stack Handler)!" << std::endl;
        std::cout << "!!! THIS C++ PROJECT WAS CONSTRUCTED PURELY FOR PRACTICE, NOTHING MORE !!!" << std::endl;
        std::cout << "1. Push Value" << std::endl;
        std::cout << "2. Pop Value" << std::endl;
        std::cout << "3. Check if empty" << std::endl;
        std::cout << "4. Check top value" << std::endl;
        std::cout << "5. A Little About Stacks" << std::endl;
        std::cout << "6. LET ME OUT (quit)" << std::endl;
        std::cout << red << "Your stack currently: " << reset_color;
        s.display();
        std::cin >> user_option;
        
        switch(user_option) {
            case 1:
                int valueToPush;
                std::cout << "Amazing! What value do you want to push to the stack? " << blue;
                std::cin >> valueToPush;
                s.push(valueToPush);
                std::cout << reset_color;
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(s.isEmpty()) {
                    std::cout << "Your stack is empty. Press ENTER to proceed." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore(); 
                } else {
                    std::cout << "Your stack is not empty. Press ENTER to proceed." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                }
                break;
            case 4:
                std::cout << "top value: ";
                s.peek();
                std::cout << "*press ENTER to proceed*" << std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            case 5:
                std::cout << "Stacks have a similar structure to linked lists -- both has a 'main node', like linked list's 'head' and stack's 'top'." << std::endl;
                std::cout << "In stacks, you can only interact with the top. Just like in real life. If you stack multiple stuff on each other, you'll realise that" << std::endl;
                std::cout << "You can only take from the TOP comfortably." << std::endl;
                std::cout << "Press ENTER to proceed" << std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            case 6:
                std::exit(0);
        }
    }while(!exit);

    return 0;
}