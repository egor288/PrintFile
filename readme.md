<h1>Утилита, выводящая файл в консоль</h1>

-l, --lines=n вывести только n (только положительное) первых(последних) строк файл (необязательный аргумент, по-умолчанию выводим все)

-t, --tail вывод n последний строк файла (необязательный аргумент)

-d, --delimiter=c символ по которому определяется конец строки (нeобязательный, по-умолчанию '\n')

Название файла и опции передаются через аргументы командной строки в следующем формате:

PrintFile.exe [OPTION] filename
Примеры запуска программы:

PrintFile.exe filename

PrintFile.exe filename

PrintFile.exe --tail --lines=10 filename

PrintFile.exe -l 2 filename

PrintFile.exe -d '\t' filename

PrintFile.exe filename -t -l 10