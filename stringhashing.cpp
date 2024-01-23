#include<iostream> 
using namespace std;

class Node{
    public:
    string key;
    Node *next;

    Node(string key){
        this->key = key;
        next = NULL;
    }
};

class hashed{
    public:
    int hashtablesize;

    Node **table;

    hashed(int hashtablesize){
        this->hashtablesize = hashtablesize;
        table = new Node*[hashtablesize];
        for(int i=0;i<hashtablesize ;i++){
            table[i] = nullptr;
        }
    }

    void insert(const string &key){
        int val = hashfunction(key);
        Node *tempnode = new Node(key);

        if(table[val] == nullptr){
            table[val] = tempnode;
        }
        else if(table[val] != nullptr){
                Node *current = table[val];
                while(current->next != NULL){
                    current = current->next;
                }
                current->next = tempnode;
        }
    }

    int hashfunction(const string &key){
        int length = key.size();
        int hash = 0;
        for(int i=0;i<length;i++){
            hash +=key[i];
        }
        return hash%hashtablesize;
    }

    void display(){
        for(int i=0;i<hashtablesize ;i++){
            Node *temp = table[i];
            while(temp != nullptr){
                cout<<temp->key;
                if(temp->next != nullptr){
                    cout<<"-->";
                }
                else{
                    cout<<"-->NULL";
                }
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    hashed h(10);
    h.insert("ali");
    h.insert("bilal");
    h.insert("amna");
    h.insert("tayyib");
    h.insert("minar");
    h.insert("shaheer");
    h.insert("hassan");
    h.insert("taha");
    h.insert("bilal");
    h.insert("ail");
    h.display();
}