//===- standalone-opt.cpp ---------------------------------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include <filesystem>
#include <iostream>

#include "mlir/IR/AsmState.h"
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

#include "Murphi/Dialect.h"
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

#include "Target/TranslateToMurphi.h"

int loadMLIR(mlir::MLIRContext &context, mlir::OwningModuleRef &module) {
  std::ifstream stream;
  stream.open("/Users/petrvesely/dev/mlir/mlir-standalone-template/MI.pcc",
              std::ifstream::in);

  antlr4::ANTLRInputStream input(stream);
  ProtoCCLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  ProtoCCParser parser(&tokens);
  ProtoCCParser::DocumentContext *tree = parser.document();

  module = pcc::mlirGen(context, tree);
  return !module ? 1 : 0;
}

int loadAndProcessMLIR(mlir::MLIRContext &context,
                       mlir::OwningModuleRef &module) {
  if (int error = loadMLIR(context, module)) {
    std::cout << "LoadMLIR failed" << std::endl;
    return error;
  }

  // Add and enable passes
  mlir::PassManager pm(&context);
  // Apply any generic pass manager command line options and run the pipeline.
  mlir::applyPassManagerCLOptions(pm);

  // TODO -- passes not working correctly
  // pm.addPass(mlir::createLowerToMurphiPass());
  // if (mlir::failed(pm.run(*module))) {
  //   return 4;
  // }
  return 0;
}

int main(int argc, char **argv) {
  // Register any command line options.
  mlir::registerAsmPrinterCLOptions();
  mlir::registerMLIRContextCLOptions();
  mlir::registerPassManagerCLOptions();
  // Create MLIR Context
  mlir::MLIRContext context;
  context.getOrLoadDialect<mlir::pcc::PCCDialect>();
  context.getOrLoadDialect<mlir::murphi::MurphiDialect>();
  context.getOrLoadDialect<mlir::StandardOpsDialect>();
  context.getOrLoadDialect<mlir::scf::SCFDialect>();

  mlir::OwningModuleRef module;

  if (int error = loadAndProcessMLIR(context, module)) {
    std::cout << "loadAndProcessMLIR Failed" << std::endl;
    return error;
  }
  module->dump();
  return 0;
}



  // mlir::registerAllPasses();
  // TODO: Register standalone passes here.
  // mlir::registerPCCToMurphiPasses();

  // mlir::DialectRegistry registry;
  // registry.insert<mlir::pcc::PCCDialect>();
  // registry.insert<mlir::murphi::MurphiDialect>();
  // registry.insert<mlir::StandardOpsDialect>();
  // Add the following to include *all* MLIR Core dialects, or selectively
  // include what you need like above. You only need to register dialects that
  // will be *parsed* by the tool, not the one generated
  // registerAllDialects(registry);

  // return failed(
  //     mlir::MlirOptMain(argc, argv, "Standalone optimizer driver\n",
  //     registry));