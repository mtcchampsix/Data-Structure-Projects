#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class orderedList{
public:
    orderedList();
    orderedList(int size);
    ~orderedList();
    void merge(int list[], int x, int y, int z);
    void mergeSort(int list[], int x, int y );
    void sort();
    bool search(int x) const;
    void add(const int & s);
    int size() const;
    int operator[](const unsigned i) const;
    
private:
    int *list;
    int sz;
    int capacity;
};

orderedList::orderedList(){
    list = NULL;
    sz = 0;
    capacity = 0;
    
}

orderedList::orderedList(int size){
    list = new int[size];
    capacity = size;
    sz = 0;
}

orderedList::~orderedList(){
    delete [] list;
    list = NULL;
}

int orderedList::size() const{
    return sz;
}

void orderedList::add(const int & s){
    list[sz] = s;
    sz++;
}

int orderedList::operator[](const unsigned i) const{
    if (i >= sz || i < 0){
        cout << "Operator []: out of range" << endl;
        return -1;
    }
    return list[i];
}

void orderedList::merge(int list[], int left, int right, int mid){
    int first = mid - left + 1;
    int second = right - mid;
    
    orderedList orderlist1(first);
    orderedList orderlist2(second);
    
    for (int i = 0; i < orderlist1.capacity; i++){
        orderlist1.add(list[left+i]);
    }
    
    for (int j =0; j < orderlist2.capacity; j++){
        orderlist2.add(list[(mid+1)+j]);
    }
    
    int m = 0;
    int n = 0;
    int p = 0;
    while (m < orderlist1.size() && (n < orderlist2.size())){
        if (orderlist1[n] <= orderlist2[n]){
            list[left+p] = orderlist1[m];
            p++;
            m++;
        } else {
            list[left+p] = orderlist2[n];
            p++;
            n++;
        }
    }
    if (( m < orderlist1.size() && n < orderlist2.size())){
        for (int x = m; x < orderlist1.size(); x++){
            list[left+n+x] = orderlist1[x];
            p++;
        }
    } else if (m >= orderlist1.size() && n < orderlist2.size()) {
        for (int x = n; x < orderlist2.size(); x++){
            list[left+m+x] = orderlist2[x];
            p++;
        }
    }
}


void orderedList::mergeSort(int list[], int left, int right ){
    if (left < right){
        int center = (left+right)/2;
        
        mergeSort(list, left, center);
        mergeSort(list, center +1, right);
        
        merge(list, left, right, center);
    }
}

void orderedList::sort(){
    mergeSort(list, 0, sz-1);
}

bool orderedList::search(int x) const{
    int begin = 0;
    int end = sz-1;
    
    while (begin <= end){
        int mid = (end + begin)/2;
        if (x > list[mid]){
            begin = mid+1;
        } else if (x < list[mid]){
            end = mid-1;
        } else if (x == list[mid]){
            return true;
        }
    }
    return 0;
}


#endif
