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

A `scanf` függvény mellett megismerkedünk a karakterenként olvasással. Erre a `getchar` függvényt használjuk, amely az `stdin` pufferből (a billentyűzetről beírt karakterek) tér vissza sorban. Amikor entert ütünk, a begépelt sor kerül a pufferbe, és innen adja vissza a `getchar` függvény a karaktereket egyenként.

Pl. egy olyan program, ami a 0 karakter ütéséig kiírja a beütött karaktereket az ASCII kódjukkal együtt.
```
    char ch;
    while ((ch = getchar())){
        printf("'%c' - %d\n", ch, ch);
    }
```

### Beolvasás egész számot karakterenként
Ebben a részben egy olyan alprogramot hozunk létre, amely a legközelebbi egész számot olvassa be az `stdin` bemenetről.
A felhasználó által beírt karakterek bekerülnek egy `stdin` nevű streambe. Ez azt jelenti, hogy amikor olvasunk a `stdin`-ről, akkor sorban fogjuk kapni a `getchar()` függvénnyel a karaktereket, amelyeket beírt.

Létrehozunk egy metódust, amely a paraméterül kapott karakterről eldönti, hogy számjegy-e vagy nem.
```
int isDigit(char ch){
    return '0' <= ch && ch <= '9';
}
```

Amikor a számot akarjuk beolvasni, addig olvasunk, amíg számjegyet vagy `'-'` karaktert nem olvasunk (negatív számok miatt).
```
char ch;
ch = getchar();
while (!isDigit(ch) && ch != '-'){
    ch = getchar();
}
```
Miután ez a rész lefutott, biztosak lehetünk benne, hogy a ch-ban vagy egy `'-'` karakter vagy egy számjegy van.
Negatív szám esetére létrehozunk egy elágazást, ami eldönti, hogy negatív számról van-e szó. Ha negatív, akkor elmentjük ezt az információt és eggyel tovább olvasunk:
```
int sign = 1;
if (ch == '-'){
    sign = -1;
    ch = getchar();
    /*Ha most nem számjegy következik, akkor rossz számformátumot írtak be.*/
    if (!isDigit(ch)){
        printf("Invalid number");
        return 0;
    }
}
```
Különben pedig mehet az értékek beolvasása:
```
int value = ch - '0'; /*Mivel sorrendben vannak a számjegyek, a '0' értékét kivonva magát az értéket kapjuk.*/
ch = getchar();
while (isDigit(ch)){
    value *= 10;
    value += ch - '0';
}
return sign * value;
```

Egybemásolva a programot: (Vegyük észre, hogy ez majdnem ugyanúgy használható mint a `scanf` esetében volt, csak itt visszatérési értékként kapjuk a beolvasott számot, nem egy változóba rakja bele. Így csak egyetlen számot lehet egyszerre beolvasni, de egy elválasztó nem-szám karakter után ismét olvashatunk be más egész számot.)
```
#include <stdio.h>


int isDigit(char ch){
    return '0' <= ch && ch <= '9';
}

int readInt(){
    char ch;
    ch = getchar();
    while (!isDigit(ch) && ch != '-'){
        ch = getchar();
    }

    int sign = 1;
    if (ch == '-'){
        sign = -1;
        ch = getchar();
        /*Ha most nem számjegy következik, akkor rossz számformátumot írtak be.*/
        if (!isDigit(ch)){
            printf("Invalid number");
            return 0;
        }
    }

    int value = ch - '0'; /*Mivel sorrendben vannak a számjegyek, a '0' értékét kivonva magát az értéket kapjuk.*/
    ch = getchar();
    while (isDigit(ch)){
        value *= 10;
        value += ch - '0';
        ch = getchar();
    }
    return sign * value;
}


int main(){
    int a = readInt();
    int b = readInt();

    printf("Your number is: %d %d\n", a, b);
    return 0;
}
```

## Bitműveletek

Ehhez a következő honlapot ajánlom: [Bitműveletek](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
