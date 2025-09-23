# 3. Gyakorlat, példaprogramok

## Inkrementáló operátorok

Az inkrementáló operátoroknak (`++`) van visszatérési értéke. A különbség az, hogy a növelés előtti vagy utáni érték lesz a visszatérési érték.

### Posztinkrementálás
A posztfix inkrementáló operátor a növelés előtti értékkel tér vissza:
```
    int i = 1;
    int j = i++;
    /* ekkor i = 2 és j = 1 */
```

### Preinkrementálás
A prefix inkrementáló operátor a növelés előtti értékkel tér vissza:
```
    int i = 1;
    int j = ++i;
    /* ekkor i = 2 és j = 2 */
```

## Beolvasás karakterenként

A `scanf` függvény mellett megismerkedünk a karakterenként olvasással. Erre a `getchar` függvényt használjuk, amely az `stdin` bufferbe beírt karakterekkel sorban tér vissza. Tehát ha elküldjük a buffert az enter nyomásával, akkor az első `getchar` függvény az első karakterrel tér vissza, a második a másodikkal és így tovább (beleértve az újsor karaktert is).

Pl. egy olyan program, ami a 0 karakter ütéséig kiírja a beütött karaktereket az ASCII kódjukkal együtt.
```
    char ch;
    while ((ch = getchar())){
        printf("'%c' - %d\n", ch, ch);
    }
```

## Bitműveletek

Ehhez a következő honlapot ajánlom: [Bitműveletek](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
