<!-- .slide: data-background="#111111" -->

# Algorytmy sortuj膮ce

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .element: style="font-size: 0.8em" -->

## Zadanie 馃捇

```cpp
struct Point { int x, y; }
```
<!-- .element: style="font-size: 0.8em" -->

1. Utw贸rz `std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};`
2. Utw贸rz funkcj臋 do wypisywania zawarto艣ci kontenera `d`
3. Napisz 2 komparatory:
   1. `pointXCompare`, kt贸ry por贸wnuje tylko warto艣ci `x` ze struktury `Point`
   2. `pointYCompare`, kt贸ry por贸wnuje tylko warto艣ci `y` ze struktury `Point`
4. Sprawd藕 czy `d` jest posortowane wzgl臋dem `pointXCompare` oraz `pointYCompare`
5. U偶yj `stable_sort` do posortowania `d` wzgl臋dem warto艣ci `x`
6. U偶yj `sort` do posortowania `d` wzgl臋dem warto艣ci `y`

___

## `std::partial_sort` vs `std::nth_element`

```cpp
std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
std::cout << "The median is " << v[v.size()/2] << '\n';     // 5
// possible content of v = {3, 2, 3, 4, 5, 6, 7, 9, 6}
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
std::partial_sort(s.begin(), s.begin() + 3, s.end());
// possible content of s = {0, 1, 2, 7, 8, 6, 5, 9, 4, 3}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::partial_sort` vs `std::nth_element`

* <!-- .element: class="fragment fade-in" --> <code>std::nth_element</code> i <code>std::partial_sort</code> to algorytmy sortuj膮ce
* <!-- .element: class="fragment fade-in" --> <code>std::nth_element</code> zmienia kolejno艣膰 element贸w w kontenerze w taki spos贸b, 偶e:
  * <!-- .element: class="fragment fade-in" --> n-ty element jest na w艂a艣ciwej pozycji
  * <!-- .element: class="fragment fade-in" --> wszystkie elementy mniejsze od niego lub r贸wne s膮 przed nim
  * <!-- .element: class="fragment fade-in" --> wszystkie elementy wi臋ksze od niego s膮 za nim
  * <!-- .element: class="fragment fade-in" --> z艂o偶ono艣膰 liniowa - <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> <code>std::partial_sort</code> zmienia kolejno艣膰 element贸w w kontenerze w taki spos贸b, 偶e:
  * <!-- .element: class="fragment fade-in" --> zakres <code>[first, middle)</code> zawiera posortowane najmniejsze elementy z ca艂ego zakresu <code>[first, last)</code>
  * <!-- .element: class="fragment fade-in" --> kolejno艣膰 element贸w w zakresie <code>[middle, last)</code> jest niewyspecyfikowana
  * <!-- .element: class="fragment fade-in" --> nie ma gwarancji, 偶e kolejno艣膰 r贸wnych sobie element贸w zostanie zachowania (algorytm nie jest stabilny)
  * <!-- .element: class="fragment fade-in" --> z艂o偶ono艣膰 liniowo-logarytmiczna <code>O(n logn)</code>, a dok艂adniej <code>(last-first) * log(middle-first)</code> operacji
