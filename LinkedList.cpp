#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next = NULL;

    Node(T value) : data(value) {}
};

template <typename T>
struct LinkedList {
	Node<T>* head = new Node<T>(T());
	Node<T>* getLastNode() {
		Node<T>* current = head;
		while (current->next) {
			current = current->next;
		}
		return current;
	}
	void push_end(T value) {
		Node<T>* newNode = new Node<T>(value);
		
		this->getLastNode()->next = newNode;
	}
	void push_start(T value) {
		Node<T>* newNode = new Node<T>(value);
				
		newNode->next = head->next;
		head->next = newNode;
	}
	void pop_end() {
		if (!head->next) {return;}
		
		Node<T>* current = head;
		while (current->next->next) {
			current = current->next;
		}
		
		delete current->next;
		current->next = NULL;
	}
	Node<T>* get(int index) {
		if (!head->next) {return NULL;}
		Node<T>* current = head->next;
		
		int i = 1;
		while (i <= index) {
			if (!current->next) {return NULL;}
			
			current = current->next;
			
			i++;
		}
		
		return current;
	}
	void pop_start() {
		if (!head->next) {return;}
		
		head->next = head->next->next;
	}
	void push(T value, int index) {
		Node<T>* current = get(index);
		if (!current){
			return;
		}
		
		Node<T>* old_next = current->next;
		current->next = new Node<T>(value);
		current->next->next = old_next;
	}
	void pop(int index) {
		Node<T>* current = get(index);
		Node<T>* next = current->next->next;
		delete current->next;
		current->next = next;
	}
	void print() {
		if (!head->next) {
			std::cout << "[]";
			return;
		}
		
		Node<T>* current = head->next;
		
		std::cout << "[";
		while (current->next) {
			std::cout << current->data << ", ";
			
			current = current->next;
		}
		std::cout << current->data << "]\n";
	}
	int size() {
		if (!head->next) {return 0;}
		int n = 0;
		
		Node<T>* current = head;
		while (current->next) {
			current = current->next;
			++n;
		}
	
		return n;
	}
	~LinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
	LinkedList<int> list;
	
	list.push_end(1);
	list.push_end(2);
	list.push_end(3);
	list.push(1, 5);
	list.print();
	
    return 0;
}

