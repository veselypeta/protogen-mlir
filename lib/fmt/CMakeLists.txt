add_mlir_dialect_library(fmtlib
format.cc

ADDITIONAL_HEADER_DIRS
${PROJECT_SOURCE_DIR}/include/fmt

LINK_LIBS PUBLIC
MLIRIR
)

target_link_libraries(fmtlib PUBLIC MLIRIR)