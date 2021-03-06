<!-- .slide: data-background="#111111" -->

# Praca domowa 馃捇

<a href="https://coders.school">
    <img width="500px" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.85em" -->

## Praca domowa

### Post-work

Dzia艂aj du偶o z dokumentacj膮 cppreference i najlepiej z kim艣 w parze lub nawet grupie 3-osobowej 馃檪

* Zadanie 1 - `inner-product` (8 punkt贸w)
* Zadanie 2 - `advanced-calculator` (25 punkt贸w)

#### Bonusy

* **01.09.2021 (艣roda)** to ostatni dzie艅 na zebranie bonusowych punkt贸w za punktualno艣膰
* **3 XP** wpadn膮 Ci za ka偶de zadanie dostarczone w terminie (razem 6 punkt贸w)
* **1 XP** za prac臋 w grupie dla ka偶dej osoby z grupy za ka偶de zadanie (razem 2 punkty dla ka偶dej osoby). Zalecamy grupy 3 osobowe.

#### [Zadania w repo](https://github.com/coders-school/stl/blob/master/05-associative-containers/08-homework.md)

___

### Pre-work

* Przejrzyj raz jeszcze [z艂o偶ono艣膰 operacji na wszystkich kontenerach STL](https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md) i poczytaj tam te偶 o drzewach binarnych i r贸偶nych algorytmach sortowania.

___

## Zadanie 1 - `inner-product`

Zaimplementuj funkcj臋 `ArithmeticAverage()`, kt贸ra bierze 2 wektory int贸w i oblicza 艣redni膮 arytmetyczn膮 wszystkich warto艣ci

Input: `{1, 2, 3, 4} {1, 2, 3, 4}`
Output: `2.5`

Zaimplementuj funkcj臋 `Distance()`, kt贸ra bierze 2 wektory int贸w (jako wsp贸艂rz臋dne punkt贸w w przestrzeni n-wymiarowej) i oblicza odleg艂o艣膰 mi臋dzy nimi.

Input: `{7, 4, 3} {17, 6, 2}`
Output: `10.247`

Zadanie dostarcz na ga艂膮藕 [inner-product](https://github.com/coders-school/stl/tree/inner-product/homework/inner-product).

___

## Zadanie 2 - `advanced-calculator`

Napisz program advanced_calculator. Ma on posiada膰 p臋tle g艂贸wn膮, kt贸ra b臋dzie przyjmowa膰 dane od u偶ytkownika i wy艣wietla膰 wynik, np. dla `5 % 3` ma zwr贸ci膰 wynik `2`. Wszystkie komendy kalkulatora powinny by膰 przechowywane w mapie, kt贸ra jako klucz przechowuje znak `char` odwo艂uj膮cy si臋 do konkretnej komendy (np. `+` -> dodaj , `%` -> modulo), a jako warto艣ci `std::function<>` b臋d膮ce wraperem na wyra偶enia lambda dokonuj膮ce okre艣lonej kalkulacji.

Program powinien tak偶e zwraca膰 odpowiedni kod b艂臋du, je偶eli u偶ytkownik poda z艂e dane. Np. dzielenie przez `0` lub spr贸buje doda膰 `ala + 5`.

* Input: `5 + 5` -> operacja dodawania dw贸ch liczb `5` i `5` -> output: `10`.
* Input: `5 ^ 2` -> operacje pot臋gowania -> output `25`.
* Input: `125 $ 3` -> operacja pierwiastka (sqrt za d艂ugie), pierwiastek sze艣cienny z `125` -> output: `5`.

Zadanie dostarcz na ga艂膮藕 [advanced-calculator](https://github.com/coders-school/stl/tree/advanced-calculator/homework/advanced-calculator).

___

### Funkcje kalkulatora

* Dodawanie, mno偶enie, dzielenie, odejmowanie (`+`,  `*` , `/` , `-`)
* Modulo (`%`)
* Obliczanie silni (`!`)
* Podnoszenie liczby do pot臋gi (`^`)
* Obliczanie pierwiastka (`$`)

___

### Error code

* `Ok`
* `BadCharacter` - znak inny ni偶 liczba
* `BadFormat` - z艂y format komendy np. + 5 4, powinno by膰 4 + 5
* `DivideBy0` - dzielenie przez 0
* `SqrtOfNegativeNumber` - pierwiastek z liczby ujemnej
* `ModuleOfNonIntegerValue` - pr贸ba obliczenia % na liczbie nieca艂kowitej

___

### Funkcja, kt贸ra b臋dzie testowana

```cpp
ErrorCode process(std::string input, double* out)
```

* Funkcja ta powinna przyjmowa膰 dane od u偶ytkownika oraz dokonywa膰 odpowiedniej kalkulacji
* Je偶eli dane s膮 poprawne, ma zwr贸ci膰 `ErrorCode:Ok`, a w zmiennej `out` ma zapisa膰 wynik
* Je偶eli wyst膮pi kt贸ry艣 z b艂臋d贸w, funkcja ma go zwr贸ci膰, a w `out` ma nic nie zapisywa膰
