/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.cpp
 * Author: Jeremie
 * 
 * Created on 5. avril 2018, 13:02
 */

#include "List.h"
/*
template<class T>
List<T>::List(){
    head = nullptr;
    tail = nullptr;
    _size = 0;
}
*/

template<class T>
List<T>::List(const List& orig) {
    if(head == nullptr){
        head = nullptr;
        tail = nullptr;
        _size = 0;
    } else{
        for(size_t i = 0; i < orig.size; ++i){
            append(orig.at(i));
        }
    }
}
/*
template<class T>
size_t List<T>::size() const{
    return _size;
}

/*
template<class T>
void List<T>::append(const T& o){
    tail = new Element<T>(o, tail, nullptr);
    
    if(head == nullptr){ // Tête est null
        head = tail;
    } else{
        tail->prev->next = tail;
    } 
}
*/

/*
template<class T>
std::ostream& operator << (std::ostream& lhs, const List<T>& rhs){
    lhs << "size : ";
    /*
    for(size_t i = 0; i < rhs.size(); ++i){
        lhs << rhs.at(i);
    }
     
    
    return lhs;
}
*/