
file(GLOB_RECURSE HAL_SRCS
    hal/*.c
    hal/*.cpp
)
set(HAL_INCS
    hal/
)

file(GLOB_RECURSE MYUI_SRCS
    MYUI/*.c
    MYUI/*.cpp
)
set(MYUI_INCS
    MYUI/

)

file(GLOB_RECURSE SQUARE_SRCS
    squareline/*.c
    squareline/*.cpp
)
set(SQUARE_INCS
    squareline/
)







idf_component_register(SRCS "main.cpp" ${HAL_SRCS} ${MYUI_SRCS} ${SQUARE_SRCS}
                    INCLUDE_DIRS "." ${HAL_INCS} ${MYUI_INCS} ${SQUARE_INCS})
