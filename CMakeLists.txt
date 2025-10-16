cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(bulk VERSION ${PROJECT_VESRION})

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

configure_file(version.h.in version.h)

add_executable(bulk_cli main.cpp Logger/LogSystem.cpp
Logger/StdCoutLogger.cpp Logger/FileLogger.cpp Bulk/Bulk.cpp
Bulk/Bulk_moc.cpp)

add_library(bulk lib.cpp)

set_target_properties(bulk_cli bulk PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(bulk
    PRIVATE "${CMAKE_BINARY_DIR}"
)
 
target_link_libraries(bulk_cli PRIVATE
    bulk
) 

if(WITH_BOOST_TEST)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(test_bulk test_bulk.cpp Logger/LogSystem.cpp
    Logger/StdCoutLogger.cpp Logger/FileLogger.cpp Bulk/Bulk.cpp
    Bulk/Bulk_moc.cpp Logger/StdCoutLogger_moc.cpp)

    set_target_properties(test_bulk PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    set_target_properties(test_bulk PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
    )

    target_link_libraries(test_bulk
        ${Boost_LIBRARIES}
        bulk
    )
endif()

if (MSVC)
    target_compile_options(bulk_cli PRIVATE
        /W4
    )
    target_compile_options(bulk PRIVATE
        /W4
    )

    if(WITH_BOOST_TEST)
        target_compile_options(test_bulk PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(bulk_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

    if(WITH_BOOST_TEST)
        target_compile_options(test_bulk PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS bulk_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_BOOST_TEST)
    enable_testing()
    add_test(test_bulk test_bulk)
endif()
