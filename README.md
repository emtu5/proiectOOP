# Temple Stones v1.0.1

- A game where you place pieces on a board in order to fulfill certain winning conditions (such as filling up the board completely, all but one tile etc.).

- A very rough mock-up of what the final game will look like (none of the assets are final):
![](https://i.imgur.com/M5zQM2d.png)

- Right now, the game looks like this:
![](https://i.imgur.com/5fd3M14.png)
## How to play

- Place pieces on the board with your mouse.
- Left Click: Picks up a piece. Click again to release it. If the piece has space to fit on the board, it will be placed on it.
- Right CLick: Rotates the held piece clockwise.
- Middle Click: Flips the piece.

### Current state of the game

- Basic piece placement logic has been implemented, as well as a super-basic level file parser.
- Currently there is only one level that's immediately loaded at startup (and only that, I haven't coded any logic for advancing to other levels). In the future there will not only be multiple levels, but also a dedicated level select screen.
- You can toy around with the pieces on the predefined board.

## To be implemented/done

- Fix release tag not putting in the resources folder
- Clean up the code for 1.0 (especially Piece/Board classes)
- Visual bug: A picked up tile should be placed on the very top (there's no code yet that moves a piece to the front) 
- A basic level advancement system
- A Button class (UI, not only for the menu, but also in-game, as the pieces will be accesed by the buttons on the side, as seen in the mock-up)
- Texture Loader for the pieces, the
- A level select screen (Menu class, and so much more)
- Save files
- Implement win conditions for different board types
- Make Engine class singleton
- Exception handling (missing level files, assets)
- Make a config file for window size
- Basic sounds

### Tema 0

- [x] Nume proiect (poate fi schimbat ulterior)
- [x] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [x] definirea a minim 3-4 clase folosind compunere
- [x] constructori de inițializare
- [x] pentru o clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [x] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [x] cât mai multe `const` (unde este cazul)
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese
- [x] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` exemple de date de intrare de la tastatură (dacă există)
- [x] tag de `git`: de exemplu `v0.1`
- [] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa de mai sus, constructori virtuali (clone)
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] smart pointers
  - [ ] `dynamic_cast`
- [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim 2 clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor, `try`/`catch` în `main`
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] la sfârșit: commit separat cu adăugarea unei noi derivate fără a modifica restul codului
- [ ] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] o clasă șablon cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse

- [SFML](https://github.com/SFML/SFML/tree/aa82ea132b9296a31922772027ad5d14c1fa381b) (Zlib), [Documentație] (https://www.sfml-dev.org/documentation/2.5.1/)
- [Tutorial Snake](https://www.youtube.com/playlist?list=PLbPaYYCufiXzbKTwPpYpgkUplgsCscEm6) (ca să mă obișnuiesc cu SFML)
