// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

#pragma warning(disable: 6011)    // 取消对空指针的引用
char comment[] = "-------------------------------------\nAutoNop Loader Complete!!!\n一个快捷键自动nop 的插件， 只支持 windows x86 系统， 因为 x64 很少看到有 花指令  \n-------------------------------------\n";


size_t idaapi init(void)
{
	//char message[10] = { "123" };
	qstring msg_buff[] = {0};
	acp_utf8(msg_buff, comment);
	msg(msg_buff->c_str());

	//warning("123");
	
	//IDA在启动的时候会调用每个插件的init函数。
	//返回值有三种选项:
	//PLUGIN_SKIP适合那些不支持的插件，IDA将不会加载该插件
	//PLUGIN_OK适合那些执行一次性功能的插件
	//PLUGIN_KEEP适合那些需要一直保持功能的插件
	return PLUGIN_KEEP;
}


void idaapi term(void)
{
	//当结束插件时，一般您可以在此添加一点任务清理的代码。
	return;
}

bool idaapi run(size_t)
{
	//当按下热键时候,执行功能的入口函数
	char msg_buff[255] = { 0 };
	ea_t cur_add = get_screen_ea();

	if (cur_add != 0xFFFFFFFF) {
		//qsnprintf(msg_buff, 255, "cur_select_address:%X", get_screen_ea());

		// 开始 patch
		patch_byte(cur_add, 0x90);
		msg("Patch NOP Sucess: %08X\n", get_screen_ea());
		// Patch 完成后， 跳转到下一个地址
		jumpto(cur_add + 1);


	}
	else {
		qstrncpy(msg_buff, (const char*)"未选中任何地址!!", 255);
		// 三行代码，让 ida plugin 弹出中文
		qstring *msg_buff1 = NULL;
		acp_utf8(msg_buff1, msg_buff);
		warning(msg_buff1->c_str());
	}

	return true;
}


plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  0,                    // 插件的一些属性,一般为0即可
  init,                 // initialize
  term,                 // terminate. this pointer may be NULL.
  run,                  // invoke plugin
  comment,              // 插件的说明,会显示在IDA下方的状态栏中
  "",                   // multiline help about the plugin
  "AutoNop",		// 插件在列表中显示的名称
  "Shift-P"              // 插件想要注册的功能快捷键
};
