# Curso de programación en C


## 1. Introducción

Dennis Ritchie lo inventó 1972. Su propósito era escribir un sistema operativo. El sistema operativo se hizo tan famoso que todavía lo estamos usando, Unix. Mientras hacia investigación con Ken Thompson en Bell Labs en ese momento, fue lanzado como un producto gratuito. Más tarde, el sistema se vuelve muy importante porque era utilizado en computadoras personales pequeñas, y de hecho es la base de Linux y es el mecanismo de bajo del capó detrás del sistema operativo Macintosh. De hecho tan importantes son tanto Ritchie como Thomson que ganaron el premio más alto en ciencias de la computación, que se llama el Turing Award.



## 2. Herramientas:

* Compilador de C
  * gcc gnu compiler, MinGW, visual studio.
* Editor de código
  * Vim, Notepad++, Sublime Text.

### 2.1. Instalación del compilador y editor

1. Instalar el manejador de paquetes [scoop](https://scoop.sh/) siguiendo las instrucciones de la pagina.
2. Instalar el compilador de C utilizando el comando `scoop install gcc`
3. Instalar el un editor con el comando `scoop install notepadplusplus` o `scoop install neovim`
4. Para proyectos grandes instalar la herramienta "make" `scoop install make`.



Nota: en windows hay que especificar el compilador con  `CC=gcc` al principio del archivo `makefile` o `Makefile`. 

### 2.2. Filosofía de trabajo

Write -> Compile -> Debug -> Run



## 3. Compilar

* `gcc filename.c`
  * Retorna un `a.out`
* `gcc -o filename.exe filename.c`
  * Retorna un `filename.exe`
  * `-o` es la bandera de output



## 4. Template

El código base que se utilizara es:

```c
/* Description of the program
 * Author: Ciro Bermudez
 * Date: 00/00/2022
*/
#include <stdio.h>

int main(void){

    return 0;
}
```

* `#include <stdio.h>` es una directiva de preprocesador (pasa antes que el código se compila) para incluir la librería standard input/output, la cual nos da acceso a algunas funciones importantes como `printf()`. La terminación `.h` es porque es un header file.
* El programa principal se ejecuta dentro de la función `int main()`, si no ingresa ningún argumento es preferible poner `void`.
* `return 0;` es para decirle al sistema operativo que el programa se ejecuto sin problemas.
* `void` indica lista de argumentos esta vacía. Si se utiliza como tipo de dato significa que el tipo de dato esta indefinido.



## 5. Conceptos

### 5.0. Comentarios

Para poner comentarios en una línea se utiliza `//` o para comentarios de varias líneas se utiliza `/*  */`

### 5.1. Directivas de preprocesador

#### 5.1.1. #define

La directiva de preprocesador`#define` nos permite la definición de macros, en otras palabras, se utiliza para definir una constante o expresión que se utilizará en el código.. Por convención el nombre de la directiva debe ir en mayúscula. No requiere que termine en punto y coma. Este tipo de definiciones de macro no pueden cambiar su valor como las variables.

```c
#define CNAME value
#define CNAME (expression)
#define NAME "Ciro Bermudez"
#define PI 3.1416
```

#### 5.1.2. #include

La directiva de preprocesador `#include` sirve para incluir un header file. Esta directiva pega una copia del archivo `my_file.h` donde se ponga la directiva durante el proceso de compilación. El `#include` puede ocurrir en cualquier lado del código pero típicamente se pone al principio de los archivos.  Por estos archivos tienen la terminación `.h` el cual proviene de "header file". Este tipo de archivos pueden contener otros `#include` o `#define` dentro de ellos. Ejemplos de este tipos de archivos son:

```c
#include "my_file.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
```



### 5.2. Conversión silenciosa

Cuando realizamos operaciones algebraicas en C podemos realizar operaciones entre diferentes tipos de datos, sin embargo si se realizan operaciones como en el siguiente ejemplo, se realiza una conversión de tipo de dato para que la operación tenga sentido.

```c
kilometers = 1.609 * (miles + yards / 1760.0);
```

Al dividir un `int` entre un `double`, se realiza una conversión implícita a `double` para que el resultado tenga sentido, de ahí en adelante.

### 5.3. Operadores

| Type                         | Operator                                     | Associativity |
| ---------------------------- | -------------------------------------------- | ------------- |
| Primary Expression Operators | `() [] . -> expr++ expr--`                   | left to right |
| Unary Operators              | `* & + - ! ++expr --expr (typescast) sizeof` | right to left |
| Binary Operators             | `* / %`                                      | left to right |
|                              | `+ - `                                       |               |
| (Bitwise)                    | `>> <<`                                      |               |
|                              | `< > <= >=`                                  |               |
|                              | `== !=`                                      |               |
| (Bitwise)                    | `&`                                          |               |
|                              | `^`                                          |               |
|                              | `|`                                          |               |
| (Logical) (short circuit)    | `&&`                                         |               |
|                              | `||`                                         |               |
| Ternary Operator             | `?:`                                         | right to left |
| Assignment Operators         | `= += -= *= %= >>= <<= &= ^= |=`             | right to left |
| Comma                        | `,`                                          | left to right |

Nota: short circuit evaluation es cuando no es necesario realizar más comprobaciones cuando se sabe que es falso. `A && B`. Si a es falsa ya no se comprueba lo que tenga B, es falso.

#### 5.3.1.  &

El operador `&` significa, la dirección de, entonces cuando utilizamos la función `scan("%d", &celsius)` el operador `&` dice, guarda la entrada del usuario en la dirección de memoria de celsius. "almacenar en la ubicación de la variable".

#### 5.3.2 Coma ,

El operador coma nos permite hacer secuencia de operaciones, por ejemplo se utiliza en la asignación de valor de variables.

```c
int a = 10, b = 3;
c = (a = 10, b = 20);   // c sera 20
```

Se utiliza mucho para asignar los valores iniciales en un ciclo for.

```c
for(sum = 0, i = 0; i < 10; i++){
    statements
}
```

#### 5.3.3. Casting

Convertir un tipo de dato a otro se llama casting,  La precedencia del operador cast es una de las más altas por lo que si queremos que el resultado de dividir dos enteros sea un flotante podemos hacer lo siguiente:

```c
int a = 17; b = 5;
double c;
c = (double) a / b;
```

Como el cast tiene una precedencia mayor que la división,  `a` se convierte en un `double`, y al realizarse la división de un `double` entre un `int` se hará la conversión implícita a `double` y el resultado será `3.4000`. Si no se hace el cast, el resultado de la división es un `int` con el valor de`3` y al realizar la conversión implícita por la asignación al tipo de dato se convierte en `3.0000` .





### 5.4. Tipos de datos

| Tipo     | Formato | Tamaño  | Nombre          |
| -------- | ------- | ------- | --------------- |
| `char`   | `%c`    | 1 byte  | Caracteres      |
| `int`    | `%d`    | 4 bytes | Enteros         |
| `float`  | `%f`    | 4 bytes | Flotantes       |
| `double` | `%lf`   | 8 bytes | Doble presición |
| `void`   |         | 0 bytes | Vacío           |

Para conocer el tamaño en bytes de una variable o un tipo podemos utilizar el operador `sizeof`

#### 5.4.1. Modificadores

| Modificadores |
| ------------- |
| `short`       |
| `long`        |
| `unsigned`    |
| `signed`      |
| `const`       |

#### 5.4.2. Tabla completa

| **Data Type**         | **Format Specifier** | **Minimal Range**                                            | **Typical Bit Size** |
| --------------------- | -------------------- | ------------------------------------------------------------ | -------------------- |
| unsigned char         | %c                   | 0 to 255                                                     | 8                    |
| char                  | %c                   | -127 to 127                                                  | 8                    |
| signed char           | %c                   | -127 to 127                                                  | 8                    |
| int                   | %d, %i               | -32,767 to 32,767                                            | 16 or 32             |
| unsigned int          | %u                   | 0 to 65,535                                                  | 16 or 32             |
| signed int            | %d, %i               | Same as int                                                  | Same as int16 or 32  |
| short int             | %hd                  | -32,767 to 32,767                                            | 16                   |
| unsigned short int    | %hu                  | 0 to 65,535                                                  | 16                   |
| signed short int      | %hd                  | Same as short int                                            | 16                   |
| long int              | %ld, %li             | -2,147,483,647 to 2,147,483,647                              | 32                   |
| long long int         | %lld, %lli           | -(263 – 1) to 263 – 1 (It will be added by the C99 standard) | 64                   |
| signed long int       | %ld, %li             | Same as long int                                             | 32                   |
| unsigned long int     | %lu                  | 0 to 4,294,967,295                                           | 32                   |
| unsigned longlong int | %llu                 | 264 – 1 (It will be added by the C99 standard)               | 64                   |
| float                 | %f                   | 1E-37 to 1E+37 along with six digits of the precisions here  | 32                   |
| double                | %lf                  | 1E-37 to 1E+37 along with six digits of the precisions here  | 64                   |
| long double           | %Lf                  | 1E-37 to 1E+37 along with six digits of the precisions here  | 80                   |

### 5.5. Palabras reservadas

32 Palabras reservadas

| `auto`     | `else`   | `long`     | `switch`   |
| ---------- | -------- | ---------- | ---------- |
| `break`    | `enum`   | `register` | `typedef`  |
| `case`     | `extern` | `return`   | `union`    |
| `char`     | `float`  | `short`    | `unsigned` |
| `const`    | `for`    | `signed`   | `void`     |
| `continue` | `goto`   | `sizeof`   | `volatile` |
| `default`  | `if`     | `static`   | `while`    |
| `do`       | `int`    | `struct`   | `double`   |

`auto` , `goto`, `register`, ya no se ocupan.

Para más información dirigirse a la siguiente página [Keyword tigcc](http://tigcc.ticalc.org/doc/keywords.html)

### 5.6. Identificadores

La palabra `main` en la estructura básica de nuestros programas, es un identificador. Para que un código sea fácil de leer y  sea auto documentado es necesario conocer algunas de las reglas para escoger el nombre de los identificadores. Podemos utilizar la siguiente ecuación de sintaxis para eso:

`id ::= {letter | underscore} <1> {letter | undersocre | digit} <0+>  `

Los identificadores no deben ser muy grandes, hay que tener cuidado que no sea alguna de las palabras reservadas. `<1>` significa al menos uno, y `<0+>` significa 0 o más. Estos son algunos ejemplos:

```c
_printf()
two_words
twoWords
my_dna    
```



### 5.7. Expresiones y precedencia

Es importante como funcionan los operadores para conocer el orden y la precedencia en la que se evalúan. También es importante notar la diferencia entre declarar una variable e inicializarla con algún valor o asignarle un valor.

```c
int c;        // la variable c esta siendo declarada
int a = 1;	  // la variable a esta siendo declarada e inicializada con el valor de 1
int b = 2;	  // la variable b esta siendo declarada e inicializada con el valor de 2
c = a + b;    // expresion de asignacion para la variable c
```

Hay 16 niveles de precedencia,  el orden en que se presentan en la tabla de los operadores es el orden de precedencia que tienen los operadores. La asociatividad es importante para saber qué operaciones se realizan primero. Si son sumas, restas, multiplicaciones y divisiones simples se ejecutan de izquierda a derecha.

#### 5.7.1. Expresión y evalución

Si las expresiones se vuelven muy complicadas es buena practica utilizar paréntesis manualmente para dejar claro la precedencia de las operaciones. 

`3/7 = 0`La división de dos enteros resulta en un entero. 

`3/7 = 2`La división de dos enteros resulta en un entero. 

`5/2.0 = 2`La división de un entero entre un flotante resulta en un flotante.

Otra cosa importante es tener presente el orden de los incrementos y decrementos.

`a = ++b;` es lo mismo que `b = b+1; a = b;` leído de izquierda a derecha

`a = b++;` es lo mismo que `a = b; b = b+1;` leído de izquierda a derecha

### 5.7.2. Tipos de declaraciones

- **Declaration** of a variable or function simply declares that the variable or function exists somewhere in the program, but the memory is not allocated for them. The declaration of a variable or function serves an important role–it tells the program what its type is going to be. In case of *function* declarations, it also tells the program the arguments, their data types, the order of those arguments, and the return type of the function. So that’s all about the declaration.
- Coming to the **definition**, when we *define* a variable or function, in addition to everything that a declaration does, it also allocates memory for that variable or function. Therefore, we can think of definition as a superset of the declaration (or declaration as a subset of definition).

- A variable is **declared** when the compiler is informed that a variable exists (and this is its type); it does not allocate the storage for the variable at that point.
- A variable is **defined** when the compiler allocates the storage for the variable.

Para declarar una variable se requiere el tipo y el identificador. `type id;`. También se pueden inicializar en la misma línea `type id = value;`.  Ejemplos:

```c
int = a;					// Declaracion
int a = 3;                  // Declaracion e inicializacion
int a = 3, b = 5;           // Declaracion e inicializacion en lista
```

Siempre es buena practica inicializar las variables y no dejar que el compilar les asigne un valor por defecto. Es bueno inicializar en este aspecto con un cero para tener certeza del valor.

### 5.8. Sintaxis

#### 5.8.1. Sentencia if

Cero significa "falso" y cualquier otra cosa que no sea cero "verdadero".

```c
if(condition)
    statement
else
    statement
    
if(condition){
    statements
}else{
    statements
}
```

#### 5.8.2. Sentencia while

```c
while(condition){
    statements
}

for(;;){
    statements
}
```

#### 5.8.3. Sentencia for

```c
for(int i = 0; i < 10; i++){
    statements
}
```

#### 5.8.4. Operador ternario

Tiene una precedencia muy baja.

```c
statemet ? Statement_if_true : Statement_if_false;
x = statemet ? Statement_if_true : Statement_if_false;
```

#### 5.8.5 Sentencia switch case

Todos los `cases` necesitan la sentencia `break`, excepto `default`. Si no se pone la sentencia `break` se ejecutan cada uno de los casos de manera consecutiva. La variable debe ser de tipo `int` o sus derivados, no puede ser de tipo flotante.

```c
switch (variable){
    case 1: 
        do_something;
        break;
    case 2:
        do_something;
        break;
    default:
        do_something;   
}
```





## 6. Redireccionamiento input/output

Cuando estamos trabajando con la terminal en ocasiones es conveniente pasar el contenido de un archivo de texto como la entrada para nuestro programa. Por ejemplo tenemos un programa llamado `calculate.exe` el cual acepta del usuario números que se ingresan manualmente. Pasar manualmente 3 números es fácil pero 100 no tanto. Lo mismo ocurre cuando queremos copiar la salida de la terminal para tener un registro `.log` de nuestro programa, copiar y pegar unas cuantas líneas en un archivo de texto es fácil pero unas miles no tanto. Para esto utilizamos el redirecionamiento.

En sistemas Unix y el CMD de windows podemos utilizar la siguiente línea de código para realizar el direccionamiento de la entrada. y posteriormente mandar el resultado a un archivo de texto.

```bash
calculate.exe < input.txt > output.txt
```

Si se esta trabajando con el powershell desafortunadamente se requiere utilizar un comando diferente pero la lógica no cambia drásticamente.

```powershell
Get-Content input.txt | ./calculate.exe > salida.txt
```

La única diferencia es que ahora es necesario pasar la entrada antes utilizando un piped, pero la redirección de salida es la misma.

`EOF` es `Ctrl + Z` en windows y `Ctrl + D` en Unix

Un `\n` siempre se agrega al final de los archivos de texto en automático por los editores de código para evitar problemas de compatibilidad y porque los documentos deben tener siempre al menos una linea



## 7. Funciones

Las funciones en C son un de los temas más importantes ya que la programación en C es funcional y no orientada a objetos, aun teniendo en cuenta que tenemos acceso a estructuras más complejas con `struct`.

Lo primero que hay que saber de las funciones es que es buena practica poner el "prototipo de función" debajo de las declaraciones `#include` y `#define`,  Un prototipo de función puede verse de la siguiente manera:

```c
double pow(double x, double n);
double pow(double , double);
void print_table(void);
int print_stuff(const char *format, ...);
```

Se define el tipo de dato que retorna la función y el tipo de dato de los argumentos. No es necesario poner el nombre de las variables de entrada, solo el tipo, pero es buena practica ponerlos porque es una documentación adicional. Si no se tiene claro el número de datos de entrada se puede poner, "ellipses" en código `...`.

Una función necesita un tipo, un nombre y si no es `void`  un valor que retornar.

```c
double function_name(double var1, double var2){
    statements;
    return something;
}
```

La sentencias `return` usarse de distintas maneras, por ejemplo  `return 0;` o `return (0);`. Cualquiera de los dos es valido.

Cuando se crean variables dentro de las funciones, esas variables son locales y únicamente la función tiene acceso a ellas a menos que se retornen por la sentencia `return`. El alcance de las variables se llama el"scope" de la varible.

#### 7.1. Call by Value

Si tenemos una función como la siguiente `double sqrt(double x)`, cuando pasamos una variable, por ejemplo `double a` como argumento, estamos pasando una **copia** del valor de la variable, una `a_local`, de manera que si dentro de la función se modifica el valor de la variable, por ejemplo `a = a + 1`, se modifica el valor de la copia y no de la variable que se esta pasando como valor. En resumen cuando se pasa un parámetro por valor únicamente se pasa una copia el valor. Si se desea cambiar el valor de la variable es necesario pasar la variable por referencia. La variable se crea y se destruye cuando se invoca y retorna un valor la función.

#### 7.2. Call by reference

El llamado de una función por referencia utiliza apuntadores, en otras palabras pide la dirección de la variable. Por ejemplo la función para solicitar información del usuario `scanf("%d", &size);` solicita la dirección en memoria de la variable y utilizando dereferenciación puede modificar el valor de la variable dentro de la 

`*` derefenciar / acceder al contenido de la dirección de memoria

`&` dirección de

En resumen pasar por referencia es pasar una dirección. Esto es para trabajar directamente con la dirección de memoria y poder modificar su valor utilizando dereferenciación.

Cuando creemos funciones con arreglos la función debe estar descrita por ejemplo:

```c
double average(int size, double grades[]){
    
}

double average(int size, double *grades){
    
}
```



   

#### 7.3 Recursión

```c
void count(int n){
    while( n > 0 ){
        printf("time is %d\n", n);
        n--;
    }
    printf("Blast off\n");
}

void recursive_count(int n){
    if(n == 0){
        printf("Blast off\n");
    }else{
        printf("time is %d\n",n);
        recursive_count(n-1);
    }
}
```



```c
long int factorial(int n){
    long f = 1;
    int i;
    for(i = 1; i <= n; i++){
        f = f * i;
    }
    return f;
}

long int recursive_factorial(int n){
    if(n == 1)
        return 1;
    else
        return ( recursive_factorial( n - 1 )*n );
}
```



```c
long fibonacci(int n){
    long f2 = 0, f1 = 1; f_old;
    int i;
    for(i = 0; i < n; i++){
        fold = f2;
        f2 = f1 + f2;
        f1 = fold;
    }
    return f2;
}

long recursive_fibonacci(int n){
    if(n <= 1)
        return n;
    else
     
```



#### 7.4. Scope

Un "bloque" se crea cuando abrimos y cerramos un par de llaves. Lo anterior es importante para saber el tiempo de vida de las variables cuando se crea una variable dentro del bloque. Cuando se termine ese bloque la variable deja de existir para bloques exteriores. Por ejemplo:

```c
int main(void){
    int i = 0;
        for(i = 0; i < 10; i++){
            int j = 1;
            statements
        }
    printf("%d",j);
    return 0;
}
```

En el código anterior la variable `j` deja de existir en el momento que termina el bucle for, y al momento de compilación se genera un error.

Otra punto importante a tener en cuenta es cuando se crean variables con el mismo nombre pero en diferentes scopes.

```c
{
    int i = 5;
    {
        int i = 7;
        int j = 3; 
    }
}
```

En el código de arriba se muestra como en un bloque interior se vuelve a crear la variable `i`, tenemos permitido hacer eso, sin embargo dentro del bloque interno, solo podemos ver que `i = 7`, en otras palabras solo podemos ver la `i` interior. No hay manera de ver la `i` exterior dentro de ese bloque. La `i` interna tiene preferencia, pero cuando se termine ese bloque, `i` volverá a tener el valor de la `i` exterior.

Cuando se declara una variable se ponen en algo llamado `stack`.  Es una manera interna que el compilador maneja el almacenar las variables. Eso también esta relacionado con el `heap`.

##### 7.4.1. Storage classes

Usamos la clase de almacenamiento en el lenguaje C para determinar la visibilidad, el tiempo de vida, el valor inicial y la ubicación de la memoria de cualquier variable dada. Las clases de almacenamiento definen la visibilidad (alcance/scope) y el tiempo de vida de cualquier función/variable dentro de un programa C. Estas clases preceden al tipo que van a modificar. La clase de almacenamiento determina la vida útil, la visibilidad y también su alcance de esa variable.

| **Class** | **Name of Class** | **Place of Storage** | **Scope**              | **Default Value** | **Lifetime**        |
| --------- | ----------------- | -------------------- | ---------------------- | ----------------- | ------------------- |
| auto      | Automatic         | RAM, stack           | Local, within block    | Garbage Value     | End of block        |
| extern    | External          | RAM, data segment    | Global, multiple files | Zero              | Till end of program |
| static    | Static            | RAM, data segment    | Local, within block    | Zero              | Till end of program |
| register  | Register          | Register             | Local, within block    | Garbage Value     | End of block        |

1. **auto**: This is the default storage class for all the variables declared inside a function or a block. Hence, the keyword auto is rarely used while writing programs in C language. Auto variables can be only accessed within the block/function they have been declared and not outside them (which defines their scope). Of course, these can be accessed within nested blocks within the parent block/function in which the auto variable was declared. However, they can be accessed outside their scope as well using the concept of pointers given here by pointing to the very exact memory location where the variables reside. They are assigned a garbage value by default whenever they are declared. 
   
2. **extern**: Extern storage class simply tells us that the variable is defined elsewhere and not within the same block where it is used. Basically, the value is assigned to it in a different block and this can be overwritten/changed in a different block as well. So an extern variable is nothing but a global variable initialized with a legal value where it is declared in order to be used elsewhere. It can be accessed within any function/block. Also, a normal global variable can be made extern as well by placing the ‘extern’ keyword before its declaration/definition in any function/block. This basically signifies that we are not initializing a new variable but instead we are using/accessing the global variable only. The main purpose of using extern variables is that they can be accessed between two different files which are part of a large program. For more information on how extern variables work, have a look at this [link](https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/). 
3. **static**: This storage class is used to declare static variables which are popularly used while writing programs in C language. Static variables have the property of preserving their value even after they are out of their scope! Hence, static variables preserve the value of their last use in their scope. So we can say that they are initialized only once and exist till the termination of the program. Thus, no new memory is allocated because they are not re-declared. Their scope is local to the function to which they were defined. Global static variables can be accessed anywhere in the program. By default, they are assigned the value 0 by the compiler. ljk
4. **register**: This storage class declares register variables that have the same functionality as that of the auto variables. The only difference is that the compiler tries to store these variables in the register of the microprocessor if a free registration is available. This makes the use of register variables to be much faster than that of the variables stored in the memory during the runtime of the program. If a free registration is not available, these are then stored in the memory only. Usually few variables which are to be accessed very frequently in a program are declared with the register keyword which improves the running time of the program. An important and interesting point to be noted here is that we cannot obtain the address of a register variable using pointers. 



## 8.  Arrays, strings y pointers

### 8.1. Arreglos

Los arreglos se usan cuando muchas variables del mismo tipo son deseadas. El nombre de un arreglo por si mismo es un apuntador. Un ejemplo de arreglo es el siguiente `int a[3];`. Asigna el espacio para el arreglo de tres elementos `a`. Para indexar los elementos del arreglo se comienza desde `a[0]`, hasta `a[2]`, los arreglos siempre comienzan desde el índice `array_name[0]`. El número de elementos del arreglo debe ser de tipo `cont int`.

Ejemplos de arrays:

```c
int data[5];
int data[5] = {1,2,3,4,5},
int data[5] = {0};
int data[] = {1,2,3,4,5};
```

Un arreglo tiene un lugar donde esta almacenado y empieza en lo que se conoce como su "dirección base". Después tiene continuamente el número de elementos del arreglo en memoria.



Unlike many programming languages an array name in C is just a pointer to a base address and there is no way to know its size.  

### 8.2. String

Un string es una cadena de caracteres. Por ejemplo la cadena "ab" tiene tres caracteres, a,b,\0.

`\0` se conoce como el carácter centinela o guarda, también como carácter nulo. Por convención toda string debe terminar con un carácter nulo.

Para crear un string podemos hacer los siguiente:

```c
char str[] = "abc";
```

entonces `str[0]` es `'a'` y `str[3]` es `'\0'`.

Macros importantes para trabajar con strings son: `getchar()` y `putchar()`, se utilizan para leer caracteres desde el teclado y para imprimir esos caracteres en pantalla.



### 8.3. Apuntadores (pointers)

Un apuntador es solo una dirección de un objeto en memoria. Es importe entender la aritmética de apuntadores el cual es uno de los temas mas importantes en el lenguaje C,

Para declarar un apuntador se hace de la siguiente manera:

```c
int a = 10;
int *p = &a;
```

El apuntador debe ser del mismo que la variable a la que apunta. `&a` significa la dirección de `a`, y `*p` significa que `p` será de tipo apuntador y almacena la dirección donde esta guardada la variable `a`.

El carácter especial `*` sirve para especificar que la variable será de tipo apuntador.

Una vez que el apuntador es creado podemos ver la dirección de memoria de `a`, imprimiendo en pantalla `p`, por ejemplo `printf("%p",p);`.  Se vería una dirección en hexadecimal, también podemos, imprimirlo como `%lu.`

Si queremos ver el valor que tiene la variable `a` podemos resdeferenciar `p`, de la siguiente manera `printf("%d",*p);` . Imprimiría el valor de 10. 

Desreferenciar significa obtener el valor de la dirección.

El nombre de un arreglo por si mismo es un apuntador a la dirección base del arreglo.



#### 8.3.1 Aritmética de direcciones

Por ejemplos si tenemos un arreglo de la siguiente manera:

```c
int data[4] = {2,4,6,8};
```

el tipo `int` tiene un tamaño de 4 bytes, de manera que si por ejemplo `data[0]` se encuentra en la dirección 7006, `data[1]` se encuentra en la dirección 7010, y `data[3]` en la dirección 7018. de manera que la aritmética de direcciones se puede hacer con la ecuación 

dirección del elemento = dirección base + (tamaño del tipo de dato)*elemento.

Como el nombre un arreglo por si mismo es un apuntador, si imprimimos el nombre del arreglo nos dará la dirección base del arreglo, si sumamos 3 al arreglo, nos dará la dirección en donde se almaceno el tercer elemento del arreglo.

Otra manera de verlo es que `data` es igual a `&data[0]`, y `data + 1` es igual a `&data[1]`

Otra cosa importante es que `data[i]` es igual a `*(data + i)`

De mismo modo `data[]` es igual a `*data`.





## 9. Tipos definidos por el usuario

### 9.1. Enum

Los tipos nativos en C son por ejemplo: `int`, `float`, `char`, sin embargo podríamos tener tipos de datos diferentes que nos ayuden a resolver problemas de una mejor manera. Un ejemplo clásico es pensar en los números complejos como un tipo de dato nuevo, o los días de la semana. Tener tipos nuevos permite al compilador hacer chequeos de tipos de dato, y hacer hacer debuging más fácil. C es un lenguaje considerado de tipeo "weak" , debido a todas las conversiones que existen, las cuales son convenientes en muchos casos, pero hay que tener cuidado para evitar errors, por ejemplo en C no existe el tipo booleano, y comprueba que una expresión es verdadera si no es cero. Si una evaluación se realizó correctamente, el resultado es 1. Type safety es importante. 

Para crear tipos definidos por el usuario utilizamos la palabra reservada `enum`. Por ejemplo podemos hacer lo siguiente:

```c
enum WeekDays {MON, TUE, WED, THU, FRI, SAT, SUN};
```

Creamos el tipo de dato `day`, cuyo domino es `MON, TUE, WED, THU, FRI, SAT, SUN`. Por convención se pone la primera en mayúscula. C les asigna un valor a cada uno de los elementos. Es decir `MON = 0`, `TUE = 1`, `WED = 2`, hasta `SUN = 6`. Secretamente son constantes enteras.

Para crear una variable de este nuevo tipo de dato, lo hacemos de la siguiente manera:

```c
enum WeekDays today;
today = MON;
```

Para crear una función de este nuevo tipo lo hacemos de la siguiente manera:

```c
enum WeekDays next_day(enum WeekDays any_day){
    return (any_day + 1) % 7;
}
```

Podemos ahorrarnos mucho trabajo si utilizamos la sentencia `typedef` de la siguiente manera:

```c
enum WeekDays {MON, TUE, WED, THU, FRI, SAT, SUN};
typedef enum WeekDays WeekDays;
```

Entonces tanto la declaración y definición de la variable como la función las podríamos simplificar de la siguiente manera:

```c
WeekDays today;
today = MON;

WeekDays next_day(WeekDays any_day){
    return (any_day + 1) % 7;
}
```

En otras palabras, utilizando `typedef` regresamos a la manera tradicional.



## 10. Prepocesador

* Link in standard files
* Macro expansion 
* Incluir librerías con `#define`
  * `#include <stdio.h>`
  * `#include <stdlib.h>`
  * `#include <math.h>`
  * `#include <time.h>`
  * `#include <ctype.h>`
    * Contiene funciones importantes como `isalpha(c)`, `isspace(c)`, `isdigit(c)`, `islower()`, `toupper(c)`.
  * `#include <assert.h>`
    * Es muy importante porque no permite hacer debug de nuestros códigos.
    * Tenemos acceso a `assert()`, evalúa una expresión, si es verdadera continua el código, sino aborta.
    * Si utilizamos `#define NDEBUG` desactivamos todos los asserts sin tener que comentarlos.
    * gcc -DNDEBUG
  * `#include "mycode.h"`

* Macros con `#define`
  * `#define C_KM_S 299792.458 `
  * `#define EQ ==`
  * `#define SQ(x) ((x)*(x)`
* gcc -E file.c expad macros para el código despues de las expansiones



## 11. Structures - Abstracts Data Types (ADT)  

### 11.1. Struct / typedef

Es un tipo definido por el usuario. Los tipos de dato son muy importantes para la solución de un problema ya que nos permiten modelar de una manera más sencilla el objeto u objetos del mundo real. Para entenderlo de mejor manera utilizaremos el siguiente ejemplo: Si queremos programar un juego de cartas o representar números complejos hay que crear una manera coherente de encapsular la información. 

```c
/* Form 1*/
struct card {
    int pips;   /*1-13*/
    char suit;  /*type of card*/
};

struct card deck[52];


/* Form 2*/
struct card {
    int pips;   /*1-13*/
    char suit;  /*type of card*/
} deck[52];

/*Form 3*/
struct complex {  
    float re;   /*1-13*/
    float im;  /*type of card*/
} 
typedef struct complex complex;
complex a, b, c[10];

/*Form 4*/
typedef struct complex {  // tag_name is optional
    float re;   /*1-13*/
    float im;  /*type of card*/
} complex; 

complex a, b, c[10];
```

En el código anterior se muestran diversas maneras de describir una estructura y de instanciar una estructura. De mismo modo se muestran ejemplos de como utilizar la sentencia `typedef` para hacer más sencilla la redacción del código. Se puede instanciar la estructura con valores iniciales de la siguiente manera `complex c1 = {1.1, 2.2};`.

Para acceder a los elementos de la estructura existen dos maneras. La primera es utilizando el operador punto `.` y la segunda utilizando el operador flecha `->` y apuntadores .Veamos el siguiente código:

```c
struct complex {  
    float re;   /*1-13*/
    float im;  /*type of card*/
} 
typedef struct complex complex;

// complex c1 = {1.1, 2.2};
complex c1;
c1.re = 1.1;
c1.im = 2.2;

printf("re = %lf im = %lf\n", c1.re, c1.im);

```



Ahora utilizando apuntadores:

 ```c
 struct complex {  
     float re;   /*1-13*/
     float im;  /*type of card*/
 } 
 typedef struct complex complex;
 
 //complex c1 = {1.1, 2.2};
 complex c1;
 complex *ptc;
 ptc = &c1;
 ptc -> re = 1.1;
 ptc -> im = 2.2;
 
 printf("with pointers\n");
 printf("re = %lf im = %lf\n", ptc -> re, ptc -> im);
 
 ```



El operador `->` significa "el valor de", y necesita del lado izquierdo una dirección de memoria, en otras palabras un apuntador, a diferencia de el operador punto que necesita una variable del lado izquierdo. `foo->bar` es equivalente a `(*foo).bar`

```c
struct foo
{
  int x;    // miembro
  float y;
};

struct foo var;
struct foo *pvar;
pvar = malloc(sizeof(struct foo));

var.x = 5;
(&var)->y = 14.3;
pvar->y = 22.4;
(*pvar).x = 6;
```



### 11.2. Stack (pila/montón)

El stack tiene la filosofía LIFO (Last In First Out) y es una estructura de datos canónica no trivial, que aparece mucho en algoritmos y arquitecturas de computadoras. 

Hay distintas operaciones que pueden realizarse sobre esta estructura de datos: }

* Push: Meter un elemento de arriba.
* Pop: Sacar un elemento de arriba.
* Top: Ver el tope del stack
* Empty: Ver si esta vacia
* Full: Ver si esta llena
* Reset: Reiniciar

Por ejemplo un stack de libros, tomas un libro del tope, y guando lo dejas de utilizar lo vuelves a poner en el tope. Sirve mucho para invertir una lista.

```c
/* Description of the program
 * Author: Ciro Bermudez
*/
#include <stdio.h>
#define MAX_LEN   1000
#define EMPTY      -1
#define FULL      (MAX_LEN - 1)

enum boolean {false, true};

struct stack {
    char s[MAX_LEN];
    int top;
};

typedef enum boolean boolean;
typedef struct stack stack;

void reset(stack *stkp){
    stkp -> top = EMPTY;
}

void push(char c, stack *stkp){
    //(stkp -> top)++;
    stkp -> s[++(stkp -> top)] = c;
}

char pop(stack *stkp){
    return stkp -> s[(stkp -> top)--];
}

char top(const stack *stkp){
    return stkp -> s[stkp -> top];
}

boolean empty(const stack *stkp){
    return (boolean)(stkp -> top == EMPTY);
}

boolean full(const stack *stkp){
    return (boolean)(stkp -> top == FULL);
}

int main(void){

    char str[] = "My name is Ciro Bermudez";
    int i;
    stack s1;
    reset(&s1);
    printf(" In the string: %s\n",str);
    for (i = 0; str[i] != '\0'; i++){
        if ( !full(&s1) ){
            push(str[i], &s1);
        }
    }
    printf(" From the stack: ");
    while ( !empty(&s1) ){
       // putchar( top(&s1) );
       // pop(&s1);
        putchar( pop(&s1) );
    }
    putchar('\n');

    return 0;
}
```



### 11.3. Listas ligadas (link list  )

Es un self-referential struct, es recursiva. Una lista tiene una cabeza "head" que apunta a un elemento, que a su vez apunta a otro elemento, y así sucesivamente hasta llegar al final de la lista, o "tail", un centinela. El head es el inicio de la lista ligada y el tail es el final. Se utiliza `malloc()` , la cual se encuentra en `#include <stdlib.h>`, esta función va a un lugar especial llamado  "heap", que es una pilla de almacenamiento disponible para la rutina C, que es dinámica, así que se puede usar en cualquier momento en el trascurso del programa. Cuando llamamos a `malloc()` pedimos un tamaño particular como `int` 4 bytes. `malloc()` retorna un apuntador y ese apuntador puede utilizarse para inicializar lo que sea. Si se utiliza mucha memoria es buena practica regresar la memoria o liberarla.



## 12. Random numbers in C

Para utilizar números aleatorios en C se utiliza la función `rand()` la cual se encuentra en la librería `#include <stdlib.h>`. La función genera números desde 0 hasta `RAND_MAX`, sin embargo para generar números aleatorios en un rango determinado podemos utilizar la siguiente ecuación: `num = (rand() % (upper - lower + 1)) + lower`.

Si ejecutamos la función `rand()` en el mismo programa de C nos daremos cuenta que a pesar de generar los números aleatorios correctamente, siempre son los mismo, para que esto no ocurra hay que sembrar el generador de números aleatorios con una semilla. Para esto tradicionalmente utilizamos la función `srand(time(NULL))`. La función `time(NULL)` nos entrega el tiempo recorrido desde 1 de enero de 1970 hasta el día de hoy. Este valor siempre es diferente y por eso se utiliza como semilla para la función `srand()`. Basta con sembrar una vez el generador para tener siempre números aleatorios diferentes.



## 13. C++

1. C es esencialmente un subconjunto de C++;
2. C++ tiene mejoras que haces que sea más fácil.
3. Se compila utilizando `g++`

De invento en Los laboratorios Bell en 1095 por BJarne Stroustrup, el lo llamaba C con clases.

Se tiene acceso a vectores, el cual es una generalización de los arreglos. Es un arreglo eficiente y flexible.

La palabra reservada `auto` ahora se utiliza para que el compilador infiera el tipo de dato. Esta es una diferencia con respecto a `C`.

`inline` es una palabra reservada que se utiliza para crear macros y es un sustituto de `#define` en C.

C++ is a better C.

Algo importante de C++ es que intenta utilizar el preprocesador menos.

El concepto de `namespace`





## 14. Clases

Algo muy importante en la programación moderna es la encapsulación, y la encapsulación nos permite esconder las cosas. Por ejemplo trabajando con un auto, hay cosas en el motor que solo un mecánico debería poder acceder, en otras palabras, no es para ser manipulado por los demás. La podemos llamar una caja negra, todavía podríamos utilizar el auto si sabemos como manejarlo, y esto mismo ocurre en las clases. C++ toma el concepto de estructura y agrega ideas que permiten mayor encapsulación.







`inline` le dice al compilador que trate de optimizar una función

## 18. Recursos

`int main(int argc, char **argv)`

`int main(int argc, char *argv[])`

## Links

* https://sourceforge.net/p/predef/wiki/Standards/
* 
