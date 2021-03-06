<!-- .slide: data-background="#111111" -->

# Algorytmy STL

## Praca domowa 馃捇

<a href="https://coders.school">
    <img width="500px" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.85em" -->

## Praca domowa

### Post-work

Dzia艂aj du偶o z dokumentacj膮 cppreference i najlepiej z kim艣 w parze lub nawet grupie 3-osobowej 馃檪

* Obejrzyj [105 STL Algorithms in Less Than an Hour](https://www.youtube.com/watch?v=bFSnXNIsK4A)
* Zadanie 1 -  kontynuacja zadania `grayscale-image` (6 punkt贸w)
* Zadanie 2 - `insensitive-palindrom` (6 punkt贸w)
* Zadanie 3 - `transform-containers` (6 punkt贸w)

#### Bonusy

* **18.08.2021 (艣roda)** to ostatni dzie艅 na zebranie bonusowych punkt贸w za punktualno艣膰
* **3 XP** wpadn膮 Ci za ka偶de zadanie dostarczone w terminie (razem a偶 9 punkt贸w)
* **1 XP** za prac臋 w grupie dla ka偶dej osoby z grupy za ka偶de zadanie (razem 3 punkty dla ka偶dej osoby). Zalecamy grupy 3 osobowe.

#### [Zadania w repo](https://github.com/coders-school/stl/blob/master/04-algorithms/16-homework.md)

___

### Pre-work

* Poczytaj co艣 wi臋cej o z艂o偶ono艣ci obliczeniowej np. na [Samouczku programisty](https://www.samouczekprogramisty.pl/podstawy-zlozonosci-obliczeniowej/)
* Obejrzyj i zapami臋taj jaka jest [z艂o偶ono艣膰 operacji na wszystkich kontenerach STL](https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md). Poczytaj tam te偶 o drzewach binarnych i r贸偶nych algorytmach sortowania.

___

## Zadanie 1 - `grayscale-image-algo`

Ulepsz program `grayscale-images` z poprzedniej pracy domowej (kompresja, dekompresja) obrazk贸w, tak, aby zamiast p臋tli wykorzysta膰 algorytmy. Dzia艂aj na swojej/waszej wersji implementacji tego zadania.

Gotowe zadanie zg艂o艣 na ga艂膮藕 `coders-school:grayscale-image-algo`. Je艣li nie chcesz nadpisa膰 PR z tamt膮 prac膮 domow膮 to po prostu utw贸rz nowego brancha od tego stanu. Je艣li to skomplikowane - po prostu skopiuj sw贸j program `grayscale-images` ;)

___

## Zadanie 2 - `insensitive-palindrom`

Napisz program, kt贸ry b臋dzie sprawdza艂, czy podany ci膮g wyraz贸w jest palindromem. Program powinien ignorowa膰 znaki specjalne np. `,.?()[]` (i nie tylko). Powinien r贸wnie偶 ignorowa膰 wielko艣膰 liter oraz bia艂e znaki jak spacja czy znak nowej linii.

Wywnioskuj po testach jak nazwa膰 funkcj臋. Stw贸rz w艂asne pliki 藕r贸d艂owe i nag艂贸wkowe i dodaj je do CMakeLists.txt, aby si臋 budowa艂y. Szczeg贸艂y w [README.md do tego zadania](https://github.com/coders-school/stl/tree/insensitive-palindrom/homework/insensitive-palindrom).

Gotowe zadanie zg艂o艣 na ga艂膮藕 `coders-school:insensitive-palindrom`.

___

## Zadanie 3 - `transform-containers`

Napisz funkcj臋, kt贸ra:

1. Przyjmie `std::list<std::string>` oraz `std::deque<int>`
2. Usunie duplikaty z obu kontener贸w
3. Na koniec skonwertuje to na `std::map<int, std::string>` i j膮 zwr贸ci. U偶yj `std::transform`.

Wywnioskuj po testach jak nazwa膰 funkcj臋. Stw贸rz w艂asne pliki 藕r贸d艂owe i nag艂贸wkowe i dodaj je do CMakeLists.txt, aby si臋 budowa艂y. Szczeg贸艂y w [README.md do tego zadania](https://github.com/coders-school/stl/tree/transform-containers/homework/transform-containers).

Gotowe zadanie zg艂o艣 na ga艂膮藕 `coders-school:transform-containers`.
