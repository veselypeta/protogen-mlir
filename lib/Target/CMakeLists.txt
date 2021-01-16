add_mlir_dialect_library(MLIRToMurphi
TranslateToMurphi.cpp
MurphiModule.cpp
MurphiTemplates.cpp

ADDITIONAL_HEADER_DIRS
${PROJECT_SOURCE_DIR}/include/Target

LINK_LIBS PUBLIC
MLIRIR
)

target_link_libraries(MLIRToMurphi PUBLIC MLIRIR)