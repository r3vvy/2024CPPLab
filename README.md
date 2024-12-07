# Tic-Tac-Toe

## Descrierea Proiectului

Acest proiect implementează jocul Tic-Tac-Toe (X și O) utilizând C++ și biblioteci grafice (SFML).  
Jucătorii vor muta pe o tablă 3x3, iar jocul se încheie atunci când un jucător reușește să alinieze trei simboluri proprii pe orizontală, verticală sau diagonală, sau când nu mai sunt poziții disponibile, rezultând o remiză.

## Regulile Jocului

- Doi jucători: unul folosește "O", celălalt "X".
- Jucătorii plasează simbolurile alternativ, câte o singură mutare pe rând.
- Primul jucător care formează un rând, coloană sau diagonală completă cu propriul simbol câștigă.
- Dacă tabla se umple fără ca vreun jucător să câștige, jocul se încheie cu un rezultat de egalitate.

## Dependențe

- **Mediul de dezvoltare**: C++17 sau mai nou.
- **Compilator**: g++ sau clang++ recomandat.
- **Biblioteci terțe**: [SFML](https://www.sfml-dev.org/) pentru partea grafică.
  
  Asigurați-vă că SFML este instalat (includeți headers și library paths corespunzătoare).
  
- **Sistem de build**: CMake sau Makefile, după preferință.

## Instrucțiuni de Compilare

1. Asigurați-vă că aveți instalate:
   - SFML (inclusiv biblioteca grafică, sistem, window, etc.)
   - Un compilator C++17+
   - CMake (opțional, dar recomandat)
2. Clonați repository-ul:
   ```bash
   git clone https://github.com/username/lab06-tictactoe.git
   cd lab06-tictactoe
3. Creați un director pentru build:
   mkdir build
   cd build
4. Generați fișierele de build cu CMake (exemplu):
   cmake ..
   cmake --build .
5. Executați aplicația:
   ./TicTacToe

## Testatre
   Testele sunt localizate în directorul tests.
   Pentru a rula testele:
   ./tests/test_gamedata
   în funcție de configurația sistemului de build.
## Autor 
   Moghildea Valeria
   An:2024
