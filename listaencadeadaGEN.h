template<typename TIPO>
struct TElemento {
    TIPO dado;
    TElemento<TIPO> *proximo;
};

template<typename TIPO>
struct Tlista {
    TElemento<TIPO> *inicio;
};

template<typename TIPO>
bool inicializaLista(Tlista<TIPO>& l){
    l.inicio = NULL;
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
TElemento<TIPO> *novoElemento(TIPO dado) {
    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->proximo =NULL;
    return novo;
}

template<typename TIPO>
bool insereInicio(Tlista<TIPO>& l, TIPO dado) {
    TElemento<TIPO> *novo = novoElemento(dado);
    novo->proximo = l.inicio;
    l.inicio = novo;
    return true;
}

template<typename TIPO>
bool insereFim(Tlista<TIPO>& l, TIPO dado) {
    TElemento<TIPO> *nav = l.inicio;
    TElemento<TIPO> *novo = novoElemento(dado);
    if(l.inicio != NULL){
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        novo->proximo = nav->proximo;
        nav->proximo = novo;
        return true;
    }else {
        novo->proximo = l.inicio;
        l.inicio = novo;
        return true;
    }
}

template<typename TIPO>
bool inserePosicao(Tlista<TIPO>& l, TIPO dado, int posicao) {
    TElemento<TIPO> *nav = l.inicio;
    TElemento<TIPO> *novo = novoElemento(dado);
    if(l.inicio != NULL || posicao != 0) {
        for(int i = 0; i<posicao - 1 && nav->proximo != NULL;i++) {
            nav = nav->proximo;
        }
        novo->proximo = nav->proximo;
        nav->proximo = novo;
        return true;
    }else {
        novo->proximo = l.inicio;
        l.inicio = novo;
        return true;
    }
}

template<typename TIPO>
bool removeInicio(Tlista<TIPO>& l){
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio == NULL) return false;
        l.inicio = nav->proximo;
        delete nav;
        return true;
}

template<typename TIPO>
bool removeFim(Tlista<TIPO>& l) {
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio == NULL) return false;
    if(l.inicio->proximo == NULL) {
        delete l.inicio;
        l.inicio = NULL;
        return true;
    }
    while(nav->proximo->proximo != NULL){
        nav = nav->proximo;
    }
    delete nav->proximo;
    nav->proximo = NULL;
    return true;

}

template<typename TIPO>
bool removePosicao(Tlista<TIPO>& l, int posicao){
    TElemento<TIPO> *nav = l.inicio;
    int i = 0;
    if(l.inicio == NULL) return false;
    while(i < posicao -1 && nav != NULL){
        nav = nav->proximo;
        i++;
    }
    TElemento<TIPO> *temp = nav->proximo;
    nav->proximo = nav->proximo->proximo;
    delete temp;
    return true;
}

template<typename TIPO>
void bubblesort(Tlista<TIPO> &l) {
    if(l.inicio != NULL){
        TIPO temp;
        TElemento<TIPO> *nav = l.inicio;
        TElemento<TIPO> *aux = nav->proximo;
        while(aux != NULL){
            if(aux->dado < nav->dado) {
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
TElemento<TIPO>* particao(TElemento<TIPO>*inicio, TElemento<TIPO>*fim, TElemento<TIPO>** novoInicio, TElemento<TIPO>**novoFim){
    TElemento<TIPO>*pivo = fim;
    TElemento<TIPO>*prev = NULL;
    TElemento<TIPO>*cur = inicio;
    TElemento<TIPO>*tail = pivo;

    while(cur != pivo) {
        if(cur->dado < pivo->dado){
            if(*novoInicio == NULL) {
                *novoInicio = cur;
            }
            prev = cur;
            cur = cur->proximo;
        }else {
            if(prev) {
                prev->proximo = cur->proximo;
            }
            TElemento<TIPO>* temp = cur->proximo;
            cur->proximo = NULL;
            tail->proximo = cur;
            tail = cur;
            cur = temp;
        }
    }

    if(*novoInicio == NULL) {
        *novoInicio = pivo;
    }
    *novoFim = tail;
    return pivo;

}

template<typename TIPO>
TElemento<TIPO>* quicksort(TElemento<TIPO>*inicio, TElemento<TIPO>*fim){
    if(!inicio || inicio == fim) {
        return inicio;
    }
    TElemento<TIPO>* novoInicio = NULL;
    TElemento<TIPO>* novoFim = NULL;
    TElemento<TIPO>* pivo = particao(inicio,fim,&novoInicio,&novoFim);

    if(novoInicio != pivo){
        TElemento<TIPO>* temp = novoInicio;
        while(temp->proximo!=pivo) temp = temp->proximo;
        temp->proximo = NULL;
        novoInicio = quicksort(novoInicio,temp);
        temp = getTail(novoInicio);
        temp->proximo = pivo;
    }
    pivo->proximo = quicksort(pivo->proximo, novoFim);
    return novoInicio;
}

template<typename TIPO>
void quicksortLista(Tlista<TIPO> &l){
    l.inicio = quicksort(l.inicio,getTail(l.inicio));
}

template <typename TIPO>
TElemento<TIPO>* getTail(TElemento<TIPO>* inicio) {
    TElemento<TIPO>* tmp = inicio;
    while (tmp && tmp->proximo) tmp = tmp->proximo;
    return tmp;
}
