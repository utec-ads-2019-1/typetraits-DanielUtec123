#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        List() : head(nullptr) {};

        bool find(T search, Node<T> *pointer) {
            if(this->head){
                    Node<T>* temp = pointer;
                    while (temp){
                            if(temp->data == search){
                                    return true;
                            }
                            temp = temp->next;
                    }
            }
            return false;
        }
             
        bool insert(T data) {
                if(this->head){
                        if(!find(data,this->head)){
                                Node<T>* temp = this->head;
                                Node<T>* nuevo = new Node<T>(data);
                                while (temp){

                                        if(cmp(data,temp->data)){

                                                if(temp->prev){
                                                        nuevo->next = temp;
                                                        nuevo->prev = temp->prev;
                                                        temp->prev->next = nuevo;
                                                        temp->prev = nuevo;
                                                        break;
                                                } else{
                                                        nuevo->next=temp;
                                                        temp->prev = nuevo;
                                                }

                                                break;

                                        }

                                        if(temp->next== nullptr){
                                                break;
                                        }

                                        temp = temp->next;
                                }
                                temp->next = nuevo;
                                nuevo->prev = temp;









                        } else{
                                return false;
                        }

                } else{
                        this->head =new Node<T>(data);
                }
                return true;




        }
             
        bool remove(T item) {
                if(this->head){
                        Node<T>* temp = this->head;
                        while (temp){
                                if(temp->data == item){

                                        if(temp->next){ // si hay next
                                                if(temp->prev){//si hay prev
                                                        temp->prev->next = temp->next;
                                                        temp->next->prev = temp->prev;
                                                        delete temp;

                                                } else{// si no hay prev entonces temp es head

                                                        this->head = temp->next;
                                                        this->head->prev = nullptr;
                                                        delete temp;

                                                }


                                        } else{//si no hay next
                                                if(temp->prev){ //hay prev

                                                        temp->prev->next = nullptr;
                                                        delete temp;
                                                } else{//no hay prev
                                                        this->head = nullptr;
                                                        delete temp;
                                                }



                                        }




                                        return true;
                                }
                                temp = temp->next;
                        }
                }
                return false;

        }  
             
        int size() {
            if(this->head){
                    Node<T>* temp = this->head;
                    int i = 0;
                    while (temp){
                            i++;
                            temp = temp->next;
                    }
                    return i ;

            }
            return 0;
        }

        T operator[](int index) {
                        if(this->head){
                                if(index > size()-1)
                                        throw out_of_range("indice mayor al numero de elementos");


                                Node<T>* temp = this->head;
                                for (int i = 0 ; i<index;i++){
                                       temp = temp->next;
                                }
                                return temp->data;




                        }
                        throw out_of_range("la lista no tiene elementos");




        }

        ~List() {
            // TODO
        }         
};

#endif