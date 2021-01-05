get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
        ${dialect_libs}
        ${conversion_libs}
        MLIROptLib
        antlr4_static
        )


# Generate the lexer/parser
find_package(ANTLR REQUIRED)
antlr_target(ProtoCC ProtoCC.g4 VISITOR)
include_directories(${ANTLR_ProtoCC_OUTPUT_DIR})


add_llvm_executable(murphi-opt murphi-opt.cpp mlirGen.cpp ${ANTLR_ProtoCC_CXX_OUTPUTS})

llvm_update_compile_flags(murphi-opt)
target_link_libraries(murphi-opt PRIVATE ${LIBS})
