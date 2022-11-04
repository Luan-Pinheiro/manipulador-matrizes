#include<iostream>
#include<locale>
#include<cstdlib>
#include<ctime>
using namespace std;


void imprimeMatriz(int [][50], const int, const int);
void duplicaMatriz(int [][50], const int, const int);
void multiplicaDiagonal(int [][50], const int, const int, const int);
void inverteDiagonal(int [][50], const int, const int);
int geraRandomicos(int , int);
void(*func[2])(int[][50],const int,const int)={imprimeMatriz, duplicaMatriz};

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    int n, k, randomico;

    cout << "Insira o n�mero que ira ser trabalhado MAXIMO[50]: " << endl;
    cin >> n;


    cout << endl << endl;


    int matA[n][50],matB[n][50];

    randomico = 1 + rand()%51;

    for(int i = 0; i <n; i++){
        for(int j = 0; j<n; j++){
            matA[i][j] = geraRandomicos(1,51);
            matB[i][j] = matA[i][j];
        }
    }
    cout<< "___IMPRIMINDO MATRIZ [A]___"<<endl;
    (*func[0])(matA,n,n);
    cout<< "___DUPLICANDO MATRIZ [B]___"<<endl;
    (*func[1])(matB,n,n);
    (*func[0])(matB,n,n);

    cout<< "\n"<<"Informe uma constante k"<< endl;
    cin >> k;
    cout<< "__________________________________________________"<< endl;

    cout<< "___MULTIPLICANDO DIAGONAL PRINCIPAL DE A___"<<endl;
    multiplicaDiagonal(matA, k, n,n);
    imprimeMatriz(matA,n,n);

    cout<< "___INVERTENDO DIAGONAL PRINCIPAL DE B___"<<endl;
    inverteDiagonal(matB, n, n);
    (*func[0])(matB,n,n);

    return 0;
}

void imprimeMatriz(int v[][50], const int lin, const int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col ; j++){
            cout << v[i][j] << "  ";
        }
        cout << "\n";
    }
}

void duplicaMatriz(int v[][50], const int lin, const int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col ; j++){
             v[i][j] = 2*v[i][j];
        }
    }
}

void multiplicaDiagonal(int v[][50], const int k, const int lin, const int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col ; j++){
            if(i==j){
                v[i][j] = k*v[i][j];
            }

        }
    }
}

void inverteDiagonal(int v[][50], const int lin, const int col){
    int armD[lin];
    for(int i = 0; i < lin; i++)
        armD[i] = v[i][i];

    for(int i = 0; i < lin; i++){
        v[i][i] = armD[lin - 1 -i];
    }
}

int geraRandomicos(int x, int y){
    int randomico = x + (rand()%(y-x+1));

    return randomico;
}


