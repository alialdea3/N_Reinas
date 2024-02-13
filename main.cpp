#include <iostream>
#include <array>
#include <vector>
using namespace std;
vector<vector<int>> tableroajedrez;

void pintartablero(vector<vector<int>> tablero,int MaxCasillas){
    for (int i=0;i<MaxCasillas;i++){
        for (int j=0;j<=MaxCasillas-1;j++){
            cout << tablero[i][j] << "  ";
        }
        cout << endl;
    }
}

void pintarinfluencia(vector<vector<int>> & tablero,int Damai,int Damaj,int MaxCasillas){
    int i,j;

    for (i=0;i<MaxCasillas;i++){
        if (tablero[i][Damaj]==0) tablero[i][Damaj] = 1;
    }
    for (j=0;j<MaxCasillas;j++){
        if (tablero[Damai][j]==0) tablero[Damai][j] = 1;
    }
    i=1;
    while (Damai+i<MaxCasillas && Damaj+i<MaxCasillas){
        if (tablero[Damai+i][Damaj+i]==0) tablero[Damai+i][Damaj+i] = 1;
        i++;
    }
    i=1;
    while (Damai-i>=0 && Damaj-i>=0){
        if (tablero[Damai-i][Damaj-i]==0) tablero[Damai-i][Damaj-i] = 1;
        i++;
    }
    i=1;
    while (Damai-i>=0 && Damaj+i<MaxCasillas){
        if (tablero[Damai-i][Damaj+i]==0) tablero[Damai-i][Damaj+i] = 1;
        i++;
    }
    i=1;
    while (Damai+i<MaxCasillas && Damaj-i>=0){
        if (tablero[Damai+i][Damaj-i]==0) tablero[Damai+i][Damaj-i] = 1;
        i++;
    }
}
void buscardamas(vector<vector<int>> tablero,int Damai,int Damaj,int MaxCasillas, int contador){
int i,j;

    for (i=Damai; i<MaxCasillas;i++){
        for (j=Damaj; j<MaxCasillas; j++){
            if (tablero.at(i).at(j)==0){
                tablero.at(i).at(j)=2;
                pintarinfluencia(tablero,i,j,MaxCasillas);
                contador++;
                if (j<MaxCasillas-1){
                    buscardamas(tablero,i,j+1,MaxCasillas,contador);
                }else if (i<MaxCasillas-1){
                    buscardamas(tablero,i+1,0,MaxCasillas,contador);

                }
            }
        }
    }
    if (contador==MaxCasillas){
        tableroajedrez=tablero;
    }
}




int main(){
    vector<int> linea;
        int i,j;
        int tamano;
        cout<<"Cuantas damas quieres"
;
        cin>>tamano;


        for (i=0;i<tamano;i++){
            linea.push_back(0);
        }
        for (j=0;j<tamano;j++){
            tableroajedrez.push_back(linea);
        }

        for (i=0; i<tamano;i++){
            for (j=0; j<tamano; j++){
                buscardamas(tableroajedrez,i,j,tamano,0);
            }
        }

        pintartablero(tableroajedrez,tamano);

    return 0;


}
