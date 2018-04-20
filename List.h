/* 
 * File:   List.h
 * Author: Jeremie Chatillon et James Smith
 *
 * Created on 5. avril 2018, 13:02
 */

#ifndef LIST_H
#define LIST_H
    
#include <cstdlib>
#include <iostream>

/**
 * Struct Element
 * Structure représentant un élément d'une liste
 */
template <typename as>
struct Element{
        as data;        // valeur de l'élément
        Element* prev;  // élément précédent de la liste
        Element* next;  // élément suivant de la liste
        // Constructeur
        Element(as data, Element* prev = nullptr, Element* next = nullptr)
           : data(data), prev(prev), next(next){};  
     
};

template <class T>
class List {
private:
    Element<T>* head; // Tête de la liste
    Element<T>* tail; // Queue de la liste
    
    size_t _size; // Taille de la liste
public:    
    /**
     * class Iterator - interne à List
     * Iterator d'une liste
     * Permet de parcourir la liste
     */
    class Iterator{
        public:
            /**
             * Constructeur par pointeur
             * @param e - pointeur sur l'élément
             * @param list - pointeur sur la liste contenant l'iterator
             */
           Iterator(Element<T>* e, List* list): _ptr(e), _list(list){};
           Iterator(Element<T>& e, List* list): _ptr(*e), _list(list){}; // un des 2 peut être inutil
           
           /**
            * Operator ++ - Va a l'itérateur suivant
            * @return l'itérateur suivant de la liste par référence
            */
           Iterator& operator ++ () {
               _ptr = _ptr->next; 
               return *this;
           }
           
           /**
            * Operator ++ - Va a l'itérateur suivant
            * @return l'itérateur suivant de la liste par copie
            */
           Iterator operator ++ (int) {
               Iterator it(*this);
               _ptr = _ptr->next; 
               return it;
           }
           
           /**
            * Operator -- - Va a l'itérateur précédent
            * @return l'itérateur précédent de la liste par référence
            */
           Iterator& operator -- () {
                if(_ptr == nullptr){
                   _ptr = _list->tail;
                } else {
                    _ptr = _ptr->prev;
                }
                return *this;
           }
           /**
            * Operator -- - Va a l'itérateur précédent
            * @return l'itérateur précédent de la liste par référence
            */
            Iterator operator -- (int) {
                if(_ptr == nullptr){
                    return _list->tail;
                }
                Iterator it(*this);
                _ptr = _ptr->prev;
                return it;
            } 
            
            /**
             * Operator == - operateur d'égalité
             * @param rhs - iterateur de comparaison
             * @return true si les itérateurs sont les même
             */
            bool operator == (const Iterator& rhs) const {
                return _ptr == rhs._ptr;
            }
            
            /**
             * Operator != - operateur d'inégalité
             * @param rhs - iterator de comparaison
             * @return true si les itérateur sont différent
             */
            bool operator != (const Iterator& rhs) const {
                return !(_ptr == rhs._ptr);
            }
            
            /**
             * Operateur *() - operateur de déréférenement
             * @return l'élément pointer par l'itérateur
             */
            T& operator *() const {
                return _ptr->data;
            }
             
            /**
             * Operator + - operateur de déplacement
             * @param i - nombre d'itérateur à aller au suivant
             * @return l'iterator équivalant à it + i
             */
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
            Element<T>* _ptr; // élément pointer par l'itérateur
            List* _list; // list contenant la list
       };
       
public:
    /**
     * Constructeur de List
     */
    List(){
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }
    
    /**
     * Constructeur de List par copie
     * @param orig - List à copier
     */
    List(const List& orig) {
        head = nullptr;
        tail = nullptr;
        _size = 0;
        std::cout << orig << " " << orig._size << std::endl;
        
        for(size_t i = 0; i < orig._size; ++i){
            std::cout << "asdf" << std::endl;
            T value = orig.at(i);
            std::cout << "test1" << std::endl;
            std::cout << value ;
            append(value);
        }
        
    }
    /**
     * Destructeur de la liste
     */
    virtual ~List() {

        while(head != nullptr){
            this->popFront();
        }
    };
    
    /**
     * Insertion à la fin de la List
     * @param o - élément à inserer
     */
    void append(const T& o){
        tail = new Element<T>(o, tail, nullptr);
        
        if(head == nullptr){ // Tête est null
            head = tail;
        } else{
            tail->prev->next = tail;
        } 
        ++_size;
        //std::cout << "append inside: " << head->data << " " <<  tail->data << " " << _size << std::endl;
    }
    
    /**
     * Insertion au début de la List
     * @param o - élément à inserer
     */
    void insert(const T& o){
        head = new Element<T>(o, nullptr, head);

        if(tail == nullptr){ // Tête est null
            tail = head;
        } else{
            head->next->prev = head;
        } 
        ++_size;
    }
    /**
     * at() - accès à un élément de la liste
     * @param pos - position de l'élément
     * @return l'élément à la position pos de la List par référence
     */
    T& at(size_t pos){
        std::cout << "ref " << std::endl;
        if(pos >= _size){
            std::cout << "error" << std::endl; // temp
        }
        
 
        if(_size == 0){
            std::cout << "error" << std::endl;
        }
        
        Element<T>* tmp = head;
        for(size_t i = 0; i < pos; ++i){
            tmp = tmp->next;
        }
        
        return tmp->data;
    };
    
    /**
     * at() - accès à un élément de la liste
     * @param pos - position de l'élément
     * @return l'élément à la position pos de la List par copie
     */
    /*T at(size_t pos) const{
        std::cout << "copy " << std::endl;
        T& value = at(pos);
        return value;
    }*/
    
    
    
    /**
     * Operator[] - opérateur d'accès à un élément de la liste
     * @param pos - position de l'élément
     * @return l'élément à la position pos de la List par référence
     */
    T& operator [] (size_t pos){
        return at(pos);
    }
    
    /**
     * size() - retourne la taille de la liste
     * @return 
     */
    size_t size() const{
        return _size;
    }
    
    /**
     * find(const T& o) - retourne l'index ou se trouve le premier élément dans
     *  la liste
     * @param o - élément rechercher
     * @return l'index de l'élément rechercher. -1 si pas trouvé
     */
    size_t find(const T& o){
        for(size_t i = 0; i < _size; ++i){
            if(at(i) == o)
                return i;
        }
        
        return -1;
    }
    
    /**
     * Surcharge de l'opérateur de flux <<
     */
    friend std::ostream& operator <<(std::ostream& lhs, const List<T>& rhs){
        lhs << "[";
    
        Element<T>* tmp = rhs.head;
        while(tmp != nullptr){
            lhs << tmp->data;
            if(tmp->next != nullptr)
                lhs << ", ";
            tmp = tmp->next;
        }
        lhs << "]";
    
        return lhs;
    };
    
    /**
     * supprime l'élément de tête
     */
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
    
    /**
     * Supprime le dernier élément
     */
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
    /**
     * Suppression de la tête
     */
    void deleteSingle(){
        delete head;
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }
    
    /**
     * Suppression d'un noeud de la liste
     * @param e - élément à supprimer
     */
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
    /**
     * retourne l'itérateur pointant sur le début de la liste
     * @return Iterator - begin 
     */
    Iterator begin(){
        return Iterator(head,this);
    }
    
    /**
     * retourne l'itérateur pointant sur l'élément après la fin de la liste
     * @return 
     */
    Iterator end(){
        return Iterator(nullptr,this);
    }
    

    
};

#endif /* LIST_H */

