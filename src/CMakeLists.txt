# Compile a list of files and store them in the Engine_SRC variable
file(
    GLOB Engine_SRC
    CONFIGURE_DEPENDS
    "*.cpp"
)

# Output executable compiled with target name SyrfusGameEngine from the list of source files
add_executable(SyrfusGameEngine ${Engine_SRC})