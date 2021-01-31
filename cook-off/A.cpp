#include <iostream>
#include <string>
#include <vector>

template <class T>
std::vector<std::vector<T>> toeplitz(const std::vector<T> &t) {
    
    int n = (t.size() + 1) / 2;
    std::vector<std::vector<T>> toepl(n);

    for (int i=0; i<n; i++) {

        toepl[i].resize(n);
        for (int j=0; j<n; j++)
            toepl[i][j] = t[n - 1 - j + i];

    }

    return toepl;
}

template <class T>
std::vector<T> toepl_vector(const std::vector<std::vector<T>> &toepl) {

    int i, n = toepl.size();
    std::vector<T> t(2 * toepl.size() -1 );

    for (i=0; i<n; i++)
        t[i] = toepl[0][n - 1 - i];

    for (i=1; i<n; i++)
        t[i + n - 1] = toepl[n - 1][n - 1 - i];

    return t;

}

int main(void) {

    int i, j;
    std::vector<std::string> v(7);
    v[0] = "t0"; v[1] = "t1"; v[2] = "t2"; v[3] = "t3";
    v[4] = "t4"; v[5] = "t5"; v[6] = "t6";

    std::vector<std::vector<std::string>> tp = toeplitz(v);
    std::vector<std::string> t = toepl_vector(tp);

    for (i=0; i<4; i++) {

        std::cout << "[ ";

        for (j=0; j<4; j++)
            std::cout << tp[i][j] << " ";

        std::cout << "]" << std::endl;

    }

    std::cout << std::endl;

    for (i=0; i<7; i++)
        std::cout << "[ " << t[i] << " ]" << std::endl;

    return 0;

}

