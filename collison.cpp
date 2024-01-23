#include<iostream>
using namespace std;
const int size = 5;
class Node{
    public:
    Node *next;
    int data;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};  

class hashed{
    public:

    //array of link list
    Node* chain[5];

    void initialise(){
        for(int i=0;i<5;i++){
            chain[i] = nullptr;
        }
    }

    void insert(int val){
        int key = val%5;
        Node *temp = new Node(val);
        if(chain[key] == nullptr){
            chain[key] = temp;
        }
        else if(chain[key] != nullptr){
            //means collision occuring
            Node *newnode = chain[key];
            while(newnode->next != NULL){
                newnode = newnode->next;
            }
            newnode->next = temp;
        }
    }

    void display() {
        for (int i = 0; i < 5; i++) {
            Node* current = chain[i];
            while (current != nullptr) {
                cout<<current->data;
                if(current->next != nullptr){
                    cout<<"-->";
                }
                else{
                    cout<<"-->NULL";
                }
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main(){
    hashed h;
    h.initialise();
    h.insert(89);
    h.insert(74);
    h.insert(52);
    h.insert(9);
    h.insert(23);
    h.display();
}