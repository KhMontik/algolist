@ ECHO OFF
copy postcard.%1.in postcard.in
run -t 2s a 
check postcard.in postcard.out >> res
