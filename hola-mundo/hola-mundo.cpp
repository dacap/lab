// El archivo de cabecera con algunas funciones para comunicarse con
// archivos/entrada-salida estándar de C se llama <stdio.h>, y en C++
// podemos (¿es aconsejable?) usar <cstdio>. Esto intentará poner
// todas las funciones dentro de un namespace (espacio de nombres)
// llamado "std", que es algo así como un contenedor de basura: "todas
// las funciones que conocíamos de stdio.h van a estar contenidas
// dentro de std, salvo las macros (como NULL, stdin, stdout, etc.),
// porque las macros son dífíciles"
//
// Link de interés: https://en.cppreference.com/w/cpp/header/cstdio
#include <cstdio>

// La función principal de todo programa se llama main() (esto no es
// cierto en Windows, que también podemos usar wmain(), o WinMain(), o
// wWinMain(), y quién sabe qué más). Cuando el usuario ejecuta el
// programa, las líneas de esta función comienzan a ejecutarse una
// tras otra. Aquí comienzan nuestros problemas.
//
// ¿Por qué esta función devuelve un int? Todos los procesos que se
// ejecutan en el sistema operativo deben devolver un código de
// retorno que puede indicar qué pasó en la ejecución. Abajo más
// detalles.
int main() {
  // Con la función puts() podemos imprimir una línea en la
  // consola/terminal/stdout/salida estándar.
  std::puts("Hola Mundo");

  // Devolver cero (0) significa que no hubo error, y aunque bien
  // sabemos que todos los programas tienen bugs, de vez en cuando
  // podemos mentirle al sistema operativo: "Sí sí, salió todo bien"
  return 0;
}
