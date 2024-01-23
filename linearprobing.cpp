#include<iostream>
using namespace std;

class hashed{
    public:

    int hashcode(int key){
        return key%10;
    }

    int probe(int H[] , int key , int size){
        int index = hashcode(key);
        int i=0;
        while((H[(index+i)%size]) != 0){
            i++;
        }
        return (index+i)%size;
    }

    void insertion(int H[] , int size , int key){
        int index = hashcode(key);

        if(H[index] == 0){
            H[index] = key;
        }
        else if(H[index] != 0){
            int getnestindex = probe(H,key,size);
            H[getnestindex]=key;
        }
    }

    int searchvalue(int H[] , int key){
        int val = hashcode(key);
        int i=0;
        while(H[(val+i)%10] != key){
            i++;
        } 
        return (val+i)%10;
    }

    void display(int H[] , int size){
        for(int i=0;i<size;i++){
            cout<<H[i]<<" ";
        }
    }
};

int main(){
    hashed h;
    int H[10] = {0};
    h.insertion(H,10,5);
    h.insertion(H,10,67);
    h.insertion(H,10,53);
    h.insertion(H,10,32);
    h.insertion(H,10,10);
    h.insertion(H,10,89);
    h.insertion(H,10,55);
    h.insertion(H,10,63);
    h.display(H,10);
    cout<<endl;
    int val = h.searchvalue(H,55);
    cout<<"Value at index: "<<val;
}