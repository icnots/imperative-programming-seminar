# 9. gyakorlat

## Fájlokra tagolás, modulok

C-ben a programjaink függvényekből állnak. A függvényeket külön fájlokba tagolva fordíthatjuk, így csak a módosításainkat kell újra compile-olnunk, majd a végén az összes függvényünket összelinkelni.
Az oldal alján megtalálható egy példakód, aminek a fordítását nézzük meg.
Alapszabály, hogy header fájlokat `.h` sosem fordítjuk, csak include-oljuk. A `.c` fájlokat fordítjuk és sosem include-oljuk.
Végrehajtjuk a preprocesszálást és a compile-olást a `-c` kapcsolóval, majd összelinkeljük a `gcc`-vel.
```bash
 $ gcc -W -Wall -Wextra -pedantic -c main.c
 $ gcc -W -Wall -Wextra -pedantic -c func1.c
 $ gcc -W -Wall -Wextra -pedantic -c func2.c
 $ gcc -W -Wall -Wextra -pedantic -c func3.c
 $ gcc main.o func1.o func2.o func3.o
```
A továbbiakban általában úgy fogunk fordítani, hogy ezeket a lépéseket átugorjuk és szimplán a `gvv`-nek átadjuk a forrásfájlokat (csak a `.c` kiterjesztésű fájlokat!) paraméterül.
```bash
 $ gcc -W -Wall -Wextra -pedantic main.c func1.c func2.c func3.c
```

#### **`main.c`**
```C
#include "func1.h"
#include "func2.h"

int main(){
    func1();
    func2(12);
}
```
> Itt azért van a `main.c`-ben include-olva a két header, mert ezeket használja a függvényünk és minél inkább a legszűkebb részbe szeretnénk tenni az include-okat, pontosan oda, ahol használjuk őket.

#### **`func1.c`**
```C
#include "func1.h"
#include <stdio.h>

int func1(){
    printf("This is func1\n");
}
```
> A `func1` csak a `printf` függvényt használja, ezért van szükség a `stdio.h` include-jára.

#### **`func1.h`**
```C
#ifndef FUNC1_H_INCLUDED
#define FUNC1_H_INCLUDED

int func1();

#endif
```
> A header guard-ot nem felejtjük el!


#### **`func2.c`**
```C
#include "func2.h"
#include "func3.h"
#include <stdio.h>

int func2(int n){
    printf("This is func2 called with parameter %d\n", n);
    if (n > 0){
        func2(n / 2 - 1);
    }else{
        func3(n);
    }
}
```
> A `func2` föggvény használja a `func3` függvényt, így azt ide include-oljuk!

#### **`func2.h`**
```C
#ifndef FUNC2_H_INCLUDED
#define FUNC2_H_INCLUDED

int func2(int n);

#endif
```
> A header guard-ot nem felejtjük el!



#### **`func3.c`**
```C
#include "func3.h"
#include <stdio.h>

int func3(int n){
    printf("This is func3 called with parameter %d\n", n);
}
```
> Itt is csak `printf` használat van, így ennek az include-ja van itt a header-ön kívül.

#### **`func2.h`**
```C
#ifndef FUNC3_H_INCLUDED
#define FUNC3_H_INCLUDED

int func3(int n);

#endif
```
> A header guard-ot nem felejtjük el!
