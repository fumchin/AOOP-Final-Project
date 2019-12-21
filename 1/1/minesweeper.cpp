#include "minesweeper.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
Minesweeper::Minesweeper()
{

}

string Minesweeper::solve(string s)
{
    stringstream ss;
    ss<<s;
    int M,N;
    ss>>M>>N;
    vector<vector<char>> mineMap;
    for (int i=0; i<M; i++)
    {
        string row;
        ss>>row;
        vector<char> tempVec;
        for (int j=0; j<N; j++)
            tempVec.push_back(row[j]);
        mineMap.push_back(tempVec);
        tempVec.clear();
    }
    cout << M << " " << N << endl;
    for (int i=0; i!=mineMap.size(); i++)
    {
        for (int j=0; j!=mineMap[i].size(); j++)
            cout << mineMap[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    string result;
    for (int i=0; i!=mineMap.size(); i++)
    {
        for (int j=0; j!=mineMap[i].size(); j++)
        {
            if (mineMap[i][j]=='*')
            {
                cout << '*';
                result += "*";
            }
            else
            {
                int lowerI = i-1<0? 0:i-1;
                int higherI = i+1>M-1? M-1:i+1;
                int lowerJ = j-1<0? 0:j-1;
                int higherJ = j+1>N-1? N-1:j+1;
                //       lowerI
                //lowerJ        higherJ
                //       higerI
                int sum = 0;
                for (int k=lowerI; k<=higherI; k++)
                    for (int l=lowerJ; l<=higherJ; l++)
                        if (mineMap[k][l] == '*' && !(k==i&&l==j))
                            sum++;
                cout << sum;
                result += to_string(sum);
            }
        }
        cout << endl;
        result += " ";
    }

    result.erase(result.length()-1);

    return result;
}
