//===- standalone-opt.cpp ---------------------------------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include <filesystem>
#include <iostream>

#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Support/MlirOptMain.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"

#include "Murphi/MurphiDialect.h"
#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "PCC/Types.h"
#include "Passes/PCCtoMurphiPass/Passes.h"

#include "ProtoCCBaseVisitor.h"
#include "ProtoCCLexer.h"
#include "ProtoCCMLIRVisitor.h"
#include "ProtoCCParser.h"
#include "ProtoCCVisitor.h"

#include "mlirGen.h"

void getAST() {
  std::ifstream stream;
  stream.open("/Users/petrvesely/dev/mlir/mlir-standalone-template/MI.pcc", std::ifstream::in);

  antlr4::ANTLRInputStream input(stream);
  ProtoCCLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  ProtoCCParser parser(&tokens);
  ProtoCCParser::DocumentContext *tree = parser.document();

  // Create MLIR Context
  mlir::MLIRContext context;
  context.getOrLoadDialect<mlir::pcc::PCCDialect>();
  context.getOrLoadDialect<mlir::StandardOpsDialect>();
  context.getOrLoadDialect<mlir::scf::SCFDialect>();

  mlir::OwningModuleRef module = pcc::mlirGen(context, tree);
  module->dump();
}

int main(int argc, char **argv) {
  getAST();

  
  // mlir::registerAllDialects();
  mlir::registerAllPasses();
  // TODO: Register standalone passes here.
  mlir::registerPCCToMurphiPasses();

  mlir::DialectRegistry registry;
  registry.insert<mlir::pcc::PCCDialect>();
  registry.insert<mlir::murphi::MurphiDialect>();
  registry.insert<mlir::StandardOpsDialect>();
  // Add the following to include *all* MLIR Core dialects, or selectively
  // include what you need like above. You only need to register dialects that
  // will be *parsed* by the tool, not the one generated
  // registerAllDialects(registry);

  return failed(
      mlir::MlirOptMain(argc, argv, "Standalone optimizer driver\n", registry));
}
