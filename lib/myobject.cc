#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "myobject.h"
#include "Eigen/Dense"

using Eigen::MatrixXd;
using namespace v8;

MyObject::MyObject() {};
MyObject::~MyObject() {};

void MyObject::Init(Handle<Object> target) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("MyObject"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("plusOne"),
      FunctionTemplate::New(PlusOne)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("matrix"),
      FunctionTemplate::New(Matrix)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("MyObject"), constructor);
}

Handle<Value> MyObject::New(const Arguments& args) {
  HandleScope scope;

  MyObject* obj = new MyObject();
  obj->counter_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  obj->Wrap(args.This());

  return args.This();
}

Handle<Value> MyObject::PlusOne(const Arguments& args) {
  HandleScope scope;

  MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.This());
  obj->counter_ += 1;

  return scope.Close(Number::New(obj->counter_));
}

Handle<Value> MyObject::Matrix(const Arguments& args) {
  HandleScope scope;

  MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.This());
  obj->counter_ += 1;

  MatrixXd m(2,2);
  m(0,0) = obj->counter_;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);

  return scope.Close(Number::New(m(0,0)));
}
