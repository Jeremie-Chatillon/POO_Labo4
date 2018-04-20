/* 
 * File:   main.cpp
 * Author: Jeremie Chatillon et James Smith
 *
 * Created on 5. avril 2018, 13:02
 */

#include <cstdlib>

#include "List.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Test empty constructor
    List<int> list;
    cout << "constructeur vide: " << list << endl;
    
    // Test append
    list.append(1);
    list.append(2);
    cout << "append: " << list << endl;
    
    // Test constructeur de copie
    /*List<int> list2(list);
    cout << "Constructeur copy " << list2 << endl;*/
    List<string> list_;
    list_.append("hello");
    list_.append("test");
    list_.append("asdf");
    
    cout << "string list init " << list_ << endl;
    string& s = list_.at(1);
    s = "qwertzuio";
    cout << "string " << s << endl;
    cout << "string list " << list_ << endl;
    
    /*List<string> asdf(list_);
    cout << asdf << endl;*/
    
    // Test insert
    list.insert(3);
    cout << "insert(3): " << list << endl;
    
    // Test at
    /*const int i = list.at(0);
    cout << "at(0) copy " << i << endl;
    cout << "at(0) ref " << list.at(0) << endl;
    cout << "at(1) ref " << list.at(1) << endl;*/
    //cout << "at(10) " << list.at(10) << endl;
    //cout << "at(-1) " << list.at(-1) << endl;
    
    // Test insert to at
    /*list.at(1) = 10;
    cout << "at(1) = 10 " << list << endl;*/
    
    // Test [] opérator
    //cout << "list[1]" << list[1] << endl;
    //cout << "list[10]" << list[10] << endl;
    
    // Test insert to []
    // list[1] = 50;
    //cout << "list[1] = 50" << list << endl;
    
    // Test size
    cout << "size: " << list.size() << " " << list << endl;
    
    // Test find
    //cout << "list: " << list << " find(2)" << list.find(2) << endl;
    //cout << "list: " << list << " find(100)" << list.find(100) << endl;
    
    // Test popFront
    cout << "list " << list << " popFront ";
    list.popFront();
    cout << list << endl;
    
    // Test list String
    /*List<string> l;
    l.append("un");
    l.append("deux");
    l.append("trois");
    
    cout << endl << endl;*/
    // Affichage: un deux trois
    /*List<string> c;
    c.append("un");
    c.append("deux");
    c.append("trois");
    for (List<string>::Iterator it = c.end(); it != c.begin(); --it)
        cout << *it << " ";
    cout << endl;*/
    
    // Test Iterator
    
    /*List<int>::Iterator it = list.begin();
    cout << endl<< "Iter while: ";
    while(it != list.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;
    
    cout << "For iterator string: ";
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    cout << "For modification it string ";
    for(List<string>::Iterator it = l.begin(); it != l.end(); ++it){
        *it = "salut";
        cout << *it << " ";
    }
    cout << endl;*/
    
    // Affichage: 14 3 42*/
    return 0;
}

