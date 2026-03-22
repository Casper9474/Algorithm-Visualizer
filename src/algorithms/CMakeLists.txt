set(AlgorithmsLib ${PROJECT_NAME}Lib)
add_library(AlgorithmsLib)

target_compile_features(AlgorithmsLib PRIVATE cxx_std_23)

target_sources(
        AlgorithmsLib
            PRIVATE
                bubbleSort.cpp
                quickSort.cpp
                mergeSort.cpp

            PUBLIC
                FILE_SET HEADERS
                FILES
                    sorter.h
                    bubbleSort.h
                    quickSort.h
                    mergeSort.h
)