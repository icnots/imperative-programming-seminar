# 3. Gyakorlat, példaprogramok

## Előjel nélküli egészek

Amennyiben tudjuk egy változóról, hogy olyan egészek lesznek benne, amely csak nemnegatív lehet, használhatunk `unsigned`, tehát előjel nélküli egész típust, amely kulcsszót odahelyezve a típus elé megváltoztatható a típus.
Pl.
* `unsigned int`
* `unsigned long`

A `long` típus a `long int`˙típus rövidítése.

## A `?:` operátor

Amennyiben egy értékadásnál egy egyszerű feltétel szerint akarunk kétféle értéket kiírni, használhatjuk a `?:` operátort, amely szintaxisa így néz ki:
* `feltétel ? igaz : hamis`. Amennyiben a `feltétel` igaz volt, akkor az `igaz` rész fog lefutni, különben a `hamis`.
Pl.:
* `int length = n > 0 ? n : 0;` Amennyiben az `n` változó értéke legalább 1, akkor `n` lesz a változó értéke, más esetben 0.

## Saját alprogramok írása.

A `main` függvényünk mintájára létrehozhatunk más alprogramokat is, amelyeket a nevükkel és a paramétereikkel meghívhatóak a `main` függvényünkből is.
Pl.
```
    int func(){
        printf("Hello World!\n");
        
        return 0;
    }
    int main(){
        func();
        func();
        
        return 0;
    }
```
