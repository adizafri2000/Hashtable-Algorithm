#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Hashtable.cpp"
using namespace std;

int main(){
    ifstream readFile;
    const int totalEmail = 100;
    string email;
    HashTable<string> ht(0.9*totalEmail);

    readFile.open("setA.txt");
    auto start = chrono::system_clock::now();
    while (getline(readFile, email)){
        ht.insert(email);
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    cout << endl << ht << endl;
    cout << "\n\nTime taken for hashtable insertion with chaining: " << duration.count() << "s.\n";
    readFile.close();

    readFile.open("foundData.txt");
    cout << "Searching from foundData.txt\n";
    start = chrono::system_clock::now();
    while (getline(readFile, email)){
        cout << "Searching for " << email << (ht.retrieve(email) ? ": FOUND" : ": NOT FOUND") << endl;
    }
    end = chrono::system_clock::now();
    duration = end - start;
    
    readFile.close();
    readFile.open("notFoundData.txt");
    cout << "\nSearching from notFoundData.txt\n";
    start = chrono::system_clock::now();
    while (getline(readFile, email)){
        cout << "Searching for " << email << (ht.retrieve(email) ? ": FOUND" : ": NOT FOUND") << endl;
    }
    end = chrono::system_clock::now();
    duration = duration + (end - start);

    cout << "\n\nTime taken to search for 20 emails: " << duration.count() << "s.";
    return 0;
}