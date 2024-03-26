
file(GLOB src_files wrap_*.cc)
python_add_library(linac_tracking MODULE ${src_files})
#target_link_libraries(linac_tracking orbit_core)
install(TARGETS linac_tracking DESTINATION .)