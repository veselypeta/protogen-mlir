set(LLVM_LINK_COMPONENTS
  Support
  )

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(translation_libs GLOBAL PROPERTY MLIR_TRANSLATION_LIBS)

# Generate the lexer/parser
find_package(ANTLR REQUIRED)
antlr_target(ProtoCC ProtoCC.g4 VISITOR)
include_directories(${ANTLR_ProtoCC_OUTPUT_DIR})


add_llvm_executable(pcc-translate
  pcc-translate.cpp
  TranslatePCCToMLIR.cpp
  mlirGen.cpp
  ${ANTLR_ProtoCC_CXX_OUTPUTS}
  )
llvm_update_compile_flags(pcc-translate)
target_link_libraries(pcc-translate
  PRIVATE
  ${dialect_libs}
  ${translation_libs}
  ${LIBS}
  MLIRIR
  MLIRParser
  MLIRPass
  MLIRSPIRV
  MLIRTranslation
  MLIRSupport
  antlr4_static
  )
mlir_check_link_libraries(pcc-translate)