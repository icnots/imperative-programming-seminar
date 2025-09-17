# 2. Gyakorlat, példaprogramok

## Változók

### Változótípusok

Egy változónak a típusán azt értjük, hogy a számítógép hogyan kezelje az adott memóriarészt, ami a változóhoz tartozik. Ez meghatározza a változó területét (hány bájtot foglal) és azt, hogy mit tudunk vele csinálni. Néhány példa a teljesség igénye nélkül:
* `char`
* `int`
* `float`
* `double`

### Változó deklaráció

A változókat a típusukkal ellátva névvel tudunk deklarálni, pl.: `int i;`. Egyszerre több változót is deklarálhatunk, ha azonos típust szeretnénk nekik adni, pl.: `char c1, c2;`. A változó neve mindenképpen betűvel, számmal vagy aláhúzással kezdődik, nem lehet foglalt kulcsszó.

### Változó definíció

A változóknak értékeket adhatunk az `=` operátor használatával, pl.: `i = 0;` vagy `c1 = 'a'`.

> - A változók deklarációját és definícióját egyszerre is írhatjuk, pl.:
`int i = 0;` vagy `char c1 = 'a', c2 = 'b';`

## Elágazások

A C nyelvben elágazásra az `if`-et használjuk opcionálisan else ággal kiegészülve.
```
if (0 < 1){
    /* ha igaz a feltétel */
}else{
    /* ha nem igaz a feltétel */
}
```

A blokkok helyett használható egy parancs is. A következő kód esetén a `parancs2()` függvény mindenképpen lefut, függetlenül az `n` változó értékétől.
```
if (n > 0)
    parancs1();
    parancs2();
```

Ezt használva tudunk `else if` ágakat írni, amennyiben többféle feltételt akarunk megvizsgálni. (Az `if` is egy parancsnak tekinthető.)
```
if (n > 0){
    return 1;
}else if (n < 0){
    return -1;
}else{
    return 0;
}
```


## Ciklusok

Amikor egy kódrészt többször szeretnénk futtatni, általában másolás helyett ciklusokat használunk.

### For loop

A fejléce három részre oszlik:
* 1. inicializáló rész, egyszer fut le a loop indulásakor
* 2. feltétel, amelynek minden törzs futása előtt teljesülnie kell
* 3. léptető rész, amely a törzs futása után fut le minden alkalommal.
```
for (i = 0; i < 10; i++){
    /* loop törzse */
}
```

### While loop

Addig fut a törzse, amíg a feltétel igaz. Az első lefutás előtt is megvizsgálja a feltétel teljesülését.
```
while (0 < 1){ /* 0 < 1 helyén a feltétel */
    /* loop törzse */
}
```

### Do while loop

Addig fut a törzse, amíg a feltétel igaz. Az első lefutás után vizsgálja meg először a feltétel teljesülését.
```
do {
    /* loop törzse */
} while (0 < 1); /* 0 < 1 helyén a feltétel */
```

## Beépített operátor

A `sizeof` egy operátor, amely megadja egy típus vagy egy objektum méretét bájtokban. A paramétere lehet egy adott típus vagy egy adott változó is. Pl.: `sizeof(int)` vagy `sizeof(i)`
