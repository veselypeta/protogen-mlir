add_mlir_dialect_library(utils
stateUtils.cpp

ADDITIONAL_HEADER_DIRS
${PROJECT_SOURCE_DIR}/include/utils

LINK_LIBS PUBLIC
MLIRIR
)

target_link_libraries(utils PUBLIC MLIRIR)