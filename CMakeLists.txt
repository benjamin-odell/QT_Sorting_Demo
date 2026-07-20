cmake_minimum_required(VERSION 3.19)
project(Sorting_Demo LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

set(CMAKE_AUTORCC ON)

qt_add_executable(Sorting_Demo
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    sorting_algo.h sorting_algo.cpp
    insertion_sort.h insertion_sort.cpp
    README.md
    selection_sort.h selection_sort.cpp
    quick_sort.h quick_sort.cpp
    merge_sort.h merge_sort.cpp
    bubble_sort.h bubble_sort.cpp
    heap_sort.h heap_sort.cpp
    resource.qrc

)

target_link_libraries(Sorting_Demo
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Sorting_Demo
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Sorting_Demo
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
