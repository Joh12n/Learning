学习了touch的用法：用于更新文件的时间戳，若文件不存在，才会创建它
学习了使用fstatat()读取文件的stat表，也就是文件元数据快照。
当open()的文件不存在时，会根据flags是否为O_CREAT判断是否要创建该文件。
tv_sec可以通过localtime()转为结构体，并用strftime将该结构体转为字符串实现可读性。
