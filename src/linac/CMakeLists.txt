include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#add_subdirectory(rfgap)
add_subdirectory(tracking)

include_directories(rfgap)
include_directories(tracking)

file(GLOB src_files wrap_*.cc)

python_add_library(linac MODULE WITH_SOABI  ${src_files})
#target_link_libraries(linac orbit_core)
install(TARGETS linac DESTINATION .)