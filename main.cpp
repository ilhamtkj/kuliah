#include <iostream>
#include <string>
using namespace std;

bool pilihan(string kata);  // prototype

class node
{
private:
    string data;
    node * next;
public:
    // kosntruktor
    node(string data, node *next = nullptr){
        this->data = data;
        this->next = next;
    }

    string getData(){return this->data;}
    node *getNext(){return this->next;}
    void setNext(node * next){this->next = next;}
};
typedef node* Node;

class linkedList
{
private:
    Node head;

public:
    // konstruktor
    linkedList(){
        this->head = nullptr;
    }

    // menambah node
    void insertNode(string data){
        string marker;
        Node current = head;

        if (this->head == nullptr)
        {
            this->head = new node(data);
        }
        else
        {
            cout << "Node selanjutnya : " << data << endl;
            if (pilihan("apakah kamu ingin menambah node di  depan ?"))
            {
                Node newNode = new node(data, this->head);
                this->head = newNode;
            }
            else
            {
                cout << "kamu akan menambahkan " << data << " setelah node : ";
                // cin >> marker;
                getline(cin, marker);
                while (current->getData() != marker)
                {
                    current = current->getNext();
                    if (current == nullptr)
                    {
                        cout << "\nGAGAL!!! menambahkan node, input kamu tidak valid" << endl;
                        return;
                    }
                    
                }
                Node newNode = new node(data, current->getNext());
                current->setNext(newNode);
                
            }
            
        }
        
    }

    // menampilkan/print node
    void printNode(){
        int counter = 0;
        cout << "isi node : ";
        Node current = this->head;
        while (current != nullptr)
        {
            cout << "| " << current << " " << current->getData() << " ";
            current = current->getNext();
            counter++;
        }
        cout << "\n" << "Jumlah node : " << counter << "\n\n";
        
    }

    // menghapus node
    void deleteNode(){
        if (pilihan("apakah ingin menghapus semua node ?"))
        {
            freeMemory();
            return;
        }
        else
        {
            cout << "Node yang akan dihapus : ";
            string delKey;
            getline(cin, delKey);
            Node current = this->head;
            Node before = nullptr;
            while (current->getData() != delKey)
            {
                before = current;
                current = current->getNext();
                if (current == nullptr)
                {
                    cout << "\nGAGAL!!! menghapus node, input kamu tidak valid" << endl;
                    return;
                }
                
            }
            if (before == nullptr)
            {
                Node temp = head;
                head = head->getNext();
                delete temp;
            }
            else
            {
                Node temp = current;
                before->setNext(current->getNext());
                delete temp;
            }
            
        }
        
    }

    // menghapus semua node
    void freeMemory(){
        Node temp = nullptr;
        while (head)
        {
            temp = head;
            head = head->getNext();
            delete temp;
        }
        
    }

    // destruktor
    ~linkedList(){
        freeMemory();
    }
};

// main program
int main(){
    cout << "linked list dengan oop" << endl;

    linkedList mylist;
    mylist.insertNode("eco1");
    mylist.printNode();

    mylist.insertNode("eco2");
    mylist.printNode();
    mylist.insertNode("eco3");
    mylist.printNode();

    mylist.deleteNode();

    mylist.insertNode("eks2");
    mylist.printNode();
    mylist.insertNode("eks1");
    mylist.printNode();

    // if (pilihan("apakah kamu ingin delete node ?"))
    // {
    //     mylist.deleteNode();
    //     mylist.printNode();
    // }
    // else
    // {
    //     cout << endl;
    //     mylist.printNode();
    // }
    
    return 0;
}

bool pilihan(string kata){
    char pilihan;
    while (true)
    {
        cout << kata << "pilih (y/n) ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 'y' || pilihan == 'Y')
        {
            return true;
        }
        else if (pilihan == 'n' || pilihan == 'N')
        {
            return false;
        } else
        {
            cout << "masukan pilihan yang sesuai" << endl;
        }
    }
}