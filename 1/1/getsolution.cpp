#include "getsolution.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
GetSolution::GetSolution()
{

}

string GetSolution::solve(string s)
{
    stringstream ss;
    ss << s;
    int N;
    ss>>N;
    vector<double> line(N+1,0);
    vector< vector<double> > A(N,line);

    // Read input data
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            ss >> A[i][j];

    for (int i=0; i<N; i++)
        ss >> A[i][N];
    return gauss(A);
}

string GetSolution::gauss(vector< vector<double> > A)
{
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    vector<double> x(n);
    ostringstream Strs;
    string result = "";

    for (int i=n-1; i>=0; i--)
    {
        x[i] = A[i][n]/A[i][i];
//            Strs << fixed << setprecision(2) << x[i] << " ";
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    for (int i=0; i<n; i++)
    {
        if (x[i] == -0)
            x[i] = 0;
        Strs << fixed << setprecision(2) << x[i] << " ";
    }
    result.append(Strs.str());
    result.erase(result.length()-1);
    return result;
}
