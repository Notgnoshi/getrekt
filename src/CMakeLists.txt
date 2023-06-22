add_executable(getrekt)

file(
    GLOB_RECURSE
    GETREKT_SOURCES
    CONFIGURE_DEPENDS
    "*.cpp"
)
target_sources(getrekt PRIVATE "${GETREKT_SOURCES}")
target_include_directories(
    getrekt
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
)

set_target_properties(
    getrekt PROPERTIES LINK_FLAGS "--bind -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s ENVIRONMENT=web"
)
