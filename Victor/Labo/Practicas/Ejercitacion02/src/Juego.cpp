#include <utility>

using namespace std;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;
using Tablero = vector<vector<int>>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

class Juego {
    public:
        Juego(bool esta);
        bool esta();
    private:
        bool esta_;
};

Juego::Juego(bool esta) : esta_(esta) {}

bool Juego::esta() {
    return esta_;
}
