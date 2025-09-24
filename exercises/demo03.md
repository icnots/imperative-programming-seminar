# 3. Gyakorlat, példaprogramok

## Alprogramok

A `main` metódushoz hasonlóan hozhatunk létre saját alprogramokat (metódusokat, függvényeket). Ezeknek a szintaxisa pontosan ugyanúgy néz ki mint a `main`-nek:
```
tyype name(param1type param1, param2type param2){
    return something; /*where something is of type tyype*/
}
```

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

A `scanf` függvény mellett megismerkedünk a karakterenkénti beolvasással is. Ez sokszor hasznos, mert így pontosan ellenőrizhetjük, hogy milyen karakterek érkeznek a bemenetről, és jobban kézben tarthatjuk a hibás inputok kezelését.  

Erre a `getchar` függvényt használjuk, amely az `stdin` pufferből tér vissza sorban a karakterekkel. Amikor entert ütünk, a begépelt sor kerül a pufferbe, és innen adja vissza a `getchar` a karaktereket egyenként – beleértve az újsor (`'\n'`) karaktert is.  

Például készíthetünk egy olyan programot, amely a `'0'` karakter beírásáig kiírja a beütött karaktereket az ASCII kódjukkal együtt:

```c
char ch;
while ((ch = getchar()) != '0') {
    printf("'%c' - %d\n", ch, ch);
}
````

---

## Beolvasás egész számot karakterenként

Ebben a részben egy olyan függvényt hozunk létre, amely a következő egész számot olvassa be a szabványos bemenetről (`stdin`).

A `getchar()` hívásokkal sorban kapjuk meg a felhasználó által begépelt karaktereket. Először szükségünk lesz egy segédfüggvényre, amely eldönti egy karakterről, hogy számjegy-e vagy sem:

```c
int isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}
```

(A C szabványos könyvtárában egyébként létezik `isdigit` függvény a `<ctype.h>` headerben, de itt most saját verziót írunk.)

---

### Első számjegy megtalálása

Amikor számot akarunk beolvasni, addig kell olvasni a karaktereket, amíg számjegyet vagy egy `'-'` jelet nem találunk (utóbbit a negatív számok miatt engedjük):

```c
char ch;
ch = getchar();
while (!isDigit(ch) && ch != '-') {
    ch = getchar();
}
```

Miután ez a rész lefutott, biztosak lehetünk benne, hogy a `ch` változóban vagy egy `'-'` jel, vagy egy számjegy van.

---

### Negatív számok kezelése

Ha `'-'` jelet találtunk, akkor elmentjük az előjelet, és továbbolvasunk. Ha közvetlenül utána nem számjegy jön, az hibás formátumot jelent:

```c
int sign = 1;
if (ch == '-') {
    sign = -1;
    ch = getchar();
    /* Ha most nem számjegy következik, akkor rossz számformátumot írtak be. */
    if (!isDigit(ch)) {
        printf("Invalid number\n");
        return 0; /* Jobb lenne hibakódot visszaadni vagy kilépni. */
    }
}
```

---

### Számjegyek összerakása

Ezután következik a számjegyek feldolgozása. A `'0'` kivonása egy karakterből megadja a megfelelő numerikus értéket (pl. `'7' - '0' = 55 - 48 = 7`):

```c
int value = ch - '0';
ch = getchar();
while (isDigit(ch)) {
    value *= 10;
    value += ch - '0';
    ch = getchar();
}
return sign * value;
```

---

## Teljes program

Az alábbi teljes példában a `readInt` függvény egyszerre egy egész számot olvas be a szabványos bemenetről. Hibás formátum esetén `0`-val tér vissza, de a gyakorlatban érdemes lenne hibakódot vagy más jelzést használni.

```c
#include <stdio.h>

int isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int readInt() {
    char ch;
    ch = getchar();
    while (!isDigit(ch) && ch != '-') {
        ch = getchar();
    }

    int sign = 1;
    if (ch == '-') {
        sign = -1;
        ch = getchar();
        if (!isDigit(ch)) {
            printf("Invalid number\n");
            return 0;
        }
    }

    int value = ch - '0';
    ch = getchar();
    while (isDigit(ch)) {
        value *= 10;
        value += ch - '0';
        ch = getchar();
    }
    return sign * value;
}

int main() {
    int a = readInt();
    int b = readInt();

    printf("Your number is: %d %d\n", a, b);
    return 0;
}
```

## Bitműveletek

Ehhez a következő honlapot ajánlom: [Bitműveletek](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
