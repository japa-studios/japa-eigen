#ifndef EMatrix_H
#define EMatrix_H

#include <node.h>
#include "Eigen/Dense"

class EMatrix : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> target);

 private:
  EMatrix();
  ~EMatrix();

  Matrix

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> PlusOne(const v8::Arguments& args);
  static v8::Handle<v8::Value> Matrix(const v8::Arguments& args);
  double counter_;
};

#endif
