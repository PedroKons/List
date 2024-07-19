template <typename TIPO>
struct TElemento {
    TIPO dado;
    TElemento <TIPO> * anterior;
    TElemento <TIPO> * proximo;
};

template<typename TIPO>
struct TLista {
    TElemento <TIPO> * inicio;
    TElemento <TIPO> * fim;
};

template<typename TIPO>
bool inicializaLista(TLista<TIPO> &l) {
    l.inicio = NULL;
    l.fim = NULL;
    return true;
}

template<typename TIPO>
void imprimirLista(TElemento<TIPO> *l) {
    while (l != NULL) {
        cout << l->dado << " ";
        l = l->proximo;
    }
    cout << endl;
}

template<typename TIPO>
TElemento<TIPO> *novoElemento(TIPO dado){
    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

template<typename TIPO>
bool insereInicio(TLista<TIPO> &l, TIPO dado){
    TElemento<TIPO> *novo = novoElemento(dado);
    if(l.inicio != NULL) {
        TElemento<TIPO> *nav = l.inicio;
        l.inicio = novo;
        nav->anterior = novo;
        novo->proximo = nav;
        return true;
    }else {
        l.inicio = novo;
        l.fim  = novo;
        return true;
    }
}

template<typename TIPO>
bool insereFim(TLista<TIPO> &l, TIPO dado) {
    TElemento<TIPO> *novo = novoElemento(dado);
    if(l.inicio != NULL){
        TElemento<TIPO> *nav = l.fim;
        l.fim = novo;
        nav->proximo = novo;
        novo->anterior = nav;
        return true;
    }else {
        l.inicio = novo;
        l.fim = novo;
        return true;
    }
}

template<typename TIPO>
bool inserePosicao(TLista<TIPO> &l, TIPO dado, int posicao) {
    TElemento<TIPO> *novo = novoElemento(dado);
    TElemento<TIPO> *nav = l.inicio;
    if(posicao == 0 || l.inicio == NULL) {
        return insertFirst(l, dado);
    } else {
        for(int i=0; nav != NULL && i < posicao - 1; i++){
            nav = nav->proximo;
        }
    }
    novo->anterior = nav;
    novo->proximo = nav->proximo;
    if (nav->proximo)
        nav->proximo->anterior = novo;
    else
        l.fim = novo;
    nav->proximo = novo;
    return true;

}

template<typename TIPO>
bool removeInicio(TLista<TIPO> &l){
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio == NULL) {
        return false;
    }else {
        l.inicio = l.inicio->proximo;
    }
    if(l.inicio != NULL) {
        l.inicio->anterior = NULL;
    }else {
        l.fim = NULL;
    }

    delete nav;
    return true;
}

template<typename TIPO>
bool removeFim(TLista<TIPO> &l) {
    TElemento<TIPO> *nav = l.fim;
    if(l.inicio == NULL) {
        return false;
    } else {
        l.fim = l.fim->anterior;
    }
    if(l.fim != NULL){
        l.fim->proximo = NULL;
    }else {
        l.inicio = NULL;
    }

    delete nav;
    return true;
}

template<typename TIPO>
bool removePosicao(TLista<TIPO> &l, int position){
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio == NULL) return false;
    for(int i = 0;  i<position && nav != NULL; i++) {
        nav = nav->proximo;
    }
    if (nav->anterior)
        nav->anterior->proximo = nav->proximo;
    else
        l.inicio = nav->proximo;

    if (nav->proximo)
        nav->proximo->anterior = nav->anterior;
    else
        l.fim = nav->anterior;
    delete nav;
    return true;
}

template<typename TIPO>
void bubblesort(TLista<TIPO> &l) {
    if(l.inicio != NULL) {
        TIPO temp;
        TElemento<TIPO> *nav = l.inicio;
        TElemento<TIPO> *aux = nav->proximo;
        while(aux != NULL){
            if(aux->dado < nav->dado){
                temp = aux->dado;
                aux->dado = nav->dado;
                nav->dado = temp;
                nav = l.inicio;
                aux = nav->proximo;
            }else {
                aux = aux->proximo;
                nav = nav->proximo;
            }
        }
    }
}

template<typename TIPO>
void trocar(TElemento<TIPO>* a, TElemento<TIPO>* b) {
    TIPO temp = a->dado;
    a->dado = b->dado;
    b->dado =  temp;
}

template<typename TIPO>
TElemento<TIPO> *particao(TElemento<TIPO>* inicio, TElemento<TIPO>* fim) { //recebe inicio e fim da lista
    TIPO pivo = fim->dado; // define o pivo como ultimo dado
    TElemento<TIPO>* i = inicio->anterior; // elemento anterior 

    for (TElemento<TIPO>* j = inicio; j != fim; j = j->proximo) { // percorre a lista
        if (j->dado < pivo) { // Verifica se o valor do elemento atual (j->dado) é menor que o valor do pivô (pivo)
            if(i == NULL) { // Se o elemento atual for menor que o pivô, move o ponteiro i para o próximo elemento. A função trocar é chamada para trocar os dados dos elementos i e j
                i = inicio; 
            } else { 
                i = i->proximo; 
            }
            trocar(i, j); 
        }
    }

    if(i == NULL) { //Se nenhum elemento menor que o pivô for encontrado, i permanece como NULL, caso contrário, é movido para o próximo elemento.
        i = inicio;
    } else {
        i = i->proximo;
    }
    trocar(i, fim);
    return i;

}

template<typename TIPO>
void quickSort(TElemento<TIPO>* inicio, TElemento<TIPO>* fim) {
    if (fim != NULL && inicio != fim && inicio != fim->proximo) { // Verifica se a lista não está vazia
        TElemento<TIPO>* pivo = particao(inicio, fim);
        quickSort(inicio, pivo->anterior); // ordenar a sublista à esquerda do pivô.
        quickSort(pivo->proximo, fim); //ordenar a sublista à direita do pivô
    }
}



