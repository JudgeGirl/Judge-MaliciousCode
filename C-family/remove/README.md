## README ##

針對開放練習讀寫檔案的題目，容易發生測試腳本沒辦法正常運行，如我們加入數千個檔案名稱長度接起來超過 25 MB 時，一般的 shell 會無法正常運行 `rm -rf *`。