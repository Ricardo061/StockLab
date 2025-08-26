cmake_minimum_required(VERSION 3.10)
project(StockLab)

set(CMAKE_CXX_STANDARD 17)

# Cria uma pasta "data" dentro do diretório de build
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/data)

# Define uma macro no código C++ com o caminho absoluto da pasta data
add_compile_definitions(
    DATA_PATH="${CMAKE_CURRENT_BINARY_DIR}/data/"
)

# Copia os arquivos de dados da raiz do projeto para a pasta build/data
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/stockregister.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/users.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)

# Adiciona os arquivos fonte
add_executable(StockLab main.cpp registercomp.cpp users.cpp)

target_compile_definitions(StockLab PRIVATE 
    DATA_PATH="${CMAKE_CURRENT_BINARY_DIR}/data/"
)