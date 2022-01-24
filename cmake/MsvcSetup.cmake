cmake_minimum_required(VERSION 3.16)

# due to a bug the visual studio compiler doesn't distinguish between SYSTEM and normal include paths
# To prevent us from being flooded with warnings from 3rd party libraries such as boost, we add these 
# compiler specific flags to treat every include in angle brackets as external. We then specific that 
# the warning level for external headers should be 0 (no warnings)
target_compile_options(project_options INTERFACE /experimental:external /Zc:preprocessor /external:anglebrackets /external:W0)

# Quote:
# In the current [MSVC] implementation you will still occasionally get a warning through from an external header
# when that warning was emitted by the compilers back-end (as opposed to front-end). These warnings usually
# start with C47XX, though not all C47XX warnings are back-end warnings. A good rule of thumb is that if 
# detection of a given warning may require data or control-flow analysis, then it is likely done by the 
# back-end in our implementation and such a warning won't be suppressed by the current mechanism. 
# This is a known problem and the proper fix may not arrive until the next major release of Visual Studio
# as it requires breaking changes to our intermediate representation. You can still disable these warnings
# the traditional way with /wd47XX.
# 
# Note from myself: Apparently it is not just the 47XX warnings, also a few other warnings are still emitted,
# among which a set of 26XXX warnings which have recently been added to MSVC and don't have options to suppress them yet (known bug)

# boost: warning C4619: #pragma warning: there is no warning number 'XXXX'
target_compile_options(project_warnings BEFORE INTERFACE "/wd4619")

# Enable object-level parallel building for MSVC
target_compile_options(project_options INTERFACE /MP)

target_compile_features(project_options INTERFACE cxx_std_20) 