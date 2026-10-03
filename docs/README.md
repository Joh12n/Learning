学习了touch的用法：用于更新文件的时间戳，若文件不存在，才会创建它
学习了使用fstatat()读取文件的stat表，也就是文件元数据快照。
当open()的文件不存在时，会根据flags是否为O_CREAT判断是否要创建该文件。
tv_sec可以通过localtime()转为结构体，并用strftime将该结构体转为字符串实现可读性。
学习了使用utimensat()修改文件的atim和mtim。

使用方法：
1、编译源码：gcc -Wall -Wextra -Wpedantic -g my_touch.c -o my_touch
2、使用指令：./my_touch [filename]
3、如果文件名不存在，会创建一个空文件，如果文件已在当前目录存在，则会修改该文件的mtim和atim。具体可以使用stat查看差异。
