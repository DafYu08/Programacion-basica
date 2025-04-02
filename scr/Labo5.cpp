// Ejercicio 1
bool existePico(vector<int> v){
    bool res = false;
    for (int i = 1; i < v.size() - 1; ++i) {
        if (v[i-1] < v[i] && v[i+1] < v[i]){
            res = res || true;
        }
    }
	return res;
}

// Ejercicio 2
bool divide(int a, int b){
    return (a%b==0);
}
int mcd(int m, int n){
    int res = 1;
    if(m<=n){
        for (int i = m; i > 1 ; i--) {
            if (divide(m, i) && divide(n, i)) {
                res = i;
                i = 1;
            }
        }
    }
    if(m>n){
        for (int i = n; i > 1 ; i--) {
            if (divide(m, i) && divide(n, i)) {
                res = i;
                i = 1;
            }
        }
    }
	return res;
}

// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r){
    int minInd = v[l];
    for (int i = l; i < r; ++i) {
        if(v[i] < v[minInd]){
            minInd = i;
        }
    }
	return minInd;
}

void swap (int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
// Ejercicio 4
void ordenar1(vector<int>& v){
    int minIndice;
    for (int i = 0; i < v.size(); ++i) {
        minIndice = i;
        for (int j = i+1; j < v.size(); ++j) {
            if(v[i] > v[j]){
                minIndice = j;
                swap(v[i], v[minIndice]);
            }
        }
    }
	return;
}

// Ejercicio 5
void ordenar2(vector<int>& v){
    vector <int> vectorContador (3,0);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if(v[i] == j){
                vectorContador[j]++;
            }
        }
    }
	return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
    int q = 0, r = 0;
    while (n >= d){
        q++;
        n = n - d;
    }
    r = n%d;
	return make_tuple(q,r);
}
