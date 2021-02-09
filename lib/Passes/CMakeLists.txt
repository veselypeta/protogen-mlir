add_mlir_dialect_library(PCCToMurphi
    AddTransientStatePass.cpp
    MutexReleasePass.cpp
    ConverPCCToMuphi.cpp
    Pipeline.cpp
    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include/Passes/PCCToMurphiPass

    DEPENDS
    MLIRPccToMurphiPassIncGen

)
target_link_libraries(PCCToMurphi PUBLIC MLIRIR)