
istream& operator>>(istream& entrada, const Vector&V){
    for(size_t i = 0; i < V.max; i++){
        entrada>>V.elementos[i];
    }

    return entrada;
}

ostream& operator <<(ostream& entrada, const Vector& V){
    entrada <<"[";
    for(size_t i=0; i < V.max; i++){
        entrada<<V.elementos[i];
        if(i < V.max - 1){
            entrada<<",";
        }
    }

    entrada<<"]";

    return entrada;
}