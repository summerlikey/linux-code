# linux-code
ls -l file 详细信息
chmod 添加权限  
touch a.cpp 不加路径则在当前路径创建文件  
# cat 文件处理命令
cat -n a.cpp 行号显示，这命令只显示最后一页内容
tac -n a.cpp 倒着查看，相当于第一页内容
# cp
cp file1 file2 复制file1文件并命名为file2  
cp -r 复制目录 
cp -p 保持文件的属性，例如时间不变  


# more 分页显示内容
不可以向上翻页 空格翻页 回车换行 q退出  
/关键词，系统会标记关键词， n表示下一个关键词
# less 分页
可以向上翻
# head 查看前几行
head -n 2 a.cpp  制定前两行 默认前10行
# tail 查看后几行
tail -n 3 a.cpp  查看后3行 默认后十行，可以用来查看日志，最后几行
