cmake_minimum_required(VERSION 3.20)

project(GameOfLife)

set(PROJECT_FILS main.cpp App.cpp App.h LifeAlgorytm.cpp LifeAlgorytm.h)

set(SFML_DIR "C:/Users/Jakub/Documents/Bibliotekicpp/SFML-2.5.1")

add_executable(GameOfLife ${PROJECT_FILS})

target_link_libraries(GameOfLife ${SFML_DIR}/lib/sfml-graphics.lib)
target_link_libraries(GameOfLife ${SFML_DIR}/lib/sfml-audio.lib)
target_link_libraries(GameOfLife ${SFML_DIR}/lib/sfml-window.lib)
target_link_libraries(GameOfLife ${SFML_DIR}/lib/sfml-system.lib)

include_directories(GameOfLife ${SFML_DIR}/include)

add_custom_command(TARGET GameOfLife POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        "${SFML_DIR}/bin/sfml-audio-2.dll"
        $<TARGET_FILE_DIR:GameOfLife>
    COMMAND ${CMAKE_COMMAND} -E copy
        "${SFML_DIR}/bin/sfml-graphics-2.dll"
        $<TARGET_FILE_DIR:GameOfLife>
    COMMAND ${CMAKE_COMMAND} -E copy
        "${SFML_DIR}/bin/sfml-window-2.dll"
        $<TARGET_FILE_DIR:GameOfLife>
    COMMAND ${CMAKE_COMMAND} -E copy
        "${SFML_DIR}/bin/sfml-system-2.dll"
        $<TARGET_FILE_DIR:GameOfLife>)

