GET_SUBDIRS_WITH_MAIN(dirs ${CMAKE_CURRENT_LIST_DIR})

FOREACH(subdir ${dirs})
  STRING(REGEX MATCH "[^_]+" target ${subdir})
  ADD_EXECUTABLE(${target} ${subdir}/main.cpp)
  TARGET_LINK_LIBRARIES(${target} project_options project_warnings)
ENDFOREACH()