project(LibraryTemplate VERSION 0.0.1)

set (TargetName ${PROJECT_NAME})

add_library(${TargetName} OBJECT)

_juce_initialise_target(${TargetName})

target_link_libraries(${TargetName}
        PRIVATE
        juce::juce_core
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags)

target_compile_definitions(${TargetName}
        INTERFACE
        $<TARGET_PROPERTY:${TargetName},COMPILE_DEFINITIONS>)

target_include_directories(${TargetName}
        INTERFACE
        $<TARGET_PROPERTY:${TargetName},INCLUDE_DIRECTORIES>)

set(SOURCES
    Source/LibraryAPI.cpp
    Source/LibraryImpl.cpp)

target_sources(${TargetName} PRIVATE ${SOURCES})

add_library(${TargetName}_shared SHARED)
add_library(${TargetName}_static STATIC)

target_link_libraries(${TargetName}_shared PRIVATE ${TargetName})
target_link_libraries(${TargetName}_static PRIVATE ${TargetName})

