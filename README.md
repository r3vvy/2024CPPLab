# 2024CPPLab

Proiectul este un joc tic-tac-toe (X și O) de consolă, scris în C++.
Etapele dezvoltării sunt următoarele:

1.Crearea unei clase Boarding, care va afișa în consolă tabla de joc 3x3.
Clasa va conține un array bidimensional de tip char, care va ține cont de amplasarea lui X și O.
2.Crearea unei clase Input, care va implementa logica jocului, permițând mutarea jucătorilor pe rând prin alegerea poziției după axele x și y în matrice.
3.Extinderea clasei Boarding prin adăugarea unei metode de verificare, care să determine dacă un jucător a câștigat sau dacă jocul s-a încheiat la egalitate după o mutare.
4.Extinderea clasei Boarding prin adăugarea unei metode de validare a datelor de intrare, pentru a preveni introducerea unor date invalide (de exemplu: celula deja ocupată, date mai mari decât dimensiunea matricei sau mai mici decât 0).
5.Apelarea metodelor de construire a tablei de joc și de primire a inputurilor în clasa Main.

Pentru construirea proiectului folosiți visual studio, Run(ctrl+f5) sau Visual Studio Code prin lansarea Makefile 