cmake_minimum_required(VERSION 3.15)
project(CPE_corewar_2019 C)

set(CMAKE_C_STANDARD 99)

##directories
set(INCLUDE_DIRECTORY include/)
set(SOURCE_DIRECTORY src/)
set(LIB_DIRECTORY lib/)
set(MY_DIRECTORY my/)
set(GNL_DIRECTORY get_next_line/)
set(TESTS_DIRECTORY tests/)


set(SOURCE  )
list(TRANSFORM SOURCE PREPEND ${SOURCE_DIRECTORY})


set(SOURCE_MAIN main.c)
list(TRANSFORM SOURCE_MAIN PREPEND ${SOURCE_DIRECTORY})


set(SOURCE_MY   )
list(TRANSFORM SOURCE_MY PREPEND ${MY_DIRECTORY})


set(SOURCE_LIB  ${SOURCE_MY})
list(TRANSFORM SOURCE_LIB PREPEND ${LIB_DIRECTORY})


set(SOURCE_TESTS)
list(TRANSFORM SOURCE_TESTS PREPEND ${TESTS_DIRECTORY})


##flags
set(CMAKE_C_FLAGS "")

##executables

add_executable(COEUR_GUERRE ${SOURCE_MAIN} ${SOURCE} ${SOURCE_LIB})
target_include_directories(COEUR_GUERRE PRIVATE ${INCLUDE_DIRECTORY})

#
#add_executable(tests_run ${SOURCE_TESTS} ${SOURCE_CORE} ${SOURCE_LIB})
#target_compile_options(tests_run PRIVATE ${CRITERION_FLAGS})
#target_include_directories(tests_run PRIVATE ${INCLUDE_DIRECTORY})