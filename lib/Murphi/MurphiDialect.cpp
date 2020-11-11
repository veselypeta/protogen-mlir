//===- StandaloneDialect.cpp - Standalone dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Murphi/MurphiDialect.h"
#include "Murphi/MurphiOps.h"

using namespace mlir;
using namespace mlir::murphi;

//===----------------------------------------------------------------------===//
// Murphi dialect.
//===----------------------------------------------------------------------===//

void MurphiDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Murphi/MurphiOps.cpp.inc"
      >();
}
