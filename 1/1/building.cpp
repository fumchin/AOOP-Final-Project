#include "building.h"
#include "longestpair.h"
#include <string>
#include <QTimer>
#include "shygame.h"
#include "fib.h"
#include "findfactorial.h"
#include "shortestdistance.h"
using namespace std;
Building::Building()
{
//    floor[0] = new Floor(new Add1());
//    floor[1] = new Floor(new Prime());
    floor[0] = new Floor(new LongestPair());
    floor[1] = new Floor(new Shygame());
    floor[2] = new Floor(new Fib());
    floor[3] = new Floor(new FindFactorial());
    floor[4] = new Floor(new ShortestDistance());
}
void Building::run(int question)
{
    string s = judge.getData(question);
    data.testdata1 = s;
    string s2 = floor[question]->p->solve(s);

    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();
}

