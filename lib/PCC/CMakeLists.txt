file(GLOB globbed *.cpp)
add_mlir_dialect_library(MLIRPCC
    PCCDialect.cpp
    PCCOps.cpp
    PCCTypes.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include/PCC

    DEPENDS
    MLIRPCCIncGen

	LINK_LIBS PUBLIC
	MLIRIR

)