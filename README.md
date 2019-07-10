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

#while(cin>>word) 使用ctrl + D退出循环
#map 和 vector不同
map他是一个有序的且元素不重样的关联容器，他存放元素的方式是以键值对的方式存放的;  
vector容器没有特别的要求
#list vector deque map set 应用
list 适用于在任何位置添加删除元素，他是个双向的链表  
vector 适用在需要随机访问的程序，只能在末尾添加元素，在琪他位置添加或者删除效率会很低，代价过大  
deque 适用于在容器首尾添加删除元素且随机访问的程序； 
map 是键值对的集合，他能在查找的同事进行高效的访问； 
set 是关键字的简单集合，适用于当只想知道一个值是否存在时，是最有用的。   
# queue stack


