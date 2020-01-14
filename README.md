
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
    a. 尚缺少 : 22,23,26 (floor : 23,24,27)  
    b. 測試有問題 : 2,25 (floor : 3(部分),26(全都跑不出來))，無法正確作答 
    c. time cost問題 : 20 (floor : 21)，time cost 太大，但解法正確
  (4) about checkbox  
    a. 打勾代表放棄執行該floor program，但電梯照常運行  
    b. 可以從judgeWindow.cpp 的 constructor 中更改要giveup的floor，也可將想測試的floor以外的floor program全部giveup以測試其中一題  
  (5)about result  
    a. 上傳的程式碼已完成 (judgeWindow.cpp)
  (6) 助教提供的judgeWindow已經在new_judgeWindow中了  
    a. 但測試還是原本的judgeWindow比較好用
    
2. MySQL  
  (1) mysql 目前使用的檔案 (dir: "C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/")    
    a. simple_initial_condition.csv  
    b. testdata_1225.csv  
    c. city_forFinal4.csv  
  (2) mysql 的密碼要自己重設 (main.cpp)  
    a. Line17, //database.setPassword("password"); //"nctuece" in lab  
  (3) 關於上傳 (judgeWindow.cpp)  
    a. 在construcror中更改姓名學號  
    b. 在on_export_to_database_clicked()
       更改上傳資訊 (hostname,password之類的)
       
3. 目前問題
  (1) 趕1/10 24:00前生出22題rrrr

