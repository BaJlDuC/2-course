@echo off

::Для запуска скрипта надо передать bat-файлу путь к тестируемой программе
::Одинаковые файлы Equal files
set PROGRAM = "dec2bin.exe"
set OUT = "out.txt"

::Invalid input
echo Invalid input
dec2bin.exe > "out.txt" || goto one
:one
fc "out.txt" "tests/out_invalid.txt" || goto err

::Uncorrect input
echo Uncorrect input pow(2, 31)
dec2bin.exe "2147483648" > "out.txt" || goto two
:two
fc "out.txt" "tests/out_uncorrect.txt" || goto err

::Correct input (2^31)-1
echo Correct input pow(2, 31) - 1
dec2bin.exe "2147483647" > "out.txt" || goto three
:three
fc "out.txt" "tests/out_big_correct.txt" || goto err

::Correct input 253
echo Correct input 253
dec2bin.exe "253" > "out.txt" || goto four
:four
fc "out.txt" "tests/out_successfull.txt" || goto err

::Correct input 0
echo Correct input 0
dec2bin.exe "0" > "out.txt" || goto five
:five
fc "out.txt" "tests/out_with_null.txt" || goto err

echo All tests passed
@pause
exit /B 0

:err
echo Program testing failed
@pause
exit /B 1