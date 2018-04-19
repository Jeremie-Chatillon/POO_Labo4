/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jeremie
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

    List<int> lis;
    cout << lis;
    lis.append(1);
    lis.append(2);

    cout << endl << lis.at(0);
    cout << lis.at(1) << "\n";
    
    lis.insert(3);
    lis.insert(4);

    cout << lis.at(0);
    cout << lis.at(1);
    cout << lis.at(2);
    cout << lis.at(3);
    
    cout << lis.at(3);
    
    List<int>::Iterator it = lis.begin();
    cout << endl<< "Iter : ";
    while(it != lis.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl << lis;
    cout << lis;
    cout << lis << endl;
    ///cout << endl << lis.size();
    List<string> l;
l.append("un");
l.append("deux");
l.append("trois");
for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
cout << *it << " ";
cout << endl << endl;
// Affichage: un deux trois
List<string> c;
c.append("un");
c.append("deux");
c.append("trois");
for (List<string>::Iterator it = --c.end(); it != --c.begin(); --it)
    cout << *it << " ";
cout << endl;
// Affichage: 14 3 42
    return 0;
}

