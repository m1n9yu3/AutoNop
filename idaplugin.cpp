// idaplugin.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "idaplugin.h"


// 这是导出变量的一个示例
IDAPLUGIN_API int nidaplugin=0;

// 这是导出函数的一个示例。
IDAPLUGIN_API int fnidaplugin(void)
{
    return 0;
}

// 这是已导出类的构造函数。
Cidaplugin::Cidaplugin()
{
    return;
}
