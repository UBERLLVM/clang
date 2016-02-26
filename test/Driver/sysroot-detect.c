// Check the sysroot detection.

// If --sysroot=<dir> is not specified, try <bin>/../../sysroot if available.

// RUN: %clang %s -### -fsyntax-only \
// RUN:     -ccc-install-dir "%S/Inputs/basic_android_tree/arm-linux-androideabi/bin" \
// RUN:     --target=arm-linux-androideabi 2>&1 \
// RUN:   | FileCheck %s --check-prefix=CHECK-ARM

// RUN: %clang %s -### -fsyntax-only \
// RUN:     -ccc-install-dir "%S/Inputs/basic_android_tree/aarch64-linux-android/bin" \
// RUN:     --target=aarch64-linux-android 2>&1 \
// RUN:   | FileCheck %s --check-prefix=CHECK-AARCH64

// RUN: %clang %s -### -fsyntax-only \
// RUN:   -ccc-install-dir "%S/Inputs/basic_android_tree/mipsel-linux-android/bin" \
// RUN:   --target=mipsel-linux-android 2>&1 \
// RUN:   | FileCheck %s --check-prefix=CHECK-MIPSEL

// CHECK-ARM: "-isysroot" "{{.*}}/Inputs/basic_android_tree/arm-linux-androideabi/bin/../../sysroot"
// CHECK-AARCH64: "-isysroot" "{{.*}}/Inputs/basic_android_tree/aarch64-linux-android/bin/../../sysroot"
// CHECK-MIPSEL: "-isysroot" "{{.*}}/Inputs/basic_android_tree/mipsel-linux-android/bin/../../sysroot"
