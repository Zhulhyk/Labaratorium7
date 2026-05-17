#include <concepts>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// ----------------------------------------------------
// ZADANIE 1 - concepty + przeci¹¿enia funkcji
// ----------------------------------------------------
//
// KROKI:
// 1) Napisz koncept Arithmetic (liczby ca³kowite OR zmiennoprzecinkowe).
// 2) Napisz koncept PrintableNonArithmetic:
//    - da siê wypisaæ przez std::cout
//    - NIE jest Arithmetic
// 3) Napisz 3 przeci¹¿enia funkcji opis_typ():
//    - Arithmetic -> "Typ arytmetyczny"
//    - PrintableNonArithmetic -> "Typ drukowalny"
//    - inne -> "Inny typ"

template <typename T>
concept Arithmetic = true; /* TODO */

template <typename T>
concept PrintableNonArithmetic = true; /* TODO */

template <typename T> /* TODO */
void opis_typ(T) {};

// ----------------------------------------------------
// ZADANIE 2 - concept z typem zwracanym
// ----------------------------------------------------
//
// KROKI:
// 1) Napisz concept AddableSameAs:
//    - a + b zwraca dok³adnie T (std::same_as)
//    - T jest nothrow copyable
// 2) Napisz funkcjê dodaj_bez_zmiany_typu()
//    - dzia³a tylko dla AddableSameAs

template <typename T>
concept AddableSameAs = true;/* TODO */

template <typename T> /* TODO */
T dodaj_bez_zmiany_typu(T a, T b) {};

// ----------------------------------------------------
// ZADANIE 3 - HasSize (const + dok³adny typ)
// ----------------------------------------------------
//
// KROKI:
// 1) Napisz concept HasSize:
//    - x.size() dzia³a dla const T
//    - x.size() zwraca dok³adnie std::size_t
// 2) Napisz wypisz_rozmiar() dzia³aj¹ce tylko dla HasSize

template <typename T>
concept HasSize = true; /* TODO */

template <typename T> /* TODO: zmienic typename */
void wypisz_rozmiar(const T& x) {};

// ----------------------------------------------------
// ZADANIE 4 - Indexable (const + referencja)
// ----------------------------------------------------
//
// KROKI:
// 1) Napisz concept Indexable:
//    - x.size() dzia³a dla const T i zwraca std::size_t
//    - x[i] dzia³a dla const T
//    - x[i] zwraca const reference do elementu
// 2) Napisz funkcjê wypisz_co_drugi()

template <typename T>
concept Indexable = true;/* TODO */

template <typename T> /* TODO: zmienic typename */
void wypisz_co_drugi(const T& x) {};

// ----------------------------------------------------
// G³ówna czêœæ programu
// ----------------------------------------------------

int main()
{
    double Uruchomzad = 1;

    if (Uruchomzad == 1) {
        std::cout << "ZAD 1: CONCEPTY + PRZECIAZENIA\n";
        // sprawdŸ opis_typ dla typu int
        // sprawdŸ opis_typ dla typu double
        // sprawdŸ opis_typ dla typu string
        // sprawdŸ opis_typ dla typu char
        // sprawdŸ opis_typ dla swojej dowolnej struktury, niebêd¹cej PrintableNotArithmetic
        // sprawdŸ opis_typ dla swojej dowolnej struktury, bêd¹cej PrintableNotArithmetic
        // opisz co siê stanie w przypadku char
    }

    if (Uruchomzad == 2) {
        std::cout << "ZAD 2: AddableSameAs\n";
        std::cout << dodaj_bez_zmiany_typu(3, 4) << "\n";
        std::cout << dodaj_bez_zmiany_typu(2.5, 1.5) << "\n";

        //Napisz strukture, zwracaj¹c¹ przy dodawaniu typ inny i przetestuj
    }

    if (Uruchomzad == 3) {
        std::cout << "ZAD 3: HasSize\n";
        std::string s = "abc";
        std::vector<int> v = { 1, 2, 3 };
        wypisz_rozmiar(s);
        wypisz_rozmiar(v);

        //sprawdŸ co sie stanie w przypadku argumenta int
    }

    if (Uruchomzad == 4) {
        std::cout << "ZAD 4: Indexable\n";
        std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
        std::string s = "abcdef";
        wypisz_co_drugi(v);
        wypisz_co_drugi(s);

        //sprawdŸ funkcjê wypisz_co_drugi na liœcie (std::list)
    }

    std::cout << "================\n";
    std::cout << "Koniec programu\n";
    return 0;
}