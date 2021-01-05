file(GLOB globbed *.cpp)
add_mlir_dialect_library(MLIRMurphi 
    Dialect.cpp 
    Ops.cpp
    Types.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include/PCC

    DEPENDS
    MLIRMurphiIncGen

        LINK_LIBS PUBLIC
        MLIRIR

)