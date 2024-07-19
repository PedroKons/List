#ifndef REFAZENDOLISTAESTATICA_H_INCLUDED
#define REFAZENDOLISTAESTATICA_H_INCLUDED

template<typename TIPO, int MAX>
struct TElemento {
    TIPO dado;
};

template<typename TIPO, int MAX>
struct TLista {
    TElemento<TIPO, MAX> elementos[MAX];
    int tamanho;
};

template<typename TIPO, int MAX>
bool inicializaLista(TLista<TIPO,MAX>& l){
    l.tamanho = 0;
    return true;
}

template<typename TIPO, int MAX>
int retornaTamanho(TLista<TIPO,MAX>& l){
    return l.tamanho;
}

template<typename TIPO, int MAX>
bool insereFim(TLista<TIPO, MAX>& l, TIPO dado){
    if(l.tamanho == MAX) return false;
    l.elementos[l.tamanho].dado = dado;
    l.tamanho ++;
    return true;
}

template<typename TIPO, int MAX>
bool insereInicio(TLista<TIPO, MAX>& l, TIPO dado) {
    if(l.tamanho == MAX) return false;
    for (int i = l.tamanho; i>=0; i--){
        l.elementos[i + 1].dado = l.elementos[i].dado;
    }
    l.elementos[0].dado = dado;
    l.tamanho++;
    return true;
}

template<typename TIPO, int MAX>
bool inserePosicao(TLista<TIPO, MAX>& l, TIPO dado, int posicao){
    if(l.tamanho == MAX) return false;
    for(int i = l.tamanho; i>=posicao; i--){
        l.elementos[i + 1].dado = l.elementos[i].dado;
    }
    l.elementos[posicao].dado = dado;
    l.tamanho++;
    return true;
}

template<typename TIPO, int MAX>
bool removeFim(TLista<TIPO, MAX>& l){
    if(l.tamanho == 0) return false;
    l.tamanho --;
}

template<typename TIPO, int MAX>
bool removeInicio(TLista<TIPO, MAX>& l){
    if(l.tamanho == 0) return false;
    for(int i = 0; i<=l.tamanho - 1; i++){
        l.elementos[i] = l.elementos[i+1];
    }
    l.tamanho--;
    return true;
}

template<typename TIPO, int MAX>
bool removeposicao(TLista<TIPO, MAX>& l, int posicao){
    if(l.tamanho == 0) return false;
    for(int i = posicao; i<=l.tamanho - 1; i++){
        l.elementos[i] = l.elementos[i+1];
    }
    l.tamanho--;
    return true;
}

template<typename TIPO, int MAX>
void bubblesort(TLista<TIPO, MAX>& l) {
    for(int i = 0; i < l.tamanho - 1; i++){
        for(int j =0; j < l.tamanho - i - 1; j++){
            if(l.elementos[j].dado < l.elementos[j+1].dado) {
                TIPO temp = l.elementos[j].dado;
                l.elementos[j].dado= l.elementos[j+1].dado;
                l.elementos[j+1].dado = temp;
            }
        }
    }
}

template<typename TIPO>
void trocar(TIPO& a, TIPO& b) { //swap
    TIPO temp = a;
    a = b;
    b = temp;
}

template<typename TIPO, int MAX>
int quicksort(TLista<TIPO, MAX>& l, int inicio, int fim){
    if(inicio < fim) {
        int indicePivo = particionar(l, inicio, fim);
        quicksort(l, inicio, indicePivo - 1);
        quicksort(l, indicePivo + 1, fim);
    }
}

template<typename TIPO, int MAX>
int particionar(TLista<TIPO, MAX>& l, int inicio, int fim){
    TIPO pivo = l.elementos[fim].dado;
    int i = inicio - 1;

    for(int j = inicio; j <= fim - 1; j++){
        if(l.elementos[j].dado < pivo){
            i++;
            trocar(l.elementos[i].dado, l.elementos[j].dado);
        }
    }

    trocar(l.elementos[i + 1].dado, l.elementos[fim].dado);
    return i + 1;
}

#endif // REFAZENDOLISTAESTATICA_H_INCLUDED
