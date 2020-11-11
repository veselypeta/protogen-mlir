add_mlir_dialect_library(MLIRStandalone
        MurphiDialect.cpp
        MurphiOps.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/Murphi

        DEPENDS
        MLIRMurphiOpsIncGen

	LINK_LIBS PUBLIC
	MLIRIR
)
