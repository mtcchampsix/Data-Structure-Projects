#include "main.h"

int main(int argc, char * argv[]){
    unsigned long misspelled = 0;
    unsigned long wordCount = 0;
    clock_t timeBegin, timeEnd;
    double perfectHashTime = 0;
    double totalRunTime = 0;
    
    ifstream inputFile;
    inputFile.open(argv[1]); //dictionaryfile
    
    ifstream inputFile2;
    inputFile2.open(argv[2]); //inputFile
    
    string word;
    while (inputFile >> word){
        wordCount++;
    }
    
    ifstream input;
    input.open(argv[1]);
    
    timeBegin = clock();
    HashTable dictionaryFile(wordCount);
    while (input >> word){
        dictionaryFile.insert(word);
    }
    timeEnd = clock();
    perfectHashTime = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    
    timeBegin = clock();
    while (inputFile2 >> word){
        if (dictionaryFile.find(word) == false){
            misspelled++;
        }
    }
    timeEnd = clock();
    totalRunTime = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    
    cout << "Total number of misspelled words: " << misspelled << endl;
    cout << "Total time to create the perfect hash: " << perfectHashTime << endl;
    cout << "Total runtime: " << totalRunTime << endl;
    
    return 0;
}
