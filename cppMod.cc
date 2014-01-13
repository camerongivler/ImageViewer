#include <node.h>
#include <v8.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace v8;
using namespace std;

string getB64Img();

Handle<Value> add(const Arguments& args) {
    HandleScope scope;
    Local<Number> num1 = Number::New(args[0]->NumberValue() + args[1]->NumberValue());
    return scope.Close(num1);
}

Handle<Value> mult(const Arguments& args) {
    HandleScope scope;
    Local<Number> num1 = Number::New(args[0]->NumberValue() * args[1]->NumberValue());
    return scope.Close(num1);
}

Handle<Value> prev(const Arguments& args) {
    HandleScope scope;
    system("cp image1.jpg image.jpg");
    Local<Number> num2 = Number::New(1);
    return scope.Close(num2);
}

Handle<Value> next(const Arguments& args) {
    HandleScope scope;
    system("cp image2.jpg image.jpg");
    Local<Number> num2 = Number::New(1);
    return scope.Close(num2);
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("add"),
            FunctionTemplate::New(add)->GetFunction());
    exports->Set(String::NewSymbol("mult"),
            FunctionTemplate::New(mult)->GetFunction());
    exports->Set(String::NewSymbol("prev"),
            FunctionTemplate::New(prev)->GetFunction());
    exports->Set(String::NewSymbol("next"),
            FunctionTemplate::New(next)->GetFunction());
}

NODE_MODULE(cppMod, init)