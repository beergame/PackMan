cmake_minimum_required(VERSION 3.2)
project(PackMan)

set(CMAKE_CXX_STANDARD 11)
set(PACKMAN_VERSION_MAJOR 1)
set (PACK_VERSION_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_NAME "PACKMAN")
set(SOURCE_FILES
        Abstract/AbstractEntity.cpp Abstract/Character.cpp Entities/Packman.cpp Entities/Monster.cpp Entities/Map.cpp Manager/PlayerManager.cpp Manager/MonsterManager.cpp Manager/GameManager.cpp Utils/IObservable.hh Utils/IObserver.hh Utils/TimeManager.cpp Utils/Factory/MonsterFactory.cpp Utils/Factory/MapFactory.cpp config.h.in)

add_executable(${EXECUTABLE_NAME} Abstract/AbstractEntity.cpp Abstract/Character.cpp Entities/Packman.cpp Entities/Monster.cpp Entities/Map.cpp Manager/PlayerManager.cpp Manager/MonsterManager.cpp Manager/GameManager.cpp Utils/IObservable.hh Utils/IObserver.hh Utils/TimeManager.cpp Utils/Factory/MonsterFactory.cpp Utils/Factory/MapFactory.cpp config.h.in)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 1.6 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)