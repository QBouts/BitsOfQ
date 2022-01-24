MACRO(GET_SUBDIRS_WITH_MAIN output dir)
    FILE(GLOB subdirectories RELATIVE ${dir} ${dir}/*)
    SET(dirlist)
    FOREACH(child ${subdirectories})
        IF(IS_DIRECTORY ${dir}/${child} AND EXISTS ${dir}/${child}/main.cpp)
          LIST(APPEND dirlist ${child})
        ENDIF()
    ENDFOREACH()
    SET(${output} ${dirlist})
ENDMACRO()
