g++ expr.cpp
del res.txt
for /l %%i in (1 1 8) do (

  copy expr.0%%i.in expr.in

  run -t 3s a.exe

  check expr.in expr.out >> res.txt

)

erase a.exe