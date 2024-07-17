add_executable(${ProjectName}_blink
    main.cpp
)

target_include_directories(${ProjectName}_blink PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    debug_probe
)

target_link_libraries(${ProjectName}_blink 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4 
    debug_probe
    )

pico_add_extra_outputs(${ProjectName}_blink)