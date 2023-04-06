cmake_minimum_required(VERSION 3.25.0)
project(budget_tracker)





set(CMAKE_CXX_STANDARD 23)


message(STATUS "Project source directory ${PROJECT_SOURCE_DIR}")

add_executable(budget_tracker main.cpp
        src/IDataBase.h
        src/DatabaseTables.h
        src/SqliteDataBaseService.cpp
        src/SqliteDataBaseService.h
        src/Paths.cpp
        src/Paths.h
        src/Exception.cpp
        src/Exception.h
        src/Singleton.h
        src/SqliteDataBaseConnector.cpp
        src/SqliteDataBaseConnector.h
        src/Authorization.cpp
        src/Authorization.h
        src/Authentication.cpp
        src/Authentication.h
        src/Session.cpp
        src/Session.h
        src/Commands.h
        src/Commands.cpp
        src/PasswordInput.h
        src/PasswordInput.cpp
        src/Attempt.cpp
        src/Attempt.h
        src/Budget.cpp
        src/Budget.h
        src/Datetime.cpp
        src/Datetime.h)


if (WIN32)
    set_target_properties(${PROJECT_NAME}
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/windows"
            LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/windows"
            RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/windows"
            )
    # install(TARGETS ${PROJECT_NAME} CONFIGURATIONS Debug RUNTIME DESTINATION bin/windows)

endif (WIN32)


if (UNIX)
    set_target_properties(${PROJECT_NAME}
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/linux"
            LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/linux"
            RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/linux"
            )
endif (UNIX)

set(EXTERNAL_LIBS_ROOT "${PROJECT_SOURCE_DIR}/third_party")

add_subdirectory("${EXTERNAL_LIBS_ROOT}/string_interpolation")
include_directories("${EXTERNAL_LIBS_ROOT}/string_interpolation/include")

if (WIN32)
    #    include("${CMAKE_SOURCE_DIR}/conan/windows/conan_paths.cmake")
    include("C:\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
    include_directories(C:\\vcpkg\\installed\\x64-windows\\include\\)
    link_directories(C:\\vcpkg\\installed\\x64-windows\\lib\\)

endif (WIN32)

if (UNIX)

    include_directories("${EXTERNAL_LIBS_ROOT}/string_interpolation/lib")
    #    include("${CMAKE_SOURCE_DIR}/conan/linux/conan_paths.cmake")
    include("/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
    include_directories(/opt/vcpkg/installed/x64-linux/include/)
    link_directories(/opt/vcpkg/installed/x64-linux/lib/)

endif (UNIX)

find_package(fmt REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt)

find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES})
endif ()

find_package(cryptopp REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC cryptopp::cryptopp)

find_package(SQLiteCpp REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC SQLiteCpp)
