# 5. Gyakorlat, tömbök, példaprogram

## Tömbök

A tömbök C-ben **folytonos** memóriaterületeket jelentenek. Maga a tömb neve mint változó az első elemre mutató pointerként is értelmezhető. Ez azt jelenti, hogy ennek nem lehet értéket adni, viszont ha átadjuk paraméterül, akkor nem fog az egész tömb lemásolódni, hanem azt adjuk át paraméterül, hogy "hol kezdődik a tömb". Ellenben más nyelvekkel, a C-ben **nincs** hozzárendelve a tömbhöz a hossza, ezért akkor, ha át akarunk adni paraméterül egy tömböt, a hosszát is át kell adni.

### Deklarálás

A tömböket a változókhoz hasonlóan inicializáljuk, a név mögött szögletes zárójelben jelezve a méretét.
```
    int arr1[10]; /* 10 int típusú elemből álló tömb deklarálása */
    double vars[20]; /* 20 double típusú elemből álló tömb deklarálása */
    char name[31] /* 31 char típusú elemből álló tömb deklarálása */
```

### Inicializálás

A tömböket inicializáló listával lehet incializálni, amellyel akár a tömb mérete is meghatározható.
* Ha megadjuk a tömb méretét a neve után, akkor a tömbnek olyan hosszúnak kell lennie. Ebben az esetben az inicializáló listában nem megadott elemek 0-nak lesznek megadva.
```
    int arr1[5] = {1, 2, 3, 4, 5}; /* arr1: 1, 2, 3, 4, 5 */
    int arr2[5] = {1, 2}; /* arr2: 1, 2, 0, 0, 0 */
    int arr3[5] = {0}; /* arr3: 0, 0, 0, 0, 0 */
    // int arr4[3] = {1, 2, 3, 4, 5, 6}; /* warning !! */
```
  > Amennyiben több értékkel akarjuk inicializálni mint amennyi meg van adva a tömb után, akkor figyelmeztet a fordító, hogy többet adtunk meg, de fordít kódot. Nem történik inicializálás a felesleges inicializáló listarésznél.
  
* Amennyiben nem akarjuk megadni a tömb méretét, inicializáló lista esetén elhagyható a deklarációnál. Ebben az esetben a tömb mérete az inicializáló lista hossza lesz.
```
    int arr1[] = {1, 2, 3, 4, 5}; /* arr1: 1, 2, 3, 4, 5 */
    int arr2[] = {1, 2}; /* arr2: 1, 2 */
    int arr3[] = {0, 0, 0, 0}; /* arr3: 0, 0, 0, 0 */
    int arr4[] = {1, 2, 3, 4, 5, 6}; /* arr4: 1, 2, 3, 4, 5, 6 */
```

### Accessing element

A `[]` operátorral hivatkozhatunk a tömbök elemeire. 0-tól indexelünk.
```
    int arr[5];
    arr[0] = 1;
    arr[1] = arr[0] + arr[0];
    arr[2] = arr[0] + arr[1];
    arr[3] = 1 + arr[2];
    arr[4] = 5;
```


### Karaktertömbök

A `char` típusú elemekből álló tömbök inicializálásánál az inicializáló listán kívül megadhatunk a `"` karakterek közötti karaktersorozatot is. Ez átfordítható inicializáló listára egy bináris `\0` karakterrel a végén.

Például az `"alma"` karaktersorozatot egy 10 elemű tömbben sokféleképpen megtehetjük. A következő sorok mindegyike ugyanazt eredményezi:
```
    char name1[10] = "alma";
    char name2[10] = {'a', 'l', 'm', 'a', '\0', '\0', '\0', '\0', '\0', '\0'};
    char name3[10] = {'a', 'l', 'm', 'a'};
    char name4[10] = {'a', 'l', 'm', 'a', 0};
    char name5[10] = {97, 108, 109, 97};
```

### Tömbök hossza

A tömbök hossza nem beépített tulajdonsága a C-nek (hiszen a C nem objektumorientált!), ezért a hosszt külön kell eltárolnunk és átadnunk paraméterül.
Egy lokális tömbváltozó deklarálásánál a `sizeof` művelettel lekérhetjük a tömb teljes méretét byte-okban számolva:
```
    int numbers[] = {11, 12, 13, 14, 15, 16, 17, 18};
    int length;
    length = sizeof(numbers) / sizeof(numbers[0]);
```
> Ezzel a `length` változóba 8 kerül be.

Jól használt karaktertömbök esetén a hosszt nem kell átadnunk, mert azt a bináris 0 karakterből (`\0`) kiszámolhatjuk.

### Tömbök másolása

A tömbök neve az első elemre mutató pointerré konvertálható, de éppen emiatt nem használhatjuk az `=` operátort tömbökre. A tömböket elemenként át kell másolni az új helyre, amennyiben azt szeretnénk, hogy ugyanaz legyen benne.
```
    int first[] = {123, 124, 125};
    int second[3];
    int length = sizeof(second) / sizeof(second[0]);
    for (int i = 0; i < length; i++){
        second[i] = first[i];
    }
```

### Tömbök paraméterül átadása

Paraméterátadásnál a tömb méretét nem írjuk ki, ez pointerként fog viselkedni a függvény futása során és nem lokális tömbként.
Példa: egy `int`-ekből álló tömb kiíratása egy függvénnyel:
```
void printIntArray(int arr[], int length){
    int i;
    if (length <= 0){
        printf("Empty array\n");
        return;
    }
    
    printf("%d", arr[0]);
    for (i = 1; i < length; i++){
        printf(", %d", arr[i]);
    }
}
```
