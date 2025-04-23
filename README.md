# Thomas Shellby — Simple Shell

Este proyecto es una implementación básica de un shell hecho en C, desarrollado como parte del programa de Holberton School. Simula el comportamiento de un shell tipo Unix, interpretando y ejecutando comandos en modo interactivo o desde scripts.

## Características

- Modo interactivo con prompt personalizado: `Thomas Shellby $`
- Ejecución de comandos con argumentos (como `ls -l`)
- Soporte para rutas absolutas y relativas
- Comando `exit` para cerrar el shell
- Manejo de `Ctrl + D` para salir limpiamente
- Built-in `env` para mostrar el entorno del sistema

## Cómo compilar

Usar el siguiente comando en una terminal (compilador `gcc`, estándar `gnu89`):

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Ejecución
Modo interactivo:

```bash
./hsh
Thomas Shellby $ ls -l
Thomas Shellby $ exit
```

Modo no interactivo

```bash
echo "ls -l" | ./hsh
```

## Estructura del Proyecto

El proyecto está dividido en los siguientes archivos:

- **`main.h`**: Contiene los prototipos de funciones necesarias para el proyecto y la declaración de la variable `environ`.
- **`exec.c`**: Implementa la función `execute_command` para ejecutar comandos usando `execve` y el PATH del sistema.
- **`shell.c`**: Contiene el `main` que lee los comandos, los tokeniza con `strtok`, maneja la memoria y llama a `execute_command`.
- **`utils.c`**: Contiene funciones auxiliares como `print_prompt`, `clean_newline` y `exit_shell`.

## Autores
- [**Gaston Dominguez**](https://github.com/gastii11)

- [**Agustin Lahalo**](https://github.com/Agustin800)
