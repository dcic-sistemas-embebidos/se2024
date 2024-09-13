# Instalación de Toolchain

### Toolchain ESP-IDF
Se puede instalar de dos formas, una como extensión en VSCode y otra como IDE. 
- En el archivo vscode-esp-idf-extension.md se deja una guía de instalación de la extensión en VSCode.
- Para la instalación del IDE se puede usar el instalador esp-idf-tools-2.28 que queda subido en la carpeta de la materia.

### Toolchain PlatformIO
1. Abrir VSCode Extension Manager
2. Buscar la extension oficial [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) 
3. Instalar PlatformIO IDE.

Algo importante a considerar en Windows es que el PATH tiene un límite de tamaño, lo que suele producir errores de compilación. Se aconseja ubicar los proyectos cerca del directorio raíz, por ejemplo, C:\examples\my-project