#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "ematrix.h"
#include "Eigen/Dense"

using Eigen::MatrixXd;
using namespace v8;

EMatrix::EMatrix() {};
EMatrix::~EMatrix() {};

void EMatrix::Init(Handle<Object> target) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("EMatrix"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("plusOne"),
      FunctionTemplate::New(PlusOne)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("matrix"),
      FunctionTemplate::New(Matrix)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("EMatrix"), constructor);
}

Handle<Value> EMatrix::New(const Arguments& args) {
  HandleScope scope;

  EMatrix* obj = new EMatrix();
  obj->counter_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  obj->Wrap(args.This());

  return args.This();
}

Handle<Value> EMatrix::PlusOne(const Arguments& args) {
  HandleScope scope;

  EMatrix* obj = ObjectWrap::Unwrap<EMatrix>(args.This());
  obj->counter_ += 1;

  return scope.Close(Number::New(obj->counter_));
}

Handle<Value> EMatrix::Matrix(const Arguments& args) {
  HandleScope scope;

  EMatrix* obj = ObjectWrap::Unwrap<EMatrix>(args.This());
  obj->counter_ += 1;

  MatrixXd m(2,2);
  m(0,0) = obj->counter_;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);

  return scope.Close(Number::New(m(0,0)));
}
