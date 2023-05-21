cmake_minimum_required(VERSION 3.23)
project(Mario_Parteam_V1 C)

set(CMAKE_C_STANDARD 99)

add_executable(ece-world-paris-ing1-2022-2023-td4-mario-parteam main.c Menu.c Menu.h guitarhero.c guitarhero.h bomberman.c bomberman.h supersimon.c supersimon.h map.c map.h main.h generalfunctions.h riviere.c riviere.h tickets.c)

target_link_libraries(ece-world-paris-ing1-2022-2023-td4-mario-parteam -lmingw32 -lalleg44)

