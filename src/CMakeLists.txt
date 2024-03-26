
# FindPTC..

find_package(FFTW)

find_package(MPI)
include(CMakeDependentOption)
CMAKE_DEPENDENT_OPTION(USE_MPI "Enable MPI capabilities" ON "MPI_FOUND" OFF)
if(USE_MPI)
    add_definitions("-DUSE_MPI")
    include_directories(${MPI_INCLUDE_PATH})
endif(USE_MPI)


# add all includes that subfolders may depend on:
include_directories(main include linac mpi orbit orbit/Apertures orbit/Errors orbit/FieldTracker orbit/Impedances orbit/MaterialInteractions orbit/RFCavities orbit/ParticlesAttributes orbit/BunchDiagnostics orbit/SynchPartRedefinition spacecharge teapot trackerrk4 utils utils/bunch utils/harmonic_analysis utils/integration utils/matrix utils/polynomial utils/field_sources)


set(CMAKE_CXX_FLAGS "-fPIC")

# Install main library, excluding all wrap_ sources
include(files.cmake)
python_add_library(orbit_core MODULE WITH_SOABI ${orbitcore_src})
#target_link_libraries(orbit_core ${FFTW_LIBRARIES} ${MPI_CXX_LIBRARIES})
install(TARGETS orbit_core DESTINATION .)

# We add all subdirectories (that generate libraries)
add_subdirectory(linac)
#add_subdirectory(mpi)
#add_subdirectory(orbit)
#add_subdirectory(spacecharge)
#add_subdirectory(teapot)
#add_subdirectory(utils)

# Finally we create the main project..
include_directories(linac/rfgap)
include_directories(linac/tracking)
include_directories(utils/statistics)
#add_executable(pyORBIT main/main.cc ${all_wrap_src})
#target_link_libraries(pyORBIT python2.7 pyorbit ${FFTW_LIBRARIES})
#python_standalone_executable(pyORBIT)
#install(TARGETS pyORBIT
#    RUNTIME DESTINATION bin
#)

#python_add_library(example MODULE example.c WITH_SOABI)

#install(TARGETS example DESTINATION .)

#add_subdirectory(tests)