@echo off

::Для запуска скрипта надо передать bat-файлу путь к тестируемой программе
::Одинаковые файлы Equal files
echo Equal files
compare.exe "first.txt" "second.txt" > "out.txt" || goto fail
:fail
fc "out.txt" "tests/out_failed2.txt" || goto err

::Пустые файлы Empty files
echo Empty files
compare.exe "first_empty.txt" "second_empty.txt" > "out.txt" || goto err
fc "out.txt" "tests/out_succesfull.txt" || goto err

::Разные файлы, отличие начинается в 3 строке Different files, difference in 3 line
echo Different files
compare.exe "first_fail.txt" "second_fail.txt" > "out.txt" || goto different
:different
fc "out.txt" "tests/out_failed.txt"

::Неправильный ввод данных Invalid input
echo Invalid input
compare.exe "" > "out.txt" || goto inv
:inv
fc "out.txt" "tests/out_failed_invalid_in.txt" || goto err

::Некорректнный ввод имени файла1 Uncoorect file1 name
echo Uncorrect file1 name
compare.exe "first1.txt" "second1.txt" > "out.txt" || goto unc_one
:unc_one
fc "out.txt" "tests/out_uncorrect_file1.txt"

::Некорректнный ввод имени файла2 Uncoorect file2 name
echo Uncorrect file2 name
compare.exe "first.txt" "second1.txt" > "out.txt" || goto unc_two
:unc_two
fc "out.txt" "tests/out_uncorrect_file2.txt"

::first > second;
echo First big and second
compare.exe "first_big.txt" "second_small.txt" > "out.txt" || goto fs_one
:fs_one
fc "out.txt" "tests/out_failed2.txt"

::first < second
echo First and big second
compare.exe "first_small.txt" "second_big.txt" > "out.txt" || goto fs_two
:fs_two
fc "out.txt" "tests/out_failed2.txt"

::first_emtpy 2 lines vs second_empty
echo First empty vs second empty 2 lines
compare.exe "first_empty2.txt" "second_empty.txt" > "out.txt" || goto empt
:empt
fc "out.txt" "tests/out_failed2.txt"

echo All tests passed
@pause
exit /B 0

:err
echo Program testing failed
@pause
exit /B 1