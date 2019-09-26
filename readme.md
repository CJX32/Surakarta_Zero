This is a beta version.
//编写日志
7.30 the beta version
编写图形界面

9.25
1、move_generator改用多线程
2、重新阅读web
3、测试并记录各个搜索方法的错误数

测试改变之前move_generator为10.2s

9.26
move_generator更改为多线程，但无实际变化，依然为10.2s
测试原生move_generator没有问题
测试
alpha_beta           error=41 time=15.5s
alpha_beta_PVS       error=41 time=16.5s
alpha_beta_Null_Move error=42 time=16.0s