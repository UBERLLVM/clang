// RUN: %clang_cc1 -fno-cxx-missing-return-semantics \
// RUN:     -emit-llvm -O2 -o - %s \
// RUN:   | FileCheck %s

// CHECK: @_Z9no_return
int no_return() {
  // CHECK-NOT: call void @llvm.trap
  // CHECK: ret i32 undef
}
