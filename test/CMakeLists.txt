configure_lit_site_cfg(
        ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
        ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
        MAIN_CONFIG
        ${CMAKE_CURRENT_SOURCE_DIR}/lit.cfg.py
)

set(MURPHI_OPT_TEST_DEPENDS
        FileCheck count not
        murphi-opt
        )

add_lit_testsuite(check-murphi-opt "Running the murphi-opt regression tests"
        ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${MURPHI_OPT_TEST_DEPENDS}
        )
set_target_properties(check-murphi-opt PROPERTIES FOLDER "Tests")

add_lit_testsuites(MURPHI_OPT ${CMAKE_CURRENT_SOURCE_DIR} DEPENDS ${MURPHI_OPT_TEST_DEPENDS})
