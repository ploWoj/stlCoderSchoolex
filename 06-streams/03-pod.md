<!-- .slide: data-background="#111111" -->

# POD - Plain old data

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Tryby zapisu: tekstowy vs binarny

### Demo

___

## POD - Plain old data

W uproszczeniu klasa/struktura bez konstruktora, destruktora i metod wirtualnych.

```cpp
class Pod {
public:
    void doSth() {}
    size_t getIndex() { return index_; }
    bool returnFalse() { return false; }

private:
    size_t index_;
    const char name_[15];
    double average_;
};
```
<!-- .element: class="fragment fade-in" -->

W praktyce - klasa/struktura, składająca się z typów prostych (w tym tablic), bądź innych POD-ów.
<!-- .element: class="fragment fade-in" -->

Dzięki temu układ PODa w pamięci bajt po bajcie jest intuicyjny i można go prosto **serializować**, tzn. zapisać/odczytać w formie binarnej.
<!-- .element: class="fragment fade-in" -->

___

## POD - Plain old data #2

Ale to już nie jest POD.

```cpp
class NotPod {
public:
    void doSth() {}
    bool returnTrue() { return true; }
    bool returnFalse() { return false; }

private:
    size_t index_;
    std::string name_; // std::string has constructor!
    double average_;
};
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Zapisywanie POD

```cpp
class Student {
public:
    void setName(std::string name) { strncpy(name_, name.data(), 15); }
    void setIndex(size_t index) { index_ = index; }
    void setAverage(double average) { average_ = average; }

    std::string getName() const { return name_; }
    size_t getIndex() const { return index_; }
    double getAverage() const { return average_; }

private:
    char name_[15];
    size_t index_;
    double average_;
};

int main() {
    Student mateusz;
    mateusz.setName("Mateusz");
    mateusz.setIndex(123456);
    mateusz.setAverage(5.0);

    std::fstream student("Student.txt", student.binary | student.out);
    if (student.is_open()) {
        student.write(reinterpret_cast<char*>(&mateusz), sizeof(Student));
    }
}
```
<!-- .element: class="fragment fade-in" -->

___

## Plik Student.txt

```txt
Mateusz         @�           @
```
<!-- .element: class="fragment fade-in" -->

### Hexdump
<!-- .element: class="fragment fade-in" -->

```cpp
0000000 614d 6574 7375 007a 0000 0000 0000 0000
0000010 e240 0001 0000 0000 0000 0000 0000 4014
0000020
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Odczyt POD

```cpp
void readPod() {
    student.open("Student.txt", student.binary | student.in);
    Student mateusz_read;
    if (student.is_open()) {
        student.read(reinterpret_cast<char*>(&mateusz_read), sizeof(Student));
    }
    std::cout << "Name: " << mateusz_read.getName() << '\n';
    std::cout << "Index: " << mateusz_read.getIndex() << '\n';
    std::cout << "Average: " << mateusz_read.getAverage() << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
Name: Mateusz
Index: 123456
Average: 5
```
<!-- .element: class="fragment fade-in" -->
