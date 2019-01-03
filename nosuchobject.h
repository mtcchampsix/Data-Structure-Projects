#ifndef NOSUCHOBJECT_H
#define NOSUCHOBJECT_H

#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

class NoSuchObject: public logic_error {
    
public:
    NoSuchObject():logic_error("Stack empty"){}
    NoSuchObject(const string& what):logic_error(what){}
}; //NoSuchObject class

#endif
