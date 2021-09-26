# 第一个 ida 插件

AutoNop

> 自动将view-a 视图中选中的字节patch 成 0x90 , 即 nop , 其实应该叫 快速nop 的，当时没想这么多。

快捷键:  shift + p

# 获取 binary

https://github.com/m1n9yu3/AutoNop/releases/download/v1.0/autonop.dll

放在  ida/plugins/     
目录下

# 关于 ida sdk 获取

1. 直接 在我这个项目中下载  https://github.com/m1n9yu3/AutoNop/raw/master/IDASDK75.rar
2. 看雪论坛找一下

# 关于 ida 环境搭建

因为看到有人 fork 了这个project ,所以在这里补充下

1. c/c++ ->  常规 -> 附加包含目录   这里手动选择一下  sdk/inclde 目录
2. c/c++  -> 预处理器 -> 预处理定义   这里的话， 如果是 编译 ida64 所用的插件， 则要多添加一个__EA64__  ， 其他的话 __NT__ 这个
3. c/c++ 代码生成->禁用安全检查(/GS)
4. 链接器 -> 附加库目录 -> sdk/lib/x64_win_vc_xx     如果你要编译 ida64 使用的 插件 xx 就是 64,  反之就是 32
5. 链接器 -> 输入 -> 附加依赖项    添加 ida.lib

注意要使用 x64 平台， 
更详细的可以参考: https://m1n9yu3.github.io/2021/09/26/vs2019%E5%BC%80%E5%8F%91ida7-5%E6%8F%92%E4%BB%B6%E7%8E%AF%E5%A2%83%E6%90%AD%E5%BB%BA/
