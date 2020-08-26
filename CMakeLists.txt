# Para conocer más sobre cmake y este archivo vea el archivo
# "sobre-cmake/README.md" en este mismo repositorio.

# cmake se queja si no usarmos esta línea. Indica la versión mínima de
# cmake que el usuario debe tener para poder compilar el proyecto.
cmake_minimum_required(VERSION 3.16)

# Indicamos que queremos usar el estándar C++11 como mínimo (esto hace
# que cmake pase por defecto a los compiladores clang/gcc/msvc las
# opciones necesarias para activar el soporte de C++11, como -std=c++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# El nombre de nuestro proyecto.
project(lab)

# Con add_subdirectory() podemos agregar sub-directorios que deben
# contener otros archivos CMakeLists.txt.
add_subdirectory(hola-mundo)
