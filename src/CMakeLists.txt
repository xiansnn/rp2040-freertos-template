add_executable(${ProjectName}_blink
    main.c
)

target_include_directories(${ProjectName}_blink PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${ProjectName}_blink 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4 
    )

pico_add_extra_outputs(${ProjectName}_blink)