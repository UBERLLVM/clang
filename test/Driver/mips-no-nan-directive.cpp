// Check whether -mno-nan-directive is forwarded to mips backend.
i
// RUN: %clang -target mips-linux-gnu -### -c %s -mno-nan-directive 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK %s
// CHECK: "-mllvm" "-mips-no-nan-directive"
