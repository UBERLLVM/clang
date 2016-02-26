// Test the -mstack-protector-guard=[global|tls] option

// RUN: %clang -target i686-unknown-linux-gnu \
// RUN:        -fstack-protector -mstack-protector-guard=tls -### %s 2>&1 \
// RUN:   | FileCheck %s -check-prefix=CHECK-TLS

// RUN: %clang -target i686-unknown-linux-gnu \
// RUN:        -fstack-protector -mstack-protector-guard=global -### %s 2>&1 \
// RUN:   | FileCheck %s -check-prefix=CHECK-GLOBAL

// "i686-unknown-linux-gnu": the default value is "tls"
// RUN: %clang -target i686-unkknown-linux-gnu \
// RUN:        -fstack-protector -### %s 2>&1 \
// RUN:   | FileCheck %s -check-prefix=CHECK-TLS

// "i686-unknown-linux-android": the default value is "global"
// RUN: %clang -target i686-unkknown-linux-android \
// RUN:        -fstack-protector -### %s 2>&1 \
// RUN:   | FileCheck %s -check-prefix=CHECK-GLOBAL

// CHECK-TLS-NOT: "-x86-force-gv-stack-cookie"

// CHECK-GLOBAL: "-x86-force-gv-stack-cookie"
