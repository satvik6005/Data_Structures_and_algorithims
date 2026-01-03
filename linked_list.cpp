
#include <iostream>

using namespace std;

class Node {
  int data;
  Node * next = NULL;

  public:
    int get_data() {
      return this -> data;
    }
  Node * get_next() {
    return this -> next;
  }
  void set_next(Node * next) {
    this -> next = next;
  }
  void set_data(int data) {
    this -> data = data;
  }

};


class LinkedList {
  Node * head = NULL;
  Node * tail = NULL;
  public:
    void add_data(int data) {
      if (tail == NULL) {
        tail = new Node();
        tail -> set_data(data);
        head = tail;
        return;

      }
      if (!check_duplicate(data)) {
        Node * new_node = new Node();
        tail -> set_next(new_node);
        tail = new_node;
        tail -> set_data(data);
        return;
      }
      cout << "canot add duplicate" << "\n";

    }
  bool check_duplicate(int data) {
    Node * traverse = head;
    while (traverse != NULL) {
      if (traverse -> get_data() == data)
        return true;
      traverse = traverse -> get_next();
    }
    return false;
  }
  void remove_data(int data) {
    if (head == NULL) {
      cout << "underflow" << "\n";
      return;
    }
    if (head -> get_next() == NULL && head -> get_data() == data) {
      head = NULL;
      tail = NULL;
      return;

    }

    Node * previous = new Node();
    Node * traverse = new Node();
    traverse = head;
    while (traverse != NULL) {
      if (traverse -> get_data() == data && traverse == head) {
        head = traverse -> get_next();
        delete traverse;
        return;
      } else if (traverse -> get_data() == data && traverse == tail) {
        previous -> set_next(traverse -> get_next());
        tail = previous;
        delete traverse;
        return;
      } else if (traverse -> get_data() == data) {
        previous -> set_next(traverse -> get_next());
        delete traverse;
        return;
      }
        previous = traverse;
        traverse = traverse -> get_next();
      }
    }

    cout << "Not Found" << "\n";

  }
  void display() {
    Node * traverse = head;
    while (traverse != NULL) {
      cout << traverse -> get_data() << "\n";
      traverse = traverse -> get_next();
    }
  }

};


int main() {
  int choice, data;
  LinkedList list;
  while (choice != 4) {
    cout << "enter 1 to display 2 to add value 3 to remove 4 to exit" << "\n";
    cin >> choice;
    switch (choice) {
    case 1:
      list.display();
      break;
    case 2:
      cout << "enter the value" << "\n";
      cin >> data;
      list.add_data(data);
      break;
    case 3:
      cout << "enter the value" << "\n";
      cin >> data;
      list.remove_data(data);
      break;
    case 4:
      cout << "thanks bbye";
      break;
    default:
      cout << "wrong choice choose again" << "\n";
      break;

    }
  }

  return 0;
}

