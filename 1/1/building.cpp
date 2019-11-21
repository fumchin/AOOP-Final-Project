#include "building.h"
#include "add1.h"
#include "longestpair.h"
#include <string>
#include <QTimer>
#include "shygame.h"
#include "fib.h"
using namespace std;
Building::Building()
{
    floor[0] = new Floor(new Add1());
    floor[1] = new Floor(new Prime());
    floor[2] = new Floor(new LongestPair());
    floor[3] = new Floor(new Shygame());
    floor[4] = new Floor(new Fib());
}
void Building::run(int question)
{
    //0.txt
    string s = judge.getData(question);
    data.testdata1 = s;

    string s2 = floor[question]->p->solve(s);

//    cout << s2;
    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();


}

