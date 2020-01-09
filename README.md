
1. 目前情況  
  (1) 電梯 : 已經完成，有時間再優化  
  (2) about testdata  
    a. 在某一層中有人或出，都要解題  
    b. 若此時有一個人進電梯，則以同一筆testdata執行十次並計算平均花費時間 (TotalCostTime/10)，  
    下一人進入或出去電梯時，則換下一筆testdata重複執行十次，  
    c. 分數 (score): 在執行正確的情況下是根據該testdata為該樓層的第幾筆testdata，以score = 10000000000+pow(2,第n筆testdata)，  
    並與其他人在本層樓進出解題正確所得的加權分數相加而成。   
    d. 時間 (TotalCost) : 同一筆testdata(同一人)重複執行十次的時間除10，並與其他人在本層樓進出解題所花的時間相加而成。  
  (3) about floor program (以question 為基準 -> question + 1 == floor)  
    a. 尚缺少 : 12,21,22,23,26 (floor : 13,22,23,24,27)  
    b. 測試有問題 : 2 (floor : 3)  
    c. 電腦問題 : 3,4,20 (floor : 4,5,21)，以不同testdata測試時是可行的，但換成正式的testdata到後面電腦會跑不動  
  (4)about checkbox  
    a. 打勾代表放棄執行該floor program，但電梯照常運行  
    b. 可以從judgeWindow.cpp 的 constructor 中更改要giveup的floor，也可將想測試的floor以外的floor program全部giveup以測試其中一題  
  (5)about result  
    a. 上傳到助教的program已經完成了(在本機上)，連線到助教那邊則還不確定  
    
2. MySQL  
  (1) mysql 目前使用的檔案 (dir: "C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/")    
    a. simple_initial_condition.csv  
    b. testdata_1225.csv  
    c. city_forFinal4.csv  
  (2) mysql 的密碼要自己重設 (main.cpp)  
    a. Line17, //database.setPassword("password"); //"nctuece" in lab  
3. 目前問題
  (1) 我的筆電跑不動嗚嗚嗚(尤其是到後面的測資floor3,4,21等等)

