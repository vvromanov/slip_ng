set(TARGET test_slip_ng)
project(${TARGET})

add_executable(${TARGET}
        TestSlipNG.cpp
        TestCRC32.cpp
        )

target_link_libraries(${TARGET}
        test_main
        slip_ng
        )

add_test(${TARGET} ${TARGET})

if (NOT ${STANDALONE_BUILD})
    add_dependencies(check ${TARGET})
endif()
