add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
        main.cpp
        mainWindow.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            main.hpp
            mainWindow.hpp
)

find_package(wxWidgets REQUIRED)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        wxWidgets::wxWidgets
)

if(CMAKE_SYSTEM_NAME MATCHES Windows)
    target_link_options(${PROJECT_NAME} PRIVATE /SUBSYSTEM:WINDOWS)
endif()