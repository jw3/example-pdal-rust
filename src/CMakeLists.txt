if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CARGO_CMD cargo build)
    set(TARGET_DIR "debug")
else ()
    set(CARGO_CMD cargo build --release)
    set(TARGET_DIR "release")
endif ()

set(CLIENT_LIB "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_DIR}/libbackend.a")

add_custom_target(client ALL
                  COMMENT "Compiling backend"
                  COMMAND CARGO_TARGET_DIR=${CMAKE_CURRENT_BINARY_DIR} ${CARGO_CMD}
                  COMMAND cp ${CLIENT_LIB} ${CMAKE_CURRENT_BINARY_DIR}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(client PROPERTIES LOCATION ${CMAKE_CURRENT_BINARY_DIR})

# ------------------

add_library(${PLUGIN_IMPL} SHARED PdalRust.hpp PdalRust.cpp)
target_include_directories(${PLUGIN_IMPL} PRIVATE ${CONAN_INCLUDE_DIRS} ${PDAL_INCLUDE_DIRS})
target_link_libraries(${PLUGIN_IMPL} PRIVATE ${PDAL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${CLIENT_LIB} pthread dl)
install(TARGETS ${PLUGIN_IMPL}
        LIBRARY DESTINATION lib)

set_target_properties(${PLUGIN_IMPL} PROPERTIES
                      VERSION ${FULL_VERSION_STRING}
                      SOVERSION ${VERSION_MAJOR}
                      CLEAN_DIRECT_OUTPUT 1)
