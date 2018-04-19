/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: Jeremie
 *
 * Created on 5. avril 2018, 13:02
 */

#ifndef LIST_H
#define LIST_H
    
#include <cstdlib>
#include <iostream>

template <typename as>
struct Element{
        as data;
        Element* prev;
        Element* next;
        Element(as data, Element* prev = nullptr, Element* next = nullptr)
           : data(data), prev(prev), next(next){};  
     
};

template <class T>
class List {
private:
    Element<T>* head;
    Element<T>* tail;
    
    size_t _size;
public:    
    class Iterator{
        public:
           Iterator(): _ptr(nullptr){};
           Iterator(Element<T>* e): _ptr(e){};
           Iterator(Element<T>& e): _ptr(*e){}; // un des 2 peut être inutil
           
           Iterator& operator ++ () {
               _ptr = _ptr->next; 
               return *this;
           }
           Iterator operator ++ (int) {
               Iterator it(*this);
               _ptr = _ptr->next; 
               return it;
           }
           Iterator& operator -- () {
               _ptr = _ptr->prev;
                return *this;
           }
            Iterator operator -- (int) {
                Iterator it(*this);
                _ptr = _ptr->prev;
                return it;
            } 
            
            
            bool operator == (const Iterator& rhs) const {
                return _ptr == rhs._ptr;
            }
            bool operator != (const Iterator& rhs) const {
                return !(_ptr == rhs._ptr);
            }
            
             T& operator *() const {
                 return _ptr->data;
             }
             
             Iterator operator + (size_t i)
            {
                Iterator it = *this;
                while (i-- > 0 && it._ptr)
                {
                    ++(it);
                }
                return it;
            }
             
        private:
            Element<T>* _ptr;
       };
       
public:
    List(){
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }
    List(const List& orig);
    virtual ~List() {

        while(head != nullptr){
            this->popFront();
        }
    };
    
    void append(const T& o){
        tail = new Element<T>(o, tail, nullptr);

        if(head == nullptr){ // Tête est null
            head = tail;
        } else{
            tail->prev->next = tail;
        } 
        ++_size;
    }
    
    void insert(const T& o){
        head = new Element<T>(o, nullptr, head);

        if(tail == nullptr){ // Tête est null
            tail = head;
        } else{
            head->next->prev = head;
        } 
        ++_size;
    }
    
    T at(size_t pos) const{
        return at(pos);
    }
    
    const T& at(size_t pos){
        if(pos >= _size);
            // Throw error
 
        if(_size == 0);
            // Throw error
        
        Element<T>* tmp = head;
        for(size_t i = 0; i < pos; ++i){
            tmp = tmp->next;
        }
        
        return tmp->data;
    };
    
    T& operator [] (size_t pos){
        return at(pos);
    }
    
    size_t size() const{
        return _size;
    }
    
    
    size_t find(const T& o){
        for(size_t i = 0; i < size; ++i){
            if(at(i) == o)
                return i;
        }
        
        return -1;
    }
    
    friend std::ostream& operator <<(std::ostream& lhs, const List<T>& rhs){
        lhs << "\nList : ";
    
        Element<T>* tmp = rhs.head;
        while(tmp != nullptr){
            lhs << tmp->data;
            tmp = tmp->next;
        }
    
        return lhs;
    };
     
    void popFront(){
        if(!_size){
            // Lancer erreur
        }
        if(_size == 1){
            deleteSingle();
        } else{
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            --_size;
        }
    }
    
    void popBack(){
        if(!size){
            // Lancer erreur
        }
        if(size == 1){
            deleteSingle();
        } else{
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;  
            --_size;
        }       
    }
private:
    void deleteSingle(){
        delete head;
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }
    void removeNode(Element<T>& e){
        if(*e == head){
            popFront();
        } else if(*e == tail){
            popBack();
        } else{
            e->prev->next = e->next;
            e->next->prev = e->prev;
            delete e;
             --_size;
        }
    }

    public:
    Iterator begin(){
        return Iterator(head);
    }
    
    Iterator end(){
        return Iterator(begin() + size());
    }
    

    
};

#endif /* LIST_H */

