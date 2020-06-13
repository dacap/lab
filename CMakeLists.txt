# Para conocer más sobre cmake y este archivo vea el archivo
# "sobre-cmake/README.md" en este mismo repositorio.

# cmake se queja si no usarmos esta línea. Indica la versión mínima de
# cmake que el usuario debe tener para poder compilar el proyecto.
cmake_minimum_required(VERSION 3.16)

# El nombre de nuestro proyecto.
project(lab)

# Con add_subdirectory() podemos agregar sub-directorios que deben
# contener otros archivos CMakeLists.txt.
add_subdirectory(hola-mundo)
