#include "scheduler.h"

Scheduler::Scheduler()
{
//    int tempFloorArray[11] =  {1, 3, 4, 6, 9, 10, 8, 7, 5, 2, 0};
//    int tempFloorArray[11] =  {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0};
//    elevator algorithm
//    while
//    for (int i=0; i<11; i++)
//        nowFloor.push_back(tempFloorArray[i]);
    index = 0;


}

floorData Scheduler::getNowFloor()
{
    return FloorArray[index];
}

void Scheduler::getNewFloor(){
    index++;
}

//void Scheduler::findNext(const int arr[27][4],People **people){
//    if(nowFloor.size()==0){
//        f = new floorData;
//        f->now = 1;
//        f->des = people[0]->getPeopleDes();
//        f->inOut = 1;
//        f->peopleNum = (arr[0][0]>10)? 10:arr[0][0];
//        nowFloor.push_back(*f);
//    }
//    else{
//        f = new floorData;
//        if(nowFloor.back().inOut == 1){
//            f->inOut = 0;
//            f->now = nowFloor.back().des;
//            f->des = nowFloor.back().des;
//            f->peopleNum = nowFloor.back().peopleNum;
//            nowFloor.push_back(*f);
//        }
//        else if(nowFloor.back().inOut == 0){
//            f->inOut = 1;
//            f->now = nowFloor.back().des-1;
//            f->des = people[f->now]->getPeopleDes();
//            f->peopleNum = (arr[0][0]>10)? 10:arr[0][0];
//        }
//    }
//}


void Scheduler::findPath(People *people[]){
    const int elevator_max = 10;
    int elevatorpeople = 0;
    People **temp = people;
    //int **temp_arr = arr;

    //start from floor 1
    floorData *f = new floorData;
    f->now = 1;
    f->des = temp[f->now-1]->getPeopleDes();
    f->inOut = 1;
    f->peopleNum = (elevator_max >= temp[f->now-1]->getPeopleNum())? temp[f->now-1]->getPeopleNum():10;
    temp[f->now-1]->Number -= f->peopleNum;
    FloorArray.push_back(*f);

    while(1){
        floorData *f = new floorData;
        if(FloorArray.back().inOut == 1){    //last one in
            f->now = FloorArray.back().des;//last one's destination
            f->des = f->now;
            f->inOut = 0;
            f->peopleNum = FloorArray.back().peopleNum;
            FloorArray.push_back(*f);
        }
        else if(FloorArray.back().inOut == 0){  //last one out
            if(temp[FloorArray.back().des-1]->getPeopleNum()!=0){
                f->now = FloorArray.back().des;//last one's destination
                f->des = temp[f->now-1]->getPeopleDes();
                f->inOut = 1;
                f->peopleNum = (elevator_max >= temp[f->now-1]->getPeopleNum())? temp[f->now-1]->getPeopleNum():10;
                temp[f->now-1]->Number -= f->peopleNum;
                FloorArray.push_back(*f);
            }
            else{   //本層沒人
                for(int i=0;i<27;i++){
                    if(temp[i]->getPeopleNum()!=0){
                        f->now = i+1;
                        f->des = temp[f->now-1]->getPeopleDes();
                        f->inOut = 1;
                        f->peopleNum = (elevator_max >= temp[f->now-1]->getPeopleNum())? temp[f->now-1]->getPeopleNum():10;
                        temp[f->now-1]->Number -= f->peopleNum;
                        FloorArray.push_back(*f);
                        break;
                    }
                }
            }
        }

        //if 全部都沒人則break
        bool flag = false;
        for(int i=0;i<27;i++){
            if(temp[i]->getPeopleNum()>0){
                flag = true;
            }
        }
        if(flag == false && FloorArray.back().inOut==0){    //全部沒人&&最後一組已經out則結束(insert 0)
            floorData *f = new floorData;
            f->now = 0;
            FloorArray.push_back(*f);
            break;
        }
    }

    for(int i=0;i<(int)FloorArray.size();i++){
        cout<<FloorArray[i].now<<"\t"<<FloorArray[i].des<<"\t"<<FloorArray[i].inOut<<"\t"<<FloorArray[i].peopleNum<<endl;
    }
}

