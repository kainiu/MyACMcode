gen > data.in
1 < data.in > my.out
2 < data.in > right.out
fc my.out right.out
if errorlevel==1 pause
%0