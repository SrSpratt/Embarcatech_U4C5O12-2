#Lista os arquivos a serem adicionados
set(SRC_FILES 
    ${CMAKE_SOURCE_DIR}/src/General.c
    ${CMAKE_SOURCE_DIR}/src/Lights.c
    ${CMAKE_SOURCE_DIR}/src/Button.c
)

#Adiciona ao executável no CMakeLists da pasta de origem
target_sources(${PROJECT_NAME} PRIVATE 
    ${SRC_FILES}
)
