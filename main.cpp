#include "main.h"

int main(int argc, const char * argv[]) {
    ifstream inputFile;
    inputFile.open(argv[1]);
    
    ifstream inputFile2;
    inputFile2.open(argv[1]);
    
    clock_t timeBegin, timeEnd;
    double totalTimeOrderedList = 0, totalTimeMTFList = 0;
    int value;
    int length; // take in the first int in the file, indicating list length
    
    
    //adding to the ordered list
    inputFile >> length;
    orderedList orderedList(length);
    while (length != 0 && inputFile >> value){
        orderedList.add(value);
        length--;
    }
    
    int queries; // comparing the queries to the orderlist values
    inputFile >> queries;
    
    timeBegin = clock();
    int item;
    orderedList.sort();
    while (queries != 0 && inputFile >> item){
        orderedList.search(item);
        queries--;
    }
    timeEnd = clock();
    totalTimeOrderedList = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    cout << "Total (approx) runtime of OrderedList is " << totalTimeOrderedList << endl;
    
    //adding elements to the MTF List
    inputFile2 >> length;
    MTFList mtflist;
    while (length != 0 && inputFile2 >> value){
        mtflist.add(value);
        length--;
    }
    
    inputFile2 >> queries;
    timeBegin = clock();
    while (queries != 0 && inputFile2 >> item){
        mtflist.search(item);
        queries--;
    }
    timeEnd = clock();
    totalTimeMTFList = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    cout << "Total (approx) runtime of MTFList is " << totalTimeMTFList << endl;
    
    //outputs with the time measurement that was faster in each case
    if (totalTimeOrderedList < totalTimeMTFList){
        cout << "Ordered list is faster than MTF List" << endl;
    } else if (totalTimeMTFList < totalTimeOrderedList){
        cout << "Total (approx) runtime of MTF List is faster than Ordered List" << endl;
    } else {
        cout << "Total (approx) runtime of MTF List and Ordered List is the same" << endl;
    }
    
    return 0;
}
