#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, c, r1, r2;

    cin >> l >> c >> r1 >> r2;
    do {
        if(
            min(l, c) > max(2 * r1, 2 * r2)) {
            int R1 = 2 * r1 + 2 * r2;

            int x1 = r1, y1 = r1, x2 = l - r2, y2 = c - r2;
            int d = pow(x2 - x1, 2) + pow(y2 - y1, 2);

            if(d > pow(r1 + r2, 2))
                cout << "S\n";
            else
                cout << "N\n";
        } else cout << "N\n";

        cin >> l >> c >> r1 >> r2;
    } while(l + c + r1 + r2 > 0);

    return 0;
}

/* Imagine que os círculos estão em diagonais opostas ( o círculo de raio R1 está na diagonal esquerda abaixo e o R2 na direita acima) Coloque o retângulo e os círculos em um plano, no qual a diagonal esquerda abaixo do retângulo esteja no ponto (0,0). Nesse caso, o círculo 1 estára no ponto (R1,R1) e o círculo 2 no ponto (comprimento-R2,altura-R2) Se os círculos cabem, então não pode haver interseção entre eles. Para verificar isso, basta ver se a distância dos centros é maior do que a soma dos raios. Se for menor, então não cabe. Caso contrário, cabe. */
