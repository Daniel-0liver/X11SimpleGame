cmake_minimum_required(VERSION 3.10)
project(X11SimpleGame-project)

# Configuração do projeto
set(SOURCES
    main.cpp
	X11SimpleGame.hpp
)

# Configuração das dependências
find_package(X11 REQUIRED)

# Adição dos arquivos-fonte e criação do executável
add_executable(X11SimpleGame ${SOURCES})

# Inclusão de diretórios de cabeçalhos
target_include_directories(X11SimpleGame PRIVATE
    ${X11_INCLUDE_DIR}
)

# Definição de recursos de linguagem
target_compile_features(X11SimpleGame PRIVATE
    cxx_std_11
)

# Vinculação de bibliotecas
target_link_libraries(X11SimpleGame PRIVATE
    ${X11_LIBRARIES}
)
