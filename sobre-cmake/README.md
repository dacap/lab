# Sobre CMake

¿Qué es un archivo `CMakeLists.txt`? Un archivo `CMakeLists.txt` es un
archivo de configuración para el programa [*CMake*](https://cmake.org/)
que describe la estructura de nuestro proyecto —qué compilar, qué
archivos ejecutables queremos generar, qué librerías, etc.

¿Qué es *CMake*? *CMake* se encarga de convertir el archivo
`CMakeLists.txt` en otros archivos de proyectos —e.j. proyectos para
*Visual Studio*, *Xcode*— u otros
[*makefiles*](https://en.wikipedia.org/wiki/Makefile) más genéricos
para utilidades como *GNU make*, *NMake*,
[*ninja*](https://ninja-build.org/).

Podemos visualizar a *CMake* como una pequeña criatura que se alimenta
de archivos `CMakeLists.txt` y lanza otros archivos cloacales como `Makefile` o
`build.ninja` que sólo otras herramientas aún más crípticas saben interpretar.
La idea general es la siguiente:

1. Existe una carpeta de código fuente: la carpeta que tiene el
   `CMakeLists.txt` y los archivos `.cpp`, generalmente es tu repositorio Git
   —también llamado [*source directory*](https://cmake.org/cmake/help/latest/variable/CMAKE_SOURCE_DIR.html).
2. Existe "la cloaca": que es donde toda la salida de *CMake* se acumula,
   y donde quedarán los `.exe` que podemos finalmente ejecutar —esta
   carpeta se llama también *build directory*,
   o [*binary directory*](https://cmake.org/cmake/help/latest/variable/CMAKE_BINARY_DIR.html).

Generalmente ejecutaremos *CMake* con el argumento `-B <build-directory>`
y `-S <source directory>`. Por ejemplo:

    C:\temp>cmake -G Ninja -S C:\temp\codigo-de-mi-proyecto -B C:\temp\cloaca

En ese caso 👆 la carpeta
`C:\temp\codigo-de-mi-proyecto` debería contener nuestro
proyecto con un archivo `CMakeLists.txt`, y en la carpeta `C:\temp\cloaca`
se crearán millones de archivos inútiles, para luego, una vez que
*CMake* haga su trabajo, podamos ejecutar otro programa (en este caso *ninja*,
ya que indicamos `-G Ninja`) que interprete todo eso y finalmente llame al
compilador, para obtener un archivo ejecutable, nuestro `.exe`, el
único archivo de interés en todo este enredo.

Como alternativa, podríamos compilar con el mismo *CMake*:

    C:\temp>cmake --build C:\temp\cloaca

Esto compilará el proyecto, haciendo que *CMake* llame al compilador
por nosotros.
