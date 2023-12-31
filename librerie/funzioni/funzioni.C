#include"funzioni.h"

float media_array_int (int valori[], int N) {
    int somma = 0 ;
    float res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (float)somma / N ;

    return res ; 
} 
float media_array_float (float valori[], int N) {
    float somma = 0 ;
    float res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (float)somma / N ;

    return res ; 
} 

double media_array_double (double valori[], int N) {
    double somma = 0 ;
    double res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (double)somma / N ;

    return res ; 
} 



float stnd_int (int valori[], int N, float m) {
    float sum_scarto = 0 ; 
    float res ;
    for (int i = 0; i < N; i++)
    {
     sum_scarto = pow(valori [i] - m,2) + sum_scarto ;
    }
    res = sqrt(sum_scarto / (-1)) ;
    return res ;
}

float stnd_float (float value [], int ndati, float media) {
    float dev ;
    float scarto = 0;
    float somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        scarto = ( value[i]-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }
    dev = sqrt (somma / (ndati-1));
    return dev;
}


double stnd_double (double value [], int ndati, double media) {
    double dev ;
    double scarto = 0;
    double somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        scarto = ( value[i]-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }
    dev = sqrt (somma / (ndati-1));
    return dev;
}


bool isOutlier (int valore, float m,float stnd) {

    float abs, c ; 
    abs = fabs(valore - m) ; 
    c = 3*stnd ;

    return abs > c ;

}

void scambia(int a[], int v1, int  v2) {
    int appoggio;
    appoggio = a[v1];
    a[v1] = a[v2];
    a[v2] = appoggio;
}

void scambia_float (float a[], int v1, int  v2) {
    int appoggio;
    appoggio = a[v1];
    a[v1] = a[v2];
    a[v2] = appoggio;
}

void print_array_int (int valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void print_array_float (float valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void print_array_double (double valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}


void print_array_char ( char valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void define_array (int voti[],int n) {
    for (int i = 0; i < n ; i++) {
        cout << endl << "inserisci qua il valore "<< i + 1 << ": "<< endl ;
        cin >> voti [i] ; 
        cout << endl;
    }    
}

int resto (int Num, int Den) {
    int q, r ;
    q =  Num/Den ; 
    r = Num - q*Den ;
    return r ; 

}

int MCD ( int p , int q) {
    int mcd, r ;
    do {
        r = resto (p,q) ;
        p = q ; 
        q = r ; 
    } while (q != 0) ; 
    return p ; 
} 



int posmin(int a[], int p, int j) {
    int s = a[p];
    int posmin = p;
    for (int i = p + 1; i < j; i++) {
        if (s > a[i]) {
            s = a[i];
            posmin = i;
        }
    }
    return posmin;
}


int posmin_float (float a[], int p, int j) {
    int s = a[p];
    int posmin = p;
    for (int i = p + 1; i < j; i++) {
        if (s > a[i]) {
            s = a[i];
            posmin = i;
        }
    }
    return posmin;
}


int deleteEntrySwap(int v[], int size, int used, int where) {
    for (int i = where; i < used; i++)
    {
      v [i] = v [i + 1] ;
    }
    used = used - 1 ;
    return used ; 
}

void ordcrescente(int a[], int n) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        p = posmin(a, i, n);
        scambia(a, i, p);
    }
}

void ordcrescente_float (float valori[], int n_elementi) {
 int p = 0;
    for (int i = 0; i < n_elementi; i++) {
        p = posmin_float(valori, i, n_elementi);
        scambia_float(valori, i, p);
    }
}


int conta_dati_file ( string directory ) {
    int i = 0 ;
    float appo ;
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        return -1 ;
    }
    
    data >> appo;
    
    while (!data.eof()) {
        i++ ;
        data >> appo ;
    }

    return i ;
}

int conta_coppiedati_file (string directory){
    float dato ;
    char colore ;
    int n_dati = 0 ;
   
    ifstream data ;

    data.open(directory) ;
    
    if (data.fail() ) {
        cout << "failed to read file" << endl ;
        return -1 ;
    } 
    
    data >> dato;
    data >> colore ;
    while (!data.eof()) {
        n_dati++ ;
        data >> dato ;
        data >> colore ;
    }
    data.close () ;
    return n_dati;

}

void define_array_file_float (float dati[] , int n_dati , string directory) {

    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati [k];
    }

    data.close () ;

}

void define_array_file_int (int dati[] , int n_dati , string directory) {

    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati [k];
    }

    data.close () ;

}




int posmax(int a[], int p, int j) {
    int s = a[p];
    int posmax = p;
    for (int i = p + 1; i < j; i++) {
        if (s < a[i]) {
            s = a[i];
            posmax = i;
        }
    }
    return posmax;
}


int posmax_float (float a[], int p, int j) {
    int s = a[p];
    int posmax = p;
    for (int i = p + 1; i < j; i++) {
        if (s < a[i]) {
            s = a[i];
            posmax = i;
        }
    }
    return posmax;
}


float mediana_float (float dati[], int n_dati) {
    float mediana; 
    if (n_dati % 2 == 0){
        mediana = (dati[n_dati/2]+dati[(n_dati/2)-1])/2 ;
    } else {
        mediana = dati[(n_dati-1)/2] ; 
    }
    return mediana ;
}


float mediana (int dati[], int n_dati) {
    float mediana; 
    if (n_dati % 2 == 0){
        mediana = (dati[n_dati/2]+dati[(n_dati/2)-1])/2 ; 
    } else {
        mediana = dati[(n_dati-1)/2] ;
    }
    return mediana ;
}

void calcolaStats (float dati [], int n_dati , float* pmin, float*pmax, float* pmediana, float* pmedia, float*pstddev) {
*pmin = dati[posmin_float(dati , 0 , n_dati)];
*pmax = dati[posmax_float(dati, 0 , n_dati)];
*pmediana = mediana_float (dati, n_dati);
*pmedia = media_array_float (dati, n_dati);
*pstddev = stnd_float (dati, n_dati, *pmedia);
}




void print_array_flie_int (int valori[], int n_dati,string directory) {
    ofstream file;
    file.open (directory) ; 
    if (file.fail() or file.fail()) {
        cout << "failed to read file" << endl ;
    } 

    for (int i = 0; i < n_dati; i++)
    {
        file << valori[i]<< endl;
    }
    file.close ();
    

}



bool is_perfect_square(int n) {
    bool value = false ; 
    float scarto = sqrtf(n)-(int)sqrtf(n);
    if (scarto == 0) {
        value = true; 
    }
    return value;
}


bool is_prime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}



int* carica_array_file_int (int& n_dati , string directory) {
    int* dati;
     
    
    n_dati = conta_dati_file (directory); 
   dati = new int [n_dati];
    ifstream data ;
    

    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        return NULL;
        n_dati = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati [k];
    }

    data.close () ;


    return dati; 
}

int conta_primi(int dati [], int n_dati ) {
    int n_primi = 0; 
    for (int i = 0; i < n_dati; i++)
        {
            if ( is_prime (dati [i])) {
                n_primi++ ;
            }
        }

        return n_primi; 
    }


    int*seleziona_primi (int dati[], int n_dati, int& n_primi) {
        int* primi;
        n_primi = conta_primi ( dati , n_dati );
        primi = new int [n_primi]; 
        int k= 0 ; 
        for (int i = 0; i < n_dati; i++)
        {
            if ( is_prime (dati [i])) {
                primi [k] = dati[i];  
                k++; 
            }
        }
        return primi; 
    }









